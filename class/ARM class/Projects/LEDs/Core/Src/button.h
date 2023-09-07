/*
 * Button.h
 *
 *  Created on: Sep 6, 2023
 *      Author: user
 */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_




#include "stm32f4xx_hal.h"


enum ButtonStatus {PUSHED, RELEASED};
enum ButtonAction {NO_ACT, ACT_PUSH, ACT_RELEASE};


typedef struct _Button {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_pin;
    uint8_t prev_state;
} Button;


void button_init(Button *, GPIO_TypeDef *, uint16_t);

uint8_t button_getAction(Button *);




#endif /* SRC_BUTTON_H_ */
