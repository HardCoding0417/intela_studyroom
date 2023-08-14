/*
 * Turns on LEDs in an annoying form
 *
 * Created: 2023-08-14 오후 12:41:47
 * Author : Choi Myeongsu
 */





#include <avr/io.h>



#define F_CPU 16000000UL
#include <util/delay.h>

#define DELAY_MS 30.



#include <stdbool.h>




#define LED_DDR DDRD
#define LED_PORT PORTD




int main() {
	LED_DDR = 0xff;
	
	while (true) {
		for (uint8_t i = 0; i < 3; ++i) {
			for (uint8_t j = 0; j < 8; ++j) {
				LED_PORT = 0xff >> j;
				_delay_ms(DELAY_MS);
			}
		}
		
		for (uint8_t i = 0; i < 3; ++i) {
			for (uint8_t j = 0; j < 8; ++j) {
				LED_PORT = 0xff << j;
				_delay_ms(DELAY_MS);
			}
		}
		
		for (uint8_t i = 0; i < 3; ++i) {
			for (uint8_t j = 0; j < 8; ++j) {
				LED_PORT = 0x1 << j;
				_delay_ms(DELAY_MS);
			}
		}
		
		for (uint8_t i = 0; i < 6; ++i) {
			for (uint8_t j = 0; j < 7; ++j) {
				LED_PORT = 0x1 << j;
				_delay_ms(DELAY_MS / 2);
			}
			for (uint8_t j = 0; j < 7; ++j) {
				LED_PORT = 0x80 >> j;
				_delay_ms(DELAY_MS / 2);
			}
		}
	}
}