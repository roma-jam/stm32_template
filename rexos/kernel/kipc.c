/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#include "dbg.h"
#include "kipc.h"
#include "kio.h"
#include "kprocess.h"
#include "../userspace/error.h"
#include "../userspace/rb.h"
#include "kernel.h"

#define KIPC_ITEM(kprocess, num)              ((IPC*)((unsigned int)(kprocess->process) + sizeof(PROCESS) + (num) * sizeof(IPC)))

void kipc_lock_release(KPROCESS* kprocess)
{
    kprocess->kipc.wait_process = (KPROCESS*)INVALID_HANDLE;
}

static inline int kipc_index(KPROCESS* kprocess, HANDLE wait_process, unsigned int cmd, unsigned int param1)
{
    int i;
    unsigned int head = kprocess->process->ipcs.head;
    for (i = kprocess->process->ipcs.tail; i != head; i = RB_ROUND(&kprocess->process->ipcs, i + 1))
        if (((KIPC_ITEM(kprocess, i)->process == wait_process) || (wait_process == ANY_HANDLE)) && ((KIPC_ITEM(kprocess, i)->cmd == cmd) || (cmd == ANY_CMD)) &&
                ((KIPC_ITEM(kprocess, i)->param1 == param1) || (param1 == ANY_HANDLE)))
            return i;
    return -1;
}

static void kipc_wait_process(KPROCESS *kprocess, KPROCESS* wait_process, unsigned int cmd, unsigned int param1)
{
    int index;
    if (wait_process == kprocess)
    {
        kprocess_error(kprocess, ERROR_DEADLOCK);
#if (KERNEL_IPC_DEBUG)
        printk("IPC deadlock: %s\n", kprocess_name(kprocess));
#endif //KERNEL_IPC_DEBUG
        return;
    }
    kprocess_sleep(kprocess, NULL, PROCESS_SYNC_IPC, kprocess);

    disable_interrupts();
    if ((index = kipc_index(kprocess, (HANDLE)wait_process, cmd, param1)) < 0)
    {
        kprocess->kipc.wait_process = wait_process;
        kprocess->kipc.cmd = cmd;
        kprocess->kipc.param1 = param1;
    }
    enable_interrupts();

    //maybe already on queue? Wakeup process
    if (index >= 0)
        kprocess_wakeup(kprocess);
}

void kipc_post_process(IPC* ipc, KPROCESS* sender)
{
    KPROCESS* receiver = (KPROCESS*)ipc->process;
    int index = -1;
    bool wake = false;
    IPC* cur;
    CHECK_HANDLE(receiver, sizeof(KPROCESS));
    CHECK_MAGIC(receiver, MAGIC_PROCESS);
    if (ipc->cmd & HAL_IO_FLAG)
    {
        KIO* kio = (KIO*)(((IO*)ipc->param2)->kio);
        CHECK_HANDLE(kio, sizeof(KIO));
        CHECK_MAGIC(kio, MAGIC_KIO);
        if (!kio_send(kio, receiver))
            return;
    }
    disable_interrupts();
    if ((wake = ((receiver->kipc.wait_process == sender || receiver->kipc.wait_process == (KPROCESS*)ANY_HANDLE) &&
                 (receiver->kipc.cmd == ipc->cmd || receiver->kipc.cmd == ANY_CMD) &&
                 ((receiver->kipc.param1 == ipc->param1) || (receiver->kipc.param1 == ANY_HANDLE)))) == true)
    {
        receiver->kipc.wait_process = (KPROCESS*)INVALID_HANDLE;
    }
    if (!rb_is_full(&receiver->process->ipcs))
        index = rb_put(&receiver->process->ipcs);
    enable_interrupts();
    if (index >= 0)
    {
        cur = KIPC_ITEM(receiver, index);
        cur->cmd = ipc->cmd;
        cur->param1 = ipc->param1;
        cur->param2 = ipc->param2;
        cur->param3 = ipc->param3;
        cur->process = (HANDLE)sender;
        //already waiting? Wakeup him
        if (wake)
            kprocess_wakeup(receiver);
    }
    else
    {
        kprocess_error(sender, ERROR_OVERFLOW);
#if (KERNEL_IPC_DEBUG)
        printk("Error: receiver %s IPC overflow!\n", kprocess_name(receiver));
        if (sender == (KPROCESS*)KERNEL_HANDLE)
            printk("Sender: kernel\n");
        else
            printk("Sender: %s\n", kprocess_name((KPROCESS*)sender));
        printk("cmd: %#X, p1: %#X, p2: %#X, p3: %#X\n", ipc->cmd, ipc->param1, ipc->param2, ipc->param3);
#if (KERNEL_DEVELOPER_MODE)
        HALT();
#endif
#endif
    }
}

void kipc_init(KPROCESS *kprocess)
{
    rb_init(&(kprocess->process->ipcs), KERNEL_IPC_COUNT);
    kprocess->kipc.wait_process = (KPROCESS*)INVALID_HANDLE;
    kprocess->kipc.cmd = ANY_CMD;
}

void kipc_post(IPC* ipc)
{
    KPROCESS* kprocess = kprocess_get_current();
    CHECK_ADDRESS(kprocess, ipc, sizeof(IPC));
    kipc_post_process(ipc, kprocess);
}

void kipc_wait(KPROCESS* wait_process, unsigned int cmd, unsigned int param1)
{
    KPROCESS* kprocess = kprocess_get_current();
    kipc_wait_process(kprocess, wait_process, cmd, param1);
}

void kipc_call(IPC* ipc)
{
    KPROCESS* kprocess = kprocess_get_current();
    CHECK_ADDRESS(kprocess, ipc, sizeof(IPC));
    kipc_post_process(ipc, kprocess);
    kipc_wait_process(kprocess, (KPROCESS*)(ipc->process), ipc->cmd & ~HAL_REQ_FLAG, ipc->param1);
}
