/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#ifndef LIB_LIB_H
#define LIB_LIB_H

#include "../kernel/kernel.h"

#define LIB_ENTER                                           void* __saved_process = __GLOBAL->process;\
                                                            __GLOBAL->process = (PROCESS*)__KERNEL; \
                                                            __KERNEL->error = ERROR_OK;

#define LIB_EXIT                                            __GLOBAL->process = __saved_process;

extern const void *const __LIB[];

void lib_stub ();

#endif // LIB_LIB_H
