/*
 * mcal_gpio.h
 *
 *  Created on: Jan 15, 2021
 *      Author: abdelrhman
 */

#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_

#include <stdio.h>
#include <stdint.h>

#define GPIOA_BASE_ADDR      (0x40010800)
#define GPIOB_BASE_ADDR      (0x40010C00)

#define GPIO_CONFG_RESET    (0x0F)
#define GPIO_CONFG_OFFSET   (0x02)

typedef enum {
	INPUT = 0,
	OUTPUT_10MHZ,
	OUTPUT_2MHZ,
	OUTPUT_50MHZ
}pinMode_e;

typedef enum {
	GP_OUT_PUSH_PULL = 0,
	ANALOG_MODE = 0,
	GP_OUT_OPEN_DRAIN = 4,
	FLOATING_INPUT = 4,
	ALT_FUN_OUT_PUSH_PULL = 8,
	GP_IN_PULL_UP_DOWN = 8,
	ALT_FUN_OUT_OPEN_DRAIN = 12
}pinConf_e;

typedef enum {
	LOW = 0,
	HIGH
}pinState_e;

typedef union {
	struct {
		uint32_t MODE0 : 2;
		uint32_t CNF0  : 2;
		uint32_t MODE1 : 2;
		uint32_t CNF1  : 2;
		uint32_t MODE2 : 2;
		uint32_t CNF2  : 2;
		uint32_t MODE3 : 2;
		uint32_t CNF3  : 2;
		uint32_t MODE4 : 2;
		uint32_t CNF4  : 2;
		uint32_t MODE5 : 2;
		uint32_t CNF5  : 2;
		uint32_t MODE6 : 2;
		uint32_t CNF6  : 2;
		uint32_t MODE7 : 2;
		uint32_t CNF7  : 2;
	};
	uint32_t val;
}CRL_t;

typedef union {
	struct {
		uint32_t MODE8  : 2;
		uint32_t CNF8   : 2;
		uint32_t MODE9  : 2;
		uint32_t CNF9   : 2;
		uint32_t MODE10 : 2;
		uint32_t CNF10  : 2;
		uint32_t MODE11 : 2;
		uint32_t CNF11  : 2;
		uint32_t MODE12 : 2;
		uint32_t CNF12  : 2;
		uint32_t MODE13 : 2;
		uint32_t CNF13  : 2;
		uint32_t MODE14 : 2;
		uint32_t CNF14  : 2;
		uint32_t MODE15 : 2;
		uint32_t CNF15  : 2;
	};
	uint32_t val;
}CRH_t;

typedef union {
	struct {
		uint32_t IDR0  : 1;
		uint32_t IDR1  : 1;
		uint32_t IDR2  : 1;
		uint32_t IDR3  : 1;
		uint32_t IDR4  : 1;
		uint32_t IDR5  : 1;
		uint32_t IDR6  : 1;
		uint32_t IDR7  : 1;
		uint32_t IDR8  : 1;
		uint32_t IDR9  : 1;
		uint32_t IDR10 : 1;
		uint32_t IDR11 : 1;
		uint32_t IDR12 : 1;
		uint32_t IDR13 : 1;
		uint32_t IDR14 : 1;
		uint32_t IDR15 : 1;
		uint32_t       : 16;
	};
	uint32_t val;
}IDR_t;

typedef union {
	struct {
		uint32_t ODR0  : 1;
		uint32_t ODR1  : 1;
		uint32_t ODR2  : 1;
		uint32_t ODR3  : 1;
		uint32_t ODR4  : 1;
		uint32_t ODR5  : 1;
		uint32_t ODR6  : 1;
		uint32_t ODR7  : 1;
		uint32_t ODR8  : 1;
		uint32_t ODR9  : 1;
		uint32_t ODR10 : 1;
		uint32_t ODR11 : 1;
		uint32_t ODR12 : 1;
		uint32_t ODR13 : 1;
		uint32_t ODR14 : 1;
		uint32_t ODR15 : 1;
		uint32_t       : 16;
	};
	uint32_t val;
}ODR_t;

typedef struct {
	CRL_t CRL;
	CRH_t CRH;
	IDR_t IDR;
	ODR_t ODR;
}GPIO_t;

// GPIOA APIs
extern void gpioA_setPinConfLow(uint8_t, pinMode_e, pinConf_e);
extern void gpioA_setPinConfHigh(uint8_t, pinMode_e, pinConf_e);
extern void gpioA_setPinState(uint8_t, pinState_e);
extern uint8_t gpioA_readInputPinState(uint8_t);
extern uint8_t gpioA_readOutputPinState(uint8_t);
extern void gpioA_setPortConfLow(uint32_t);
extern void gpioA_setPortConfHigh(uint32_t);
extern void gpioA_togglePinState(uint8_t);
extern void gpioA_setPortState(uint32_t);
extern uint32_t gpioA_getPortState(void);

// GPIOB APIs
extern void gpioB_setPinConfLow(uint8_t, pinMode_e, pinConf_e);
extern void gpioB_setPinConfHigh(uint8_t, pinMode_e, pinConf_e);
extern void gpioB_setPinState(uint8_t, pinState_e);
extern uint8_t gpioB_readInputPinState(uint8_t);
extern uint8_t gpioB_readOutputPinState(uint8_t);
extern void gpioB_setPortConfLow(uint32_t);
extern void gpioB_setPortConfHigh(uint32_t);
extern void gpioB_togglePinState(uint8_t);
extern void gpioB_setPortState(uint32_t);
extern uint32_t gpioB_getPortState(void);
#endif /* MCAL_GPIO_H_ */
