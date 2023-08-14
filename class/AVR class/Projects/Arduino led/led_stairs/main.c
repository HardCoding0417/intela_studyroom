/*
 * Turns on LEDs in form of stairs
 *
 * Created: 2023-08-14 오후 3:36:46
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000
#include <util/delay.h>
#define DELAY_MS 30.

#include <stdbool.h>


#define LED_DDR DDRD
#define LED_PORT PORTD



int main() {
	LED_DDR = 0xff;
	
	uint8_t data = 0xff;
	
    while (true) {
		for (uint8_t i = 7; i > 0; --i) {
			LED_PORT = data << i;
			_delay_ms(DELAY_MS);
		}
		for (uint8_t i = 0; i < 8; ++i) {
			LED_PORT = data >> i;
			_delay_ms(DELAY_MS);
		}
    }
}

