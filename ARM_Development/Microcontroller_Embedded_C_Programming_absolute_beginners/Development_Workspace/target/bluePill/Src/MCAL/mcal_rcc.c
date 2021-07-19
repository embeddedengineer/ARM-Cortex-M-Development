/*
 * hal_rcc.c
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */


#include "mcal_rcc.h"

static RCC_t volatile *RCC = (RCC_t volatile*) RCC_BASE_ADDR;

void rcc_gpioPortClkEnable(gpioPort_e gpioPort) {
	RCC->APB2ENR.val |= (1 << gpioPort);
}
