/*
 * led.h
 *
 *  Created on: 13 мая 2017 г.
 *      Author: RomaJam
 */

#ifndef LED_H_
#define LED_H_

#include "app.h"
#include "config.h"

typedef enum {
    LED_MODE_OFF = 0,
    LED_MODE_ON,
    LED_MODE_BLINK
} LED_MODE;

typedef enum {
    LED_WHITE = 0,
    LED_BLUE,
    LED_MAX
} LED;

void led_init(APP* app);
void led_mode(APP* app, LED led, LED_MODE mode);


#endif /* LED_H_ */
