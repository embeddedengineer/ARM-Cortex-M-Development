/*
 * MCAL_rcc.h
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */

#ifndef MCAL_RCC_H_
#define MCAL_RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR (0x40021000)

typedef enum gpioPort {
	GPIOA = 2,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG
}gpioPort;

typedef union _RC {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_RC;

typedef union _CFGR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_CFGR;

typedef union _CIR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_CIR;

typedef union _APB2RSTR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_APB2RSTR;

typedef union _APB1RSTR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_APB1RSTR;

typedef union _AHBENR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_AHBENR;

typedef union _APB2ENR {
	struct {
		uint32_t AFIO  : 1;
		uint32_t       : 1;
		uint32_t IOPA  : 1;
		uint32_t IOPB  : 1;
		uint32_t IOPC  : 1;
		uint32_t IOPD  : 1;
		uint32_t IOPE  : 1;
		uint32_t IOPF  : 1;
		uint32_t IOPG  : 1;
		uint32_t ADC1  : 1;
		uint32_t ADC2  : 1;
		uint32_t TIM1  : 1;
		uint32_t SPI1  : 1;
		uint32_t TIM8  : 1;
		uint32_t USART : 1;
		uint32_t ADC3  : 1;
		uint32_t       : 3;
		uint32_t TIM9  : 1;
		uint32_t TIM10 : 1;
		uint32_t TIM11 : 1;
		uint32_t       : 10;
	};
	uint32_t val;
}_APB2ENR;

typedef struct _RCC {
	_RC       RC;
	_CFGR     CFGR;
	_CIR      CIR;
	_APB2RSTR APB2RSTR;
	_APB1RSTR APB1RSTR;
	_AHBENR   AHBENR;
	_APB2ENR  APB2ENR;
}_RCC;

extern void rcc_gpioPortClkEnable(gpioPort);

#endif /* MCAL_RCC_H_ */
