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

typedef enum {
	GPIOA = 2,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG
}gpioPort_e;

typedef union {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}RC_t;

typedef union {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}CFGR_t;

typedef union _CIR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}CIR_t;

typedef union {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}APB2RSTR_t;

typedef union {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}APB1RSTR_t;

typedef union {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}AHBENR_t;

typedef union {
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
}APB2ENR_t;

typedef struct {
	RC_t       RC;
	CFGR_t     CFGR;
	CIR_t      CIR;
	APB2RSTR_t APB2RSTR;
	APB1RSTR_t APB1RSTR;
	AHBENR_t   AHBENR;
	APB2ENR_t  APB2ENR;
}RCC_t;

extern void rcc_gpioPortClkEnable(gpioPort_e);

#endif /* MCAL_RCC_H_ */
