/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#include "kernel.h"
#include "kernel_config.h"
#include "dbg.h"
#include "kirq.h"
#include "kipc.h"
#include "kstream.h"
#include "kprocess.h"
#include "kio.h"
#include "kobject.h"
#include "kstdlib.h"

#include "../userspace/error.h"
#include "../lib/lib_lib.h"
#include <string.h>

const char* const __KERNEL_NAME=                                                      "rexos 0.4.9";

void stdout_stub(const char *const buf, unsigned int size, void* param)
{
    //what can we debug in debug stub? :)
    kprocess_error_current(ERROR_STUB_CALLED);
}

void panic()
{
#if (KERNEL_DEBUG)
    printk("Kernel panic\n");
    dump(SRAM_BASE, 0x200);
#endif
#if (KERNEL_DEVELOPER_MODE)
    HALT();
#else
    fatal();
#endif //KERNEL_DEVELOPER_MODE
}

void svc(unsigned int num, unsigned int param1, unsigned int param2, unsigned int param3)
{
    switch (num)
    {
    //process related
    case SVC_PROCESS_CREATE:
        kprocess_create((REX*)param1, (KPROCESS**)param2);
        break;
    case SVC_PROCESS_GET_CURRENT:
        kprocess_get_current_svc((KPROCESS**)param1);
        break;
    case SVC_PROCESS_GET_FLAGS:
        kprocess_get_flags((KPROCESS*)param1, (unsigned int*)param2);
        break;
    case SVC_PROCESS_SET_FLAGS:
        kprocess_set_flags((KPROCESS*)param1, (unsigned int)param2);
        break;
    case SVC_PROCESS_GET_PRIORITY:
        kprocess_get_priority((KPROCESS*)param1, (unsigned int*)param2);
        break;
    case SVC_PROCESS_SET_PRIORITY:
        kprocess_set_priority((KPROCESS*)param1, (unsigned int)param2);
        break;
    case SVC_PROCESS_DESTROY:
        kprocess_destroy((KPROCESS*)param1);
        break;
    case SVC_PROCESS_SLEEP:
        kprocess_sleep(kprocess_get_current(), (SYSTIME*)param1, PROCESS_SYNC_TIMER_ONLY, NULL);
        break;
#if (KERNEL_PROFILING)
    case SVC_PROCESS_SWITCH_TEST:
        kprocess_switch_test();
        break;
    case SVC_PROCESS_INFO:
        kprocess_info();
        break;
#endif //KERNEL_PROFILING
    //irq related
    case SVC_IRQ_REGISTER:
        kirq_register((int)param1, (IRQ)param2, (void*)param3);
        break;
    case SVC_IRQ_UNREGISTER:
        kirq_unregister((int)param1);
        break;
    //system timer related
    case SVC_SYSTIME_HPET_TIMEOUT:
        ksystime_hpet_timeout();
        break;
    case SVC_SYSTIME_SECOND_PULSE:
        ksystime_second_pulse();
        break;
    case SVC_SYSTIME_GET_UPTIME:
        ksystime_get_uptime((SYSTIME*)param1);
        break;
    case SVC_SYSTIME_HPET_SETUP:
        ksystime_hpet_setup((CB_SVC_TIMER*)param1, (void*)param2);
        break;
    case SVC_SYSTIME_SOFT_TIMER_CREATE:
        ksystime_soft_timer_create((SOFT_TIMER**)param1, param2, (HAL)param3);
        break;
    case SVC_SYSTIME_SOFT_TIMER_START:
        ksystime_soft_timer_start((SOFT_TIMER*)param1, (SYSTIME*)param2);
        break;
    case SVC_SYSTIME_SOFT_TIMER_STOP:
        ksystime_soft_timer_stop((SOFT_TIMER*)param1);
        break;
    case SVC_SYSTIME_SOFT_TIMER_DESTROY:
        ksystime_soft_timer_destroy((SOFT_TIMER*)param1);
        break;
    //ipc related
    case SVC_IPC_POST:
        kipc_post((IPC*)param1);
        break;
    case SVC_IPC_WAIT:
        kipc_wait((KPROCESS*)param1, param2, param3);
        break;
    case SVC_IPC_CALL:
        kipc_call((IPC*)param1);
        break;
    //stream related
    case SVC_STREAM_CREATE:
        kstream_create((STREAM**)param1, param2);
        break;
    case SVC_STREAM_OPEN:
        kstream_open((STREAM*)param1, (STREAM_HANDLE**)param2);
        break;
    case SVC_STREAM_CLOSE:
        kstream_close((STREAM_HANDLE*)param1);
        break;
    case SVC_STREAM_GET_SIZE:
        kstream_get_size((STREAM*)param1, (unsigned int*)param2);
        break;
    case SVC_STREAM_GET_FREE:
        kstream_get_free((STREAM*)param1, (unsigned int*)param2);
        break;
    case SVC_STREAM_LISTEN:
        kstream_listen((STREAM*)param1, param2, (HAL)param3);
        break;
    case SVC_STREAM_STOP_LISTEN:
        kstream_stop_listen((STREAM*)param1);
        break;
    case SVC_STREAM_WRITE:
        kstream_write((STREAM_HANDLE*)param1, (char*)param2, param3);
        break;
    case SVC_STREAM_READ:
        kstream_read((STREAM_HANDLE*)param1, (char*)param2, param3);
        break;
    case SVC_STREAM_FLUSH:
        kstream_flush((STREAM*)param1);
        break;
    case SVC_STREAM_DESTROY:
        kstream_destroy((STREAM*)param1);
        break;
    case SVC_IO_CREATE:
        kio_create((IO**)param1, (unsigned int)param2);
        break;
    case SVC_IO_DESTROY:
        kio_destroy((IO*)param1);
        break;
    case SVC_OBJECT_SET:
        kobject_set(param1, (HANDLE)param2);
        break;
    case SVC_OBJECT_GET:
        kobject_get(param1, (HANDLE*)param2);
        break;
    //other - dbg, stdout/in
    case SVC_ADD_POOL:
        kstdlib_add_pool(param1, param2);
        break;
    case SVC_SETUP_DBG:
        if (__KERNEL->stdout != stdout_stub)
            kprocess_error_current(ERROR_INVALID_SVC);
        else
        {
            __KERNEL->stdout = (STDOUT)param1;
            __KERNEL->stdout_param = (void*)param2;
#if KERNEL_DEBUG
            printk("%s\n", __KERNEL_NAME);
#endif
        }
        break;
    case SVC_PRINTD:
        __KERNEL->stdout((const char*)param1, param2, __KERNEL->stdout_param);
        break;
#if (KERNEL_PROFILING)
    case SVC_TEST:
        //do nothing
        break;
#endif //KERNEL_PROFILING
    default:
        kprocess_error_current(ERROR_INVALID_SVC);
    }
}

void startup()
{
    //setup __GLOBAL
    __GLOBAL->svc_irq = svc;
    __GLOBAL->lib = (const void**)&__LIB;

    //setup __KERNEL
    memset(__KERNEL, 0, sizeof(KERNEL));
    __KERNEL->stdout = stdout_stub;

    //initialize irq subsystem
    kirq_init();

    //initialize main pool
    kstdlib_init();

    //initilize system time
    ksystime_init();

    //initialize kernel objects
    kobject_init();

    //initialize thread subsystem, create application task
    kprocess_init(&__APP);
}
