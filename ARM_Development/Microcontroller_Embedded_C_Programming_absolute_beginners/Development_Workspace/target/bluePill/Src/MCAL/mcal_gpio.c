/*
 * mcal_gpio.c
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */

#include "mcal_gpio.h"

static volatile _GPIOA *GPIOA = (volatile _GPIOA *) GPIO_BASE_ADDR;

void gpioA_setPinConf(uint8_t pinNo, pinMode mode, pinConf conf) {
	GPIOA->CRL.val &= ~(GPIO_CONFG_RESET << (pinNo << GPIO_CONFG_OFFSET));
	GPIOA->CRL.val |=  ((mode | conf) << (pinNo << GPIO_CONFG_OFFSET));
}

void gpioA_setPinState(uint8_t pinNo, pinState state) {
	switch(state) {
		case LOW :
			GPIOA->ODR.val &= ~(1 << pinNo);
			break;

		case HIGH :
			GPIOA->ODR.val |=  (1 << pinNo);
			break;

		default:
			printf("Unsupported pin state");
			break;
	}
}
