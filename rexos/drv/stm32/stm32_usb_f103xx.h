/*
 * stm32_usb_f103xx.h
 *
 *  Created on: 11 но€б. 2016 г.
 *      Author: RLeonov
 */

#ifndef STM32_STM32_USB_F103XX_H
#define STM32_STM32_USB_F103XX_H

#include "../../userspace/process.h"
#include "../../userspace/ipc.h"
#include "../../userspace/io.h"
#include "stm32_config.h"
#include "stm32_core.h"
#include "sys_config.h"

typedef struct {
    IO* io;
    unsigned int size;
    uint16_t mps;
    uint8_t io_active;
} EP;

typedef struct {
  HANDLE device;
  EP* out[USB_EP_COUNT_MAX];
  EP* in[USB_EP_COUNT_MAX];
  uint8_t addr;
} USB_DRV;

void stm32_usb_init(CORE* core);
void stm32_usb_request(CORE* core, IPC* ipc);

#endif /* STM32_STM32_USB_F103XX */
