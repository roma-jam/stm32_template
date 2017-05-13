/*
    RExOS - embedded RTOS
    Copyright (c) 2011-2016, Alexey Kramarenko
    All rights reserved.
*/

#ifndef CONFIG_H
#define CONFIG_H

#define USB_PORT_NUM                                USB_0
#define USBD_PROCESS_SIZE                           1200
#define USBD_PROCESS_PRIORITY                       150

#define ETH_PHY_ADDRESS                             0x1f
#define ETH_MDC                                     C1
#define ETH_MDIO                                    A2
#define ETH_TX_CLK                                  C3
#define ETH_TX_EN                                   B11
#define ETH_TX_D0                                   B12
#define ETH_TX_D1                                   B13
#define ETH_TX_D2                                   C2
#define ETH_TX_D3                                   B8

#define ETH_RX_CLK                                  A1
#define ETH_RX_ER                                   B10

#define ETH_RX_DV                                   A7
#define ETH_RX_D0                                   C4
#define ETH_RX_D1                                   C5
#define ETH_RX_D2                                   B0
#define ETH_RX_D3                                   B1

#define ETH_PPS_OUT                                 B5
#define ETH_COL                                     A3
#define ETH_CRS_WKUP                                A0

#define TCPIP_PROCESS_SIZE                          1200
#define TCPIP_PROCESS_PRIORITY                      149

#define DBG_CONSOLE                                 UART_1
#define DBG_CONSOLE_TX_PIN                          A9
#define DBG_CONSOLE_BAUD                            115200

#define TEST_ROUNDS                                 10000


#define APP_DEBUG                                   1

#if (APP_DEBUG)
#define APP_COMM_DEBUG                              1

#endif //  APP_DEBUG






#endif // CONFIG_H
