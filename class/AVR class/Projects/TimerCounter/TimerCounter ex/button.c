/*
 * Implements button.h
 *
 * Created: 2023-08-21 오전 11:44:44
 *  Author: Choi Myeongsu
 */ 




#include <avr/io.h>

#include "button.h"



// Initialize a declared Button struct variable
void button_init(Button *button,
				volatile uint8_t *ddr, volatile uint8_t *pin, volatile uint8_t *port,
				uint8_t pin_num) {
	button->ddr = ddr;
	button->pin = pin;
	button->port = port;
	button->pin_num = pin_num;
	button->prev_state = RELEASE;
	
	*ddr &= ~(0x1 << pin_num);
	// enable MCU's internal pull-up resistor
	*port |= 0x1 << pin_num;
}

// Get the button's action of the moment
uint8_t button_getAct(Button *button) {
	// Due to pull-up resistor, cur_state is 0 when the button is released and is 1 when pushed 
	uint8_t cur_state = !(*button->pin & 0x1 << button->pin_num);
	if (cur_state) {
		cur_state = PUSH;
	}
	else {
		cur_state = RELEASE;
	}
	
	// button's state: RELEASE -> PUSH
	if (cur_state == PUSH && button->prev_state == RELEASE) {
		button->prev_state = PUSH;
		return ACT_PUSH;
	}
	// button's state: PUSH -> RELEASE
	else if (cur_state == RELEASE && button->prev_state == PUSH) {
		button->prev_state = RELEASE;
		return ACT_RELEASE;
	}
	else {
		return NO_ACT;
	}
}