/*
 * button.h
 *
 *  Created on: Sep 19, 2023
 *      Author: user
 */




#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_



#include "stm32f4xx.h"


typedef struct {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
    uint8_t prev_state;
} Button;


enum ButtonState {PUSHED, RELEASED};
enum ButtonAction {NO_ACT, ACT_PUSH, ACT_RELEASE};


void button_init(Button *, GPIO_TypeDef *, uint16_t);
uint8_t button_getAction(Button *);



#endif /* INC_BUTTON_H_ */
