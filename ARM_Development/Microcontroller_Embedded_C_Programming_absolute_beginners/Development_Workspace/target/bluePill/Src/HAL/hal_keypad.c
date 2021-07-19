/*
 * hal_keypad.c
 *
 *  Created on: Jan 27, 2021
 *      Author: abdelrhman
 */

#include "hal_keypad.h"

static const char keypad[NO_OF_ROWS][NO_OF_COLS] = { {'1', '2', '3', 'A'},
													 {'4', '5', '6', 'B'},
													 {'7', '8', '9', 'C'},
													 {'*', '0', '#', 'D'} };

void keypad_init(void) {
	rcc_gpioPortClkEnable(GPIOA);
	gpioA_setPortConfLow(KEYPAD_CONFIG);
	gpioA_setPortState(0x000000FF);
}

char keypad_getPressedKey(void) {
	uint32_t volatile portA;
	for(uint8_t row = ROW1; row < NO_OF_ROWS; row++) {
		portA = gpioA_getPortState();
		portA = (portA & 0xFFFFFFF0) | ~(1 << row);
		gpioA_setPortState(portA);
		for(uint8_t col = COL1; col < NO_OF_COLS + NO_OF_ROWS; col++) {
			if(gpioA_readInputPinState(col) == 0) {
				delay_ms(200);
				return keypad[row][col - NO_OF_COLS];
			}
		}
	}
	return (char)-1;
}
