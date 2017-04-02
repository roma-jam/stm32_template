/*
 * cc1101.c
 *
 *  Created on: 2 апр. 2017 г.
 *      Author: RomaJam
 */

#include <cc11xx/cc1101.h>
#include "../rexos/userspace/stdio.h"
#include "../rexos/userspace/stdlib.h"
#include "../rexos/userspace/process.h"
#include "../rexos/userspace/spi.h"
#include "../rexos/userspace/pin.h"
#include "../rexos/userspace/gpio.h"
#include "../rexos/userspace/systime.h"
#include "app_private.h"

static inline void cc1101_cs_lo()
{
    gpio_reset_pin(CC1101_CS_PIN);
}

static inline void cc1101_cs_hi()
{
    gpio_set_pin(CC1101_CS_PIN);
}

static inline bool cc1101_busy()
{
    return gpio_get_pin(CC1101_MISO_PIN);
}

static inline bool cc1101_write_register(CC1101* cc1101, uint8_t addr, uint8_t data)
{
    CC1101_REG* rg = (CC1101_REG*)io_data(cc1101->io);
    cc1101_cs_lo();
    while(cc1101_busy());
    rg->addr = addr;
    rg->data = data;
    cc1101->io->data_size = sizeof(CC1101_REG);
    if(sizeof(CC1101_REG) != spi_data(CC1101_SPI, cc1101->io, CC1101_IO_SIZE))
    {
#if (CC1101_DEBUG_ERRORS)
        printf("CC1101:write register error\n");
#endif // CC1101_DEBUG_ERRORS
        cc1101_cs_hi();
        return false;
    }
    cc1101_cs_hi();
    return true;
}

static inline uint8_t cc1101_read_register(CC1101* cc1101, uint8_t addr)
{
    return 0;
}

static inline void cc1101_write_strobe(CC1101* cc1101, uint8_t strobe)
{

}

static inline void cc1101_prepare_tx(CC1101* cc1101, IO* io)
{

}

static inline void cc1101_chip_reset(CC1101* cc1101)
{

}

static inline void cc1101_start_tx(CC1101* cc1101)
{

}

static inline void cc1101_start_rx(CC1101* cc1101)
{

}

static inline void cc1101_flush_tx_fifo(CC1101* cc1101)
{

}

static inline void cc1101_flush_rx_fifo(CC1101* cc1101)
{

}

static inline void cc1101_get_state(CC1101* cc1101)
{

}



void cc1101_hw_init(CC1101* cc1101)
{
#if (CC1101_DEBUG_INFO)
    printf("CC1101: init\n");
#endif // CC1101_DEBUG_INFO
    cc1101->active = false;

    gpio_enable_pin(CC1101_CS_PIN, GPIO_MODE_OUT);
    pin_enable(CC1101_CLK_PIN, STM32_GPIO_MODE_OUTPUT_AF_PUSH_PULL_50MHZ, false);
    pin_enable(CC1101_MISO_PIN, STM32_GPIO_MODE_OUTPUT_AF_PUSH_PULL_50MHZ, false);
    pin_enable(CC1101_MOSI_PIN, STM32_GPIO_MODE_OUTPUT_AF_PUSH_PULL_50MHZ, false);

    cc1101_cs_hi();

    if(!spi_open(CC1101_SPI, SPI_MODE_MASTER | SPI_DATA_CK_IDLE_HIGH | SPI_DATA_SECOND_EDGE | SPI_BAUDRATE_DIV4))
    {
#if (CC1101_DEBUG_ERRORS)
    printf("CC1101: spi open failure\n");
#endif // CC1101_DEBUG_ERRORS
        return;
    }

    cc1101->io = io_create(CC1101_IO_SIZE);
    if(cc1101->io == NULL)
    {
#if (CC1101_DEBUG_ERRORS)
        printf("CC1101: io failure\n");
#endif // CC1101_DEBUG_ERRORS
        return;
    }
    cc1101->active = true;
}


void cc1101_hw_deinit(CC1101* cc1101)
{
#if (CC1101_DEBUG_INFO)
    printf("CC1101: deinit\n");
#endif // CC1101_DEBUG_INFO
    cc1101->active = false;

    spi_close(CC1101_SPI);

    pin_disable(CC1101_CS_PIN);
    pin_disable(CC1101_CLK_PIN);
    pin_disable(CC1101_MISO_PIN);
    pin_disable(CC1101_MOSI_PIN);

    io_destroy(cc1101->io);
}


void cc1101_set_channel(CC1101* cc1101, uint8_t channel_num)
{
#if (CC1101_DEBUG_INFO)
    printf("CC1101: set channel\n");
#endif // CC1101_DEBUG_INFO
}

void cc1101_set_tx_power(CC1101* cc1101, uint8_t power)
{
#if (CC1101_DEBUG_INFO)
    printf("CC1101: set tx power\n");
#endif // CC1101_DEBUG_INFO
}

void cc1101_set_radio_pkt_size(CC1101* cc1101, uint8_t size)
{
#if (CC1101_DEBUG_INFO)
    printf("CC1101: set pkt size\n");
#endif // CC1101_DEBUG_INFO
}
