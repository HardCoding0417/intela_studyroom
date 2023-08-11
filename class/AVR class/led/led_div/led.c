/*
 * led.c
 *
 * Created: 2023-08-11 오후 2:34:25
 *  Author: Choi Myeongsu
 */ 




#include "led.h"



// Initialize led
void led_init(LED *led) {
	*(led->port - 1) |= 0x1 << led->pin; // (address of DDRX) == (address of PORTX) - 1
}


// Turns the led on
void led_on(LED *led) {
	*(led->port) |= 0x1 << led->pin;
}

// Turns the led off
void led_off(LED *led) {
	*(led->port) &= ~(0X1 << led->pin);
}