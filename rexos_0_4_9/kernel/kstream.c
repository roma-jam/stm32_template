/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#include "kstream.h"
#include "kernel.h"
#include "kstdlib.h"
#include "kipc.h"
#include "../userspace/error.h"
#include <string.h>

//push data to stream internally after read
static void kstream_push(STREAM* stream)
{
    STREAM_HANDLE* handle;
    int written = 0;
    while ((handle = stream->write_waiters) != NULL && !rb_is_full(&stream->rb))
    {
        for(; !rb_is_full(&stream->rb) && handle->size > 0; --handle->size)
        {
            stream->data[rb_put(&stream->rb)] = *handle->buf++;
            ++written;
        }
        //writed all from waiter? Wake him up.
        if (handle->size <= 0)
        {
            handle->mode = STREAM_MODE_IDLE;
            dlist_remove_head((DLIST**)&stream->write_waiters);
            kprocess_wakeup(handle->process);
        }
    }
}

static unsigned int kstream_get_size_internal(STREAM* stream)
{
    DLIST_ENUM de;
    STREAM_HANDLE* cur;
    unsigned int size;
    if (rb_is_full(&stream->rb))
    {
        size = stream->rb.size - 1;
        dlist_enum_start((DLIST**)&stream->write_waiters, &de);
        while (dlist_enum(&de, (DLIST**)&cur))
            size += cur->size;
    }
    else
        size = rb_size(&stream->rb);
    return size;
}

void kstream_lock_release(STREAM_HANDLE* handle, KPROCESS* process)
{
    CHECK_HANDLE(handle, sizeof(STREAM_HANDLE));
    CHECK_MAGIC(handle, MAGIC_STREAM_HANDLE);
    switch (handle->mode)
    {
    case STREAM_MODE_READ:
        dlist_remove((DLIST**)&(handle->stream->read_waiters), (DLIST*)handle);
        break;
    case STREAM_MODE_WRITE:
        dlist_remove((DLIST**)&(handle->stream->write_waiters), (DLIST*)handle);
        break;
    default:
        break;
    }
    handle->mode = STREAM_MODE_IDLE;
}

void kstream_create(STREAM** stream, unsigned int size)
{
    KPROCESS* process = kprocess_get_current();
    CHECK_ADDRESS(process, stream, sizeof(void*));
    disable_interrupts();
    *stream = kmalloc(sizeof(STREAM));
    enable_interrupts();
    if ((*stream) == NULL)
    {
        kprocess_error(process, ERROR_OUT_OF_SYSTEM_MEMORY);
        return;
    }
    //allocate stream data
    disable_interrupts();
    (*stream)->data = kmalloc(size);
    enable_interrupts();
    if ((*stream)->data == NULL)
    {
        disable_interrupts();
        kfree(*stream);
        enable_interrupts();
        (*stream) = NULL;
        kprocess_error(process, ERROR_OUT_OF_PAGED_MEMORY);
        return;
    }
    DO_MAGIC((*stream), MAGIC_STREAM);
    rb_init(&(*stream)->rb, size);
    (*stream)->listener = INVALID_HANDLE;
    (*stream)->write_waiters = (*stream)->read_waiters = NULL;
}

void kstream_open(STREAM* stream, STREAM_HANDLE** handle)
{
    KPROCESS* process = kprocess_get_current();
    if ((HANDLE)stream == INVALID_HANDLE)
    {
        *handle = (STREAM_HANDLE*)INVALID_HANDLE;
        return;
    }
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    CHECK_ADDRESS(process, handle, sizeof(void*));
    disable_interrupts();
    *handle = kmalloc(sizeof(STREAM_HANDLE));
    enable_interrupts();
    if (*handle != NULL)
    {
        DO_MAGIC((*handle), MAGIC_STREAM_HANDLE);
        (*handle)->process = process;
        (*handle)->stream = stream;
        (*handle)->mode = STREAM_MODE_IDLE;
    }
    else
        kprocess_error(process, ERROR_OUT_OF_SYSTEM_MEMORY);
}

