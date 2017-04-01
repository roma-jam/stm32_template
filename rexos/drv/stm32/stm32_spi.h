/*
 * stm32_spi.h
 *
 *  Created on: 1 апр. 2017 г.
 *      Author: RomaJam
 */

#ifndef STM32_SPI_H
#define STM32_SPI_H

#include "stm32_core.h"
#include "../../userspace/io.h"
#include "../../userspace/i2c.h"
#include "../../userspace/process.h"
#include <stdbool.h>

typedef enum {
    I2C_IO_MODE_IDLE = 0,
    I2C_IO_MODE_TX,
    I2C_IO_MODE_RX
} SPI_IO_MODE;

typedef enum {
    I2C_STATE_ADDR = 0,
    I2C_STATE_LEN,
    I2C_STATE_DATA
} SPI_STATE;

typedef struct  {
    IO* io;
    HANDLE process;
    SPI_IO_MODE io_mode;
    SPI_STATE state;
    unsigned int size;
} SPI;

typedef struct  {
    SPI* spis[SPI_COUNT];
} SPI_DRV;

void stm32_spi_init(CORE* core);
void stm32_spi_request(CORE* core, IPC* ipc);


#endif /* STM32_SPI_H */
