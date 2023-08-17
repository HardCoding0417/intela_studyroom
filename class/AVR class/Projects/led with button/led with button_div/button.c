/*
 * Implements button.h
 *
 * Created: 2023-08-17 오전 10:46:38
 *  Author: Choi Myeongsu
 */ 



#include "button.h"



void button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pin_num) {
	button->ddr = ddr;
	button->pin = pin;
	button->pin_num = pin_num;
	button->prev_state = RELEASED;
	
	*ddr &= ~(0x1 << pin_num);
}

uint8_t button_getState(Button *button) {
	uint8_t cur_state = !!(*button->pin & 0x1 << button->pin_num);

	if (cur_state == PUSHED && button->prev_state == RELEASED) {
		// debounce code; To be obvious, put the same if statement inside the if statement
		_delay_ms(DEBOUNCE_DELAY_MS);
		button->prev_state = PUSHED;
		return ACT_PUSH;
	}
	else if (cur_state == RELEASED && button->prev_state == PUSHED) {
		_delay_ms(DEBOUNCE_DELAY_MS);
		button->prev_state = RELEASED;
		return ACT_RELEASED;
	}
	else{
		return NO_ACT;
	}
}