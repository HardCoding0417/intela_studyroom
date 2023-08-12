/*
 * Turn the 8 LEDs on and off in specific form(X shape)
 *
 * Created: 2023-08-12 오후 5:39:03
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL // change to MCU's clock frequency
#include <util/delay.h>

#define DELAY_MS 100. // change duration of delay


#include <stdbool.h>
#include <stdlib.h>


#include "led.h"

#define LED_PORT PORTA // change PORTx



int main() {
	uint8_t shape_X[8] = {
		0x81, // 1000 0001
		0x42, // 0100 0010
		0x24, // 0010 0100
		0x18, // 0001 1000
		0x24, // 0010 0100
		0x42, // 0100 0010
		0x81, // 1000 0001
		0x00  // 0000 0000
	};

	LED *led_arr = (LED *)malloc(sizeof(LED) * 8);


	// Initialize 8 LEDs
	for (uint8_t pin_num = 0; pin_num < 8; ++pin_num) {
		led_arr[pin_num].port = &LED_PORT;
		led_arr[pin_num].pin = pin_num;

		init_led(led_arr + pin_num);
	}


	uint8_t byte; // status of LEDs for a moment

    while (true) {
		for (uint8_t step = 0; step < 8; ++step) {
			byte = shape_X[step];
			for (uint8_t pin_num = 0; pin_num < 8; ++pin_num) {
				if (byte & 1 << led_arr[pin_num].pin) {
					led_on(led_arr + pin_num);
				}
				else {
					led_off(led_arr + pin_num);
				}
			}

			_delay_ms(DELAY_MS);
		}
	}
}