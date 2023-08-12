/*
 * Implements led.h
 *
 * Created: 2023-08-12 오후 5:16:14
 *  Author: Choi Myeongsu
 */ 




#include "led.h"



// Set DDRxn 1
void init_led(LED *led) {
	*(led->port - 1) |= 0x1 << led->pin;
}


// Set PORTxn 1
void led_on(LED *led) {
	*led->port |= 0x1 << led->pin;
}

// Set PORTxn 0
void led_off(LED *led) {
	*led->port &= ~(0x1 << led->pin);
}