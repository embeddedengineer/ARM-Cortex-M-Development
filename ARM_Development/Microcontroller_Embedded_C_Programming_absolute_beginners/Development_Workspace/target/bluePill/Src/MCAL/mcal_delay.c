/*
 * mcal_delay.c
 *
 *  Created on: Jan 27, 2021
 *      Author: abdelrhman
 */


#include "mcal_delay.h"

void delay_ms(uint32_t ms) {
	for(uint32_t volatile i = 0; i < ms; i++) {
		for(uint16_t volatile j = 0; j < 670; j++);
	}
}
