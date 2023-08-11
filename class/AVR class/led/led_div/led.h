/*
 * led.h
 *
 * Created: 2023-08-11 오후 2:33:16
 *  Author: Choi Myeongsu
 */ 



#ifndef LED_H_
#define LED_H_



#include <avr/io.h>



typedef struct{
	volatile uint8_t *port; // 'volatile' for variable to store register value
	uint8_t pin;
} LED;


void led_init(LED *led);
void led_on(LED *led);
void led_off(LED *led);



#endif /* LED_H_ */