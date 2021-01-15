/*
 * hal_rcc.c
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */


#include "mcal_rcc.h"

static volatile _RCC *RCC = (volatile _RCC *) RCC_BASE_ADDR;

void rcc_gpioPortClkEnable(gpioPort port) {
	RCC->APB2ENR.val |= (1 << port);
}
