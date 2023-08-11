/*
 * led_div.c
 *
 * Created: 2023-08-11 오후 2:30:48
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include <stdlib.h>
#include <time.h>

#include "led.h"


#define DELAY_MS 10.

#define LED_CNT 8 // max: 255

#define LED_PORTX PORTD
#define LED_DDRm DDRD0



int main(void) {
	srand(time((time_t *)NULL));
	
	
	LED led_arr[LED_CNT] = {
		{&LED_PORTX, LED_DDRm},
		{&LED_PORTX, LED_DDRm + 1},
		{&LED_PORTX, LED_DDRm + 2},
		{&LED_PORTX, LED_DDRm + 3},
		{&LED_PORTX, LED_DDRm + 4},
		{&LED_PORTX, LED_DDRm + 5},
		{&LED_PORTX, LED_DDRm + 6},
		{&LED_PORTX, LED_DDRm + 7}
	};
	
	for (uint8_t i = 0; i < LED_CNT; ++i) {
		led_init(&led_arr[i]);
	}
	
	
    while (1) {
		for (uint8_t i = 0; i < LED_CNT; ++i) {
			if (rand() % 5 == 0) {
				led_on(&led_arr[i]);
			}
		}
		_delay_ms(DELAY_MS);
		for (uint8_t i = 0; i < LED_CNT; ++i) {
			led_off(&led_arr[i]);
		}
		_delay_ms(DELAY_MS);
    }
}

