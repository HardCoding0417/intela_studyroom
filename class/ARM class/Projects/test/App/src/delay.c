/*
 * delay.c
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#include "delay.h"



void delay_ms(uint32_t time_ms) {
	HAL_Delay(time_ms);
}

uint32_t millis() {
	return HAL_GetTick();
}
