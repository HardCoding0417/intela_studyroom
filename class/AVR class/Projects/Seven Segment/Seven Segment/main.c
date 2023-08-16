/*
 * Lights up seven segment to display a digit
 *
 * Created: 2023-08-16 오전 9:13:08
 * Author : Choi Myeongsu
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY_MS 100

#include <stdbool.h>


int main() {
	uint8_t num_byte[10] = {0x00, 0x0c, 0x5b, 0x5e, 0x6c, 0x76, 0x77, 0x3c, 0x7f, 0x7e};
		
	DDRD = 0xff;
	
    while (true) {
		for (uint8_t i = 0; i < 10; i++){
			PORTD = num_byte[i];
			_delay_ms(DELAY_MS);
		}
    }
}

