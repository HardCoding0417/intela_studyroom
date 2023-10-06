/*
 * led.h
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_




#include "stm32f4xx.h"


#define LED_MAX_CHANNEL 8



typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	GPIO_PinState on_state, off_state;
} LED;


void LED_on(uint8_t);
void LED_off(uint8_t);
void LED_toggle(uint8_t);




#endif /* INCLUDE_LED_H_ */
