/*
 * hal_led.h
 *
 *  Created on: Jan 19, 2021
 *      Author: abdelrhman
 */

#ifndef HAL_LED_H_
#define HAL_LED_H_

#include "../MCAL/mcal_gpio.h"
#include "../MCAL/mcal_rcc.h"

#define OUTPUT_PUSH_PULL (0x11111111)

typedef enum {
	LED1 = 0,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7
}led_e;

extern void led_init(void);
extern void led_turnOn(led_e);
extern void led_turnOff(led_e);
extern void led_toggle(led_e);
extern uint8_t led_readValue(led_e);
#endif /* HAL_LED_H_ */
