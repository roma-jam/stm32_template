/*
 * cc1101_config.h
 *
 *  Created on: 2 апр. 2017 г.
 *      Author: RomaJam
 */

#ifndef CC1101_CONFIG_H
#define CC1101_CONFIG_H

#include "config.h"
#include "../rexos/userspace/stm32/stm32_driver.h"

#define CC1101_SPI                              SPI_1

#define CC1101_CS_PIN                           A4
#define CC1101_CLK_PIN                          A5
#define CC1101_MISO_PIN                         A6
#define CC1101_MOSI_PIN                         A7

#define CC1101_IO_SIZE                          64

#define CC1101_DEBUG                            1
#define CC1101_DEBUG_INFO                       1
#define CC1101_DEBUG_ERRORS                     1
#define CC1101_DEBUG_FLOW                       1



#endif /* CC1101_CONFIG_H */