void kstream_close(STREAM_HANDLE* handle)
{
    if ((HANDLE)handle == INVALID_HANDLE)
        return;
    CHECK_HANDLE(handle, sizeof(STREAM_HANDLE));
    CHECK_MAGIC(handle, MAGIC_STREAM_HANDLE);
    switch (handle->mode)
    {
    case STREAM_MODE_READ:
        dlist_remove((DLIST**)&(handle->stream->read_waiters), (DLIST*)handle);
        kprocess_wakeup(handle->process);
        kprocess_error(handle->process, ERROR_SYNC_OBJECT_DESTROYED);
        break;
    case STREAM_MODE_WRITE:
        dlist_remove((DLIST**)&(handle->stream->write_waiters), (DLIST*)handle);
        kprocess_wakeup(handle->process);
        kprocess_error(handle->process, ERROR_SYNC_OBJECT_DESTROYED);
        break;
    default:
        break;
    }
    disable_interrupts();
    kfree(handle);
    enable_interrupts();
}

void kstream_get_size(STREAM* stream, unsigned int *size)
{
    CHECK_ADDRESS(kprocess_get_current(), size, sizeof(unsigned int));
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    *size = kstream_get_size_internal(stream);
}

void kstream_get_free(STREAM *stream, unsigned int* size)
{
    DLIST_ENUM de;
    STREAM_HANDLE* cur;
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    CHECK_ADDRESS(kprocess_get_current(), size, sizeof(unsigned int));
    if (rb_is_empty(&stream->rb))
    {
        *size = stream->rb.size - 1;
        dlist_enum_start((DLIST**)&stream->read_waiters, &de);
        while (dlist_enum(&de, (DLIST**)&cur))
            *size += cur->size;
    }
    else
        *size = rb_free(&stream->rb);
}

void kstream_listen(STREAM* stream, unsigned int param, HAL hal)
{
    unsigned int size;
    IPC ipc;
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    KPROCESS* process = kprocess_get_current();
    size = kstream_get_size_internal(stream);
    if (stream->listener == INVALID_HANDLE)
    {
        if (size)
        {
            ipc.process = (HANDLE)process;
            ipc.cmd = HAL_CMD(hal, IPC_STREAM_WRITE);
            ipc.param1 = param;
            ipc.param2 = (HANDLE)stream;
            ipc.param3 = size;
            kipc_post_process(&ipc, (KPROCESS*)KERNEL_HANDLE);

        }
        else
        {
            stream->listener = (HANDLE)process;
            stream->listener_param = param;
            stream->listener_hal = hal;
        }
    }
    else
        kprocess_error(process, ERROR_ACCESS_DENIED);
}

void kstream_stop_listen(STREAM* stream)
{
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    KPROCESS* process = kprocess_get_current();
    if (stream->listener == (HANDLE)process)
        stream->listener = INVALID_HANDLE;
    else
        kprocess_error(process, ERROR_ACCESS_DENIED);
}

void kstream_write(STREAM_HANDLE *handle, char* buf, unsigned int size)
{
    IPC ipc;
    register STREAM_HANDLE* reader;
    KPROCESS* process = kprocess_get_current();
    int written = 0;
    CHECK_HANDLE(handle, sizeof(STREAM_HANDLE));
    CHECK_MAGIC(handle, MAGIC_STREAM_HANDLE);
    ASSERT(handle->mode == STREAM_MODE_IDLE);
    if ((HANDLE)handle->stream == INVALID_HANDLE)
    {
        kprocess_error(process, ERROR_SYNC_OBJECT_DESTROYED);
        return;
    }
    handle->size = size;
    //write directly to output
    while (handle->size && (reader = handle->stream->read_waiters) != NULL)
    {
        //all can go directly
        if (handle->size >= reader->size)
        {
            memcpy(reader->buf, buf, reader->size);
            handle->size -= reader->size;
            buf += reader->size;
            dlist_remove_head((DLIST**)&handle->stream->read_waiters);
            reader->mode = STREAM_MODE_IDLE;
            //wakeup reader
            kprocess_wakeup(reader->process);
        }
        else
        //part can go directly
        {
            memcpy(reader->buf, buf, handle->size);
            reader->buf += handle->size;
            reader->size -= handle->size;
            buf += handle->size;
            handle->size = 0;
        }
    }
    //write rest to stream
    for(; handle->size && !rb_is_full(&handle->stream->rb); --handle->size)
    {
        handle->stream->data[rb_put(&handle->stream->rb)] = *buf++;
        ++written;
    }
    //still more? wait
    if (handle->size)
    {
        handle->buf = buf;
        handle->mode = STREAM_MODE_WRITE;
        dlist_add_tail((DLIST**)&handle->stream->write_waiters, (DLIST*)handle);
        kprocess_sleep(process, NULL, PROCESS_SYNC_STREAM, handle);
    }
    //inform listener
    if ((handle->stream->listener != INVALID_HANDLE) && size)
    {
        ipc.process = handle->stream->listener;
        ipc.cmd = HAL_CMD(handle->stream->listener_hal, IPC_STREAM_WRITE);
        ipc.param1 = (unsigned int)handle->stream->listener_param;
        ipc.param2 = (HANDLE)handle->stream;
        ipc.param3 = kstream_get_size_internal(handle->stream);
        handle->stream->listener = INVALID_HANDLE;
        kipc_post_process(&ipc, (KPROCESS*)KERNEL_HANDLE);
    }
}

