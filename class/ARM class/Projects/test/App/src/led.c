/*
 * led.c
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#include "led.h"



LED led[LED_MAX_CHANNEL] = {
		{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_4, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOB, GPIO_PIN_3, GPIO_PIN_SET, GPIO_PIN_RESET},
		{GPIOA, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET}
};


void LED_on(uint8_t ch) {
	if (ch >= LED_MAX_CHANNEL) return;
	HAL_GPIO_WritePin(led[ch].GPIOx, led[ch].GPIO_Pin, led[ch].on_state);
}
void LED_off(uint8_t ch) {
	if (ch >= LED_MAX_CHANNEL) return;
	HAL_GPIO_WritePin(led[ch].GPIOx, led[ch].GPIO_Pin, led[ch].off_state);
}
void LED_toggle(uint8_t ch) {
	if (ch >= LED_MAX_CHANNEL) return;
	HAL_GPIO_TogglePin(led[ch].GPIOx, led[ch].GPIO_Pin);
}
