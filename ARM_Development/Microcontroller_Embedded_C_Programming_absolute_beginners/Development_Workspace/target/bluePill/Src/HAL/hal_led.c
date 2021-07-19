/*
 * hal_led.c
 *
 *  Created on: Jan 19, 2021
 *      Author: abdelrhman
 */

#include "hal_led.h"

void led_init(void) {
	rcc_gpioPortClkEnable(GPIOA);
	gpioA_setPortConfLow(OUTPUT_PUSH_PULL);
}
void led_turnOn(led_e led) {
	gpioA_setPinState(led, HIGH);
}

void led_turnOff(led_e led) {
	gpioA_setPinState(led, LOW);
}

void led_toggle(led_e led) {
	gpioA_togglePinState(led);
}

uint8_t led_readValue(led_e led) {
	return gpioA_readOutputPinState(led);
}
