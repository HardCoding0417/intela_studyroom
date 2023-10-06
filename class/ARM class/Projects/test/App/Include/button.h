/*
 * button.h
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#ifndef INCLUDE_BUTTON_H_
#define INCLUDE_BUTTON_H_



#include "stm32f4xx.h"


#define BUTTON_MAX_CHANNEL 2


typedef enum {
	PUSHED, RELEASED
} ButtonState;
typedef enum {
	NO_ACT, ACT_PUSH, ACT_RELEASE
} ButtonAction;

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	ButtonState prev_state;
	ButtonState state_push, state_release;
} Button;


ButtonState button_getState(uint8_t);
ButtonAction button_getAction(uint8_t);



#endif /* INCLUDE_BUTTON_H_ */
