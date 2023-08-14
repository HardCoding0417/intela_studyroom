/*
 * Turns on LEDs in specific form
 *
 * Created: 2023-08-14 오후 12:39:12
 * Author : Choi Myeongsu
 */ 





#include <avr/io.h>



#define F_CPU 16000000UL
#include <util/delay.h>

#define DELAY_MS 50.



#include <stdbool.h>




#define LED_DDR DDRD
#define LED_PORT PORTD




int main() {
	LED_DDR = 0xff;
	
	while (true) {
		for (uint8_t i = 0; i < 7; ++i) {
			LED_PORT = 0x1 << i;
			_delay_ms(DELAY_MS);
		}
		for (uint8_t i = 7; i > 0; --i) {
			LED_PORT = 0x1 << i;
			_delay_ms(DELAY_MS); 
		}
	}
}