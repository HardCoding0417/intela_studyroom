/*
 * Button.c
 *
 *  Created on: Sep 6, 2023
 *      Author: user
 */




#include "button.h"



void button_init(Button *button, GPIO_TypeDef *GPIOx, uint16_t GPIO_pin) {
    button->GPIOx = GPIOx;
    button->GPIO_pin = GPIO_pin;
    button->prev_state = RELEASED;
}

uint8_t button_getAction(Button *button) {
    uint8_t cur_state = HAL_GPIO_ReadPin(button->GPIOx, button->GPIO_pin);

    if (cur_state == PUSHED && button->prev_state == RELEASED) {
        button->prev_state = PUSHED;
        return ACT_PUSH;
    }
    else if (cur_state == RELEASED && button->prev_state == PUSHED) {
        button->prev_state = RELEASED;
        return ACT_RELEASE;
    }
    else {
        return NO_ACT;
    }
}
