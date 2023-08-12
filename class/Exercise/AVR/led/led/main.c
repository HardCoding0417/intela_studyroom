/*
 * Regularly turn a LED on and off
 *
 * Created: 2023-08-12 오후 4:37:42
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY_MS 100

#include <stdbool.h>

#include "led.h"


#define LED_PORT PORTG
#define LED_PIN DDRG0



int main() {
	LED LD2 = {&LED_PORT, LED_PIN};
	LED *LD2_ptr = &LD2;

	init_led(LD2_ptr);

    while (true) {
		led_on(LD2_ptr);
		_delay_ms(DELAY_MS);
		led_off(LD2_ptr);
		_delay_ms(DELAY_MS);
    }
}

