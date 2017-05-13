/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#include "../rexos/userspace/stdio.h"
#include "../rexos/userspace/stdlib.h"
#include "../rexos/userspace/process.h"
#include "../rexos/userspace/sys.h"
#include "../rexos/userspace/stm32/stm32_driver.h"
#include "../rexos/userspace/ipc.h"
#include "../rexos/userspace/uart.h"
#include "../rexos/userspace/process.h"
#include "../rexos/userspace/power.h"
#include "../rexos/userspace/pin.h"
#include "../rexos/userspace/gpio.h"
#include "app_private.h"
#include "comm.h"
#include "config.h"

#include "cc11xx/cc1101.h"

void app();

const REX __APP = {
    //name
    "App main",
    //size
    512,
    //priority
    200,
    //flags
    PROCESS_FLAGS_ACTIVE | REX_FLAG_PERSISTENT_NAME,
    //function
    app
};


static inline void stat()
{
    SYSTIME uptime;
    int i;
    unsigned int diff;

    get_uptime(&uptime);
    for (i = 0; i < TEST_ROUNDS; ++i)
        svc_test();
    diff = systime_elapsed_us(&uptime);
    printf("average kernel call time: %d.%dus\n", diff / TEST_ROUNDS, (diff / (TEST_ROUNDS / 10)) % 10);

    get_uptime(&uptime);
    for (i = 0; i < TEST_ROUNDS; ++i)
        process_switch_test();
    diff = systime_elapsed_us(&uptime);
    printf("average switch time: %d.%dus\n", diff / TEST_ROUNDS, (diff / (TEST_ROUNDS / 10)) % 10);

    printf("core clock: %d\n", power_get_core_clock());
    process_info();
}

static inline void app_disable_JTAG()
{
    // Disable JTAG
    bool was_enabled = (RCC->APB2ENR & RCC_APB2ENR_AFIOEN);
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    uint32_t tmp = AFIO->MAPR;
    tmp &= ~AFIO_MAPR_SWJ_CFG;
    tmp |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
    AFIO->MAPR = tmp;
    if (!was_enabled) RCC->APB2ENR &= ~RCC_APB2ENR_AFIOEN;
}

static inline void app_setup_dbg()
{
    BAUD baudrate;
    pin_enable(DBG_CONSOLE_TX_PIN, STM32_GPIO_MODE_OUTPUT_AF_PUSH_PULL_50MHZ, false);
    uart_open(DBG_CONSOLE, UART_MODE_STREAM | UART_TX_STREAM);
    baudrate.baud = DBG_CONSOLE_BAUD;
    baudrate.data_bits = 8;
    baudrate.parity = 'N';
    baudrate.stop_bits= 1;
    uart_set_baudrate(DBG_CONSOLE, &baudrate);
    uart_setup_printk(DBG_CONSOLE);
    uart_setup_stdout(DBG_CONSOLE);
    open_stdout();
}

static inline void app_init(APP* app)
{
    process_create(&__STM32_CORE);

    app_disable_JTAG();

    gpio_enable_pin(C8, GPIO_MODE_OUT);
    gpio_set_pin(C8);

    app_setup_dbg();
//    printf("App init\n");
}

void app()
{
    APP app;
    CC1101 cc1101;
    IPC ipc;

    app_init(&app);

    cc1101_hw_init(&cc1101);

    for (;;)
    {
        ipc_read(&ipc);
        switch (HAL_GROUP(ipc.cmd))
        {
        default:
            error(ERROR_NOT_SUPPORTED);
            break;
        }
        ipc_write(&ipc);
    }
}
