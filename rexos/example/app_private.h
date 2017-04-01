/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2017, Alexey Kramarenko
    All rights reserved.
*/

#ifndef APP_PRIVATE_H
#define APP_PRIVATE_H

#include "app.h"
#include "comm.h"
#include "net.h"
#include <stdint.h>

typedef struct _APP {
    COMM comm;
    NET net;
    HANDLE timer;
    HANDLE usbd;
} APP;

#endif // APP_PRIVATE_H