void kstream_read(STREAM_HANDLE* handle, char* buf, unsigned int size)
{
    register STREAM_HANDLE* writer;
    KPROCESS* process = kprocess_get_current();
    CHECK_HANDLE(handle, sizeof(STREAM_HANDLE));
    CHECK_MAGIC(handle, MAGIC_STREAM_HANDLE);
    CHECK_ADDRESS(process, buf, size);
    ASSERT(handle->mode == STREAM_MODE_IDLE);
    if ((HANDLE)handle->stream == INVALID_HANDLE)
    {
        kprocess_error(process, ERROR_SYNC_OBJECT_DESTROYED);
        return;
    }
    handle->size = size;
    //read from stream
    for(; handle->size && !rb_is_empty(&handle->stream->rb); --handle->size)
        *buf++ = handle->stream->data[rb_get(&handle->stream->rb)];
    //read directly from input
    while (handle->size && (writer = handle->stream->write_waiters) != NULL)
    {
        //all can go directly
        if (handle->size >= writer->size)
        {
            memcpy(buf, writer->buf, writer->size);
            handle->size -= writer->size;
            buf += writer->size;
            //wakeup writer
            writer->mode = STREAM_MODE_IDLE;
            dlist_remove_head((DLIST**)&handle->stream->write_waiters);
            kprocess_wakeup(writer->process);
        }
        else
        //part can go directly
        {
            memcpy(buf, writer->buf, handle->size);
            writer->size -= handle->size;
            writer->buf += handle->size;
            buf += handle->size;
            handle->size = 0;
        }
    }
    //still need more? Wait.
    if (handle->size)
    {
        handle->buf = buf;
        handle->mode = STREAM_MODE_READ;
        dlist_add_tail((DLIST**)&handle->stream->read_waiters, (DLIST*)handle);
        kprocess_sleep(process, NULL, PROCESS_SYNC_STREAM, handle);
    }
    else
        kstream_push(handle->stream);
}

void kstream_flush(STREAM* stream)
{
    CHECK_HANDLE(stream, sizeof(STREAM));
    STREAM_HANDLE* handle;
    CHECK_MAGIC(stream, MAGIC_STREAM);
    //flush stream
    rb_clear(&stream->rb);
    stream->listener = INVALID_HANDLE;
    //flush waiters
    while ((handle = stream->write_waiters) != NULL)
    {
        handle->mode = STREAM_MODE_IDLE;
        dlist_remove_head((DLIST**)&stream->write_waiters);
        kprocess_wakeup(handle->process);
    }
}

static void kstream_destroy_handle(STREAM* stream, DLIST** head)
{
    STREAM_HANDLE* handle;
    while (stream->write_waiters)
    {
        handle = (STREAM_HANDLE*)(*head);
        CHECK_MAGIC(handle, MAGIC_STREAM_HANDLE);
        handle->stream = (STREAM*)INVALID_HANDLE;
        dlist_remove_head(head);
        kprocess_wakeup(handle->process);
        kprocess_error(handle->process, ERROR_SYNC_OBJECT_DESTROYED);
    }
}

void kstream_destroy(STREAM* stream)
{
    if ((HANDLE)stream == INVALID_HANDLE)
        return;
    CHECK_HANDLE(stream, sizeof(STREAM));
    CHECK_MAGIC(stream, MAGIC_STREAM);
    CLEAR_MAGIC(stream);
    kstream_destroy_handle(stream, (DLIST**)&stream->write_waiters);
    kstream_destroy_handle(stream, (DLIST**)&stream->read_waiters);
    disable_interrupts();
    kfree(stream->data);
    kfree(stream);
    enable_interrupts();
}
