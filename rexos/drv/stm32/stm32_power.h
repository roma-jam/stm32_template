/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#ifndef STM32_POWER_H
#define STM32_POWER_H

#include "stm32_core.h"
#include "../../userspace/stm32/stm32_driver.h"
#include "../../userspace/power.h"

typedef struct {
#if (STM32_DECODE_RESET)
    RESET_REASON reset_reason;
#endif //STM32_DECODE_RESET
}POWER_DRV;

void stm32_power_init(CORE* core);
void stm32_power_request(CORE* core, IPC* ipc);

__STATIC_INLINE unsigned int stm32_power_get_clock_inside(CORE* core, STM32_POWER_CLOCKS type)
{
    IPC ipc;
    ipc.cmd = HAL_REQ(HAL_POWER, POWER_GET_CLOCK);
    ipc.param1 = (unsigned int)type;
    stm32_power_request(core, &ipc);
    return ipc.param2;
}

#endif // STM32_POWER_H
