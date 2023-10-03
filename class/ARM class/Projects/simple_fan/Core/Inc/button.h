/*
 * button.h
 *
 *  Created on: Sep 19, 2023
 *      Author: user
 */




#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_



// For HAL GPIO function
#include "stm32f4xx.h"


// the Button structure; has GPIO pin specification and the previous state
typedef struct {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
    uint8_t prev_state;
} Button;


// button state; 0 is pushed, 1 is released
enum ButtonState {PUSHED, RELEASED};
// button action; 0 is 'no act', 1 is 'act: push', 2 is 'act: release'
enum ButtonAction {NO_ACT, ACT_PUSH, ACT_RELEASE};


void button_init(Button *, GPIO_TypeDef *, uint16_t);
uint8_t button_getAction(Button *);



#endif /* INC_BUTTON_H_ */
