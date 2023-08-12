/*
 * Declare LED struct and related functions
 *
 * Created: 2023-08-12 오후 4:45:39
 *  Author: Choi Myeongsu
 */ 



#ifndef LED_H_
#define LED_H_



#include <avr/io.h>



typedef struct {
	volatile uint8_t *port;
	uint8_t pin;
} LED;


void init_led(LED *led);
void led_on(LED *led);
void led_off(LED *led);



#endif /* LED_H_ */