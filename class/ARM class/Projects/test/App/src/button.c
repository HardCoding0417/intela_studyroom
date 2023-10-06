/*
 * button.c
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#include "button.h"



Button button[BUTTON_MAX_CHANNEL] = {
		{GPIOB, GPIO_PIN_1, RELEASED, PUSHED, RELEASED},
		{GPIOB, GPIO_PIN_15, RELEASED, PUSHED, RELEASED}
};


ButtonState button_getState(uint8_t ch) {
	ButtonState state =
			HAL_GPIO_ReadPin(button[ch].GPIOx, button[ch].GPIO_Pin);
	if (state == PUSHED) {
		return button[ch].state_push;
	}
	else {
		return button[ch].state_release;
	}
}
ButtonAction button_getAction(uint8_t ch) {
	ButtonState cur_state = button_getState(ch);
	if (cur_state == PUSHED && button[ch].prev_state == RELEASED) {
		button[ch].prev_state = PUSHED;
		return ACT_PUSH;
	}
	else if (cur_state == RELEASED && button[ch].prev_state == PUSHED) {
		button[ch].prev_state = RELEASED;
		return ACT_RELEASE;
	}
	else {
		return NO_ACT;
	}
}
