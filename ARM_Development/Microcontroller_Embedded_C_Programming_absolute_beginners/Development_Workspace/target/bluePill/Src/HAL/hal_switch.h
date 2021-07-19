/*
 * hal_switch.h
 *
 *  Created on: Jan 23, 2021
 *      Author: abdelrhman
 */

#ifndef HAL_SWITCH_H_
#define HAL_SWITCH_H_


#include "../MCAL/mcal_gpio.h"
#include "../MCAL/mcal_rcc.h"

#define INPUT_PULL_UP_DOWN (0x00000888)

typedef enum {
	SW1 = 8,
	SW2,
	SW3
}switch_e;

extern void sw_init(void);
extern uint8_t sw_readValue(switch_e);
#endif /* HAL_SWITCH_H_ */
