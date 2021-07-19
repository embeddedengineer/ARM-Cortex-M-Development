/*
 * hal_keypad.h
 *
 *  Created on: Jan 27, 2021
 *      Author: abdelrhman
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#include "../MCAL/mcal_delay.h"
#include "../MCAL/mcal_gpio.h"
#include "../MCAL/mcal_rcc.h"

#define NO_OF_ROWS (4)
#define NO_OF_COLS (4)

#define KEYPAD_CONFIG (0x88881111)

#define ROW1 (0)
#define COL1 (4)

extern void keypad_init(void);
extern char keypad_getPressedKey(void);

#endif /* HAL_KEYPAD_H_ */
