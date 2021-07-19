/*
 * mcal_gpio.c
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */

#include "mcal_gpio.h"

static GPIO_t volatile *GPIOA = (GPIO_t volatile*) GPIOA_BASE_ADDR;
static GPIO_t volatile *GPIOB = (GPIO_t volatile*) GPIOB_BASE_ADDR;

// GPIOA APIs
void gpioA_setPinConf(uint8_t pinNo, pinMode_e pinMode, pinConf_e pinConf) {
	GPIOA->CRL.val &= ~(GPIO_CONFG_RESET << (pinNo << GPIO_CONFG_OFFSET));
	GPIOA->CRL.val |=  ((pinMode | pinConf) << (pinNo << GPIO_CONFG_OFFSET));
}

void gpioA_setPinConfHigh(uint8_t pinNo, pinMode_e pinMode, pinConf_e pinConf) {
	GPIOA->CRH.val &= ~(GPIO_CONFG_RESET << (pinNo << GPIO_CONFG_OFFSET));
	GPIOA->CRH.val |=  ((pinMode | pinConf) << (pinNo << GPIO_CONFG_OFFSET));
}

void gpioA_setPinState(uint8_t pinNo, pinState_e pinState) {
	switch(pinState) {
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

uint8_t gpioA_readInputPinState(uint8_t pinNo) {
	return ((GPIOA->IDR.val >> pinNo) & 0x01);
}

uint8_t gpioA_readOutputPinState(uint8_t pinNo) {
	return ((GPIOA->ODR.val >> pinNo) & 0x01);
}

void gpioA_setPortConfLow(uint32_t value) {
	GPIOA->CRL.val = value;
}

void gpioA_setPortConfHigh(uint32_t value) {
	GPIOA->CRH.val = value;
}

void gpioA_togglePinState(uint8_t pinNo) {
	GPIOA->ODR.val ^= (1 << pinNo);
}

void gpioA_setPortState(uint32_t value) {
	GPIOA->ODR.val = value;
}

uint32_t gpioA_getPortState(void) {
	return GPIOA->ODR.val;
}

// GPIOB APIs
void gpioB_setPinConf(uint8_t pinNo, pinMode_e pinMode, pinConf_e pinConf) {
	GPIOB->CRL.val &= ~(GPIO_CONFG_RESET << (pinNo << GPIO_CONFG_OFFSET));
	GPIOB->CRL.val |=  ((pinMode | pinConf) << (pinNo << GPIO_CONFG_OFFSET));
}

void gpioB_setPinConfHigh(uint8_t pinNo, pinMode_e pinMode, pinConf_e pinConf) {
	GPIOB->CRH.val &= ~(GPIO_CONFG_RESET << (pinNo << GPIO_CONFG_OFFSET));
	GPIOB->CRH.val |=  ((pinMode | pinConf) << (pinNo << GPIO_CONFG_OFFSET));
}

void gpioB_setPinState(uint8_t pinNo, pinState_e pinState) {
	switch(pinState) {
		case LOW :
			GPIOB->ODR.val &= ~(1 << pinNo);
			break;

		case HIGH :
			GPIOB->ODR.val |=  (1 << pinNo);
			break;

		default:
			printf("Unsupported pin state");
			break;
	}
}

uint8_t gpioB_readInputPinState(uint8_t pinNo) {
	return ((GPIOB->IDR.val >> pinNo) & 0x01);
}

uint8_t gpioB_readOutputPinState(uint8_t pinNo) {
	return ((GPIOB->ODR.val >> pinNo) & 0x01);
}

void gpioB_setPortConfLow(uint32_t value) {
	GPIOB->CRL.val = value;
}

void gpioB_setPortConfHigh(uint32_t value) {
	GPIOB->CRH.val = value;
}

void gpioB_togglePinState(uint8_t pinNo) {
	GPIOB->ODR.val ^= (1 << pinNo);
}

void gpioB_setPortState(uint32_t value) {
	GPIOB->ODR.val = value;
}

uint32_t gpioB_getPortState(void) {
	return GPIOB->ODR.val;
}
