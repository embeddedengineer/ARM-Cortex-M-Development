/*
 * hal_switch.c
 *
 *  Created on: Jan 23, 2021
 *      Author: abdelrhman
 */

#include "hal_switch.h"

void sw_init(void) {
	rcc_gpioPortClkEnable(GPIOA);
	gpioA_setPortConfHigh(INPUT_PULL_UP_DOWN);
}

uint8_t sw_readValue(switch_e sw) {
	return gpioA_readInputPinState(sw);
}
