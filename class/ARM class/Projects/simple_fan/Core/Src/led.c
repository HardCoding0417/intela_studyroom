/*
 * led.c
 *
 *  Created on: Sep 19, 2023
 *      Author: user
 */




#include "led.h"



// Initialize LED structure
void led_init(LED *led, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    led->GPIOx = GPIOx;
    led->GPIO_Pin = GPIO_Pin;
    led->cur_state = LED_OFF;
}

// Turn the LED on
void led_on(LED *led) {
    HAL_GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_SET);
    led->cur_state = LED_ON;
}
// Turn the LED off
void led_off(LED *led) {
    HAL_GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_RESET);
    led->cur_state = LED_OFF;
}
void led_toggle(LED *led) {
    if (led->cur_state == LED_OFF) {
        led_on(led);
    }
    else {
        led_off(led);
    }
}
