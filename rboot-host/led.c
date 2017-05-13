/*
 * led.c
 *
 *  Created on: 13 мая 2017 г.
 *      Author: RomaJam
 */

#include "app_private.h"
#include "../rexos/userspace/stm32/stm32_driver.h"
#include "../rexos/userspace/gpio.h"
#include "../rexos/userspace/stdio.h"
#include "led.h"


void led_init(APP* app)
{
    gpio_enable_pin(LED_WHITE_PIN, GPIO_MODE_OUT);
    gpio_enable_pin(LED_BLUE_PIN, GPIO_MODE_OUT);

    gpio_set_pin(LED_WHITE_PIN);

#if (APP_LED_DEBUG)
    printf("LED: init");
#endif // APP_LED_DEBUG
}

void led_mode(APP* app, LED led, LED_MODE mode)
{
#if (APP_LED_DEBUG)
    printf("LED: mode");
#endif // APP_LED_DEBUG
}
