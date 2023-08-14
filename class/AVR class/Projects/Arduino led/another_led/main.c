/*
 * Turns on LEDs in specific form, with functions
 *
 * Created: 2023-08-14 오후 2:14:52
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define DELAY_MS 10.


#include <stdbool.h>


#define LED_DDR DDRD
#define LED_PORT PORTD



void led_init();

void GPIO_Output(uint8_t);

void led_leftShift(uint8_t *);
void led_rightShift(uint8_t *);



int main() {
	led_init();
	
	uint8_t led_data = 0x01;
	uint8_t *led_data_ptr = &led_data;
	
    while (true) {
		for (uint8_t i = 0; i < 7; ++i) {
			led_leftShift(led_data_ptr);
			_delay_ms(DELAY_MS);
		}
		
		for (uint8_t i = 0; i < 7; ++i) {
			led_rightShift(led_data_ptr);
			_delay_ms(DELAY_MS);
		}
    }
}


void led_init() {
	LED_DDR = 0xff;
}

void GPIO_Output(uint8_t data) {
	LED_PORT = data;
}

void led_leftShift(uint8_t *data_ptr) {
	*data_ptr = *data_ptr << 1 | *data_ptr >> 7;
	GPIO_Output(*data_ptr);
}
void led_rightShift(uint8_t *data_ptr) {
	*data_ptr = *data_ptr >> 1 | *data_ptr << 7;
	GPIO_Output(*data_ptr);
}