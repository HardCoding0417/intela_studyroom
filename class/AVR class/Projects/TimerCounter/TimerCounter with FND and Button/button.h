/*
 * Declares 'Button' type and its functions
 *
 * To change 'BUTTON_DDR' and 'BUTTON_PIN', modify hardware.h
 *
 * Created: 2023-08-17 오전 10:45:21
 *  Author: Choi Myeongsu
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_



#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include <stdbool.h>

#include "button_hardware.h"



#define DEBOUNCE_DELAY_MS 10.


enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSH, ACT_RELEASED}; // states of a button


typedef struct {
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	
	uint8_t pin_num;
	uint8_t prev_state;
} Button;


void button_init(Button *, volatile uint8_t *, volatile uint8_t *, uint8_t);
uint8_t button_getState(Button *);



#endif /* BUTTON_H_ */