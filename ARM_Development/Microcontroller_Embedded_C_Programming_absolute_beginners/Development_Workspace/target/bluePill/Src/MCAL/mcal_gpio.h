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

#define GPIO_BASE_ADDR      (0x40010800)

#define GPIO_CONFG_RESET    (0x0F)
#define GPIO_CONFG_OFFSET   (0x02)

typedef enum pinMode {
	INPUT = 0,
	OUTPUT_10MHZ,
	OUTPUT_2MHZ,
	OUTPUT_50MHZ
}pinMode;

typedef enum pinConf {
	GP_OUT_PUSH_PULL = 0,
	GP_OUT_OPEN_DRAIN = 4,
	ALT_FUN_OUT_PUSH_PULL = 8,
	ALT_FUN_OUT_OPEN_DRAIN = 12
}pinConf;

typedef enum pinState {
	LOW = 0,
	HIGH
}pinState;

typedef union _CRL {
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
}_CRL;

typedef union _CRH {
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
}_CRH;

typedef union _IDR {
	struct {
		uint32_t       : 32;
	};
	uint32_t val;
}_IDR;

typedef union _ODR {
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
}_ODR;

typedef struct _GPIOA {
	_CRL CRL;
	_CRH CRH;
	_IDR IDR;
	_ODR ODR;
}_GPIOA;

void gpioA_setPinConf(uint8_t, pinMode, pinConf);
void gpioA_setPinState(uint8_t, pinState);

#endif /* MCAL_GPIO_H_ */
