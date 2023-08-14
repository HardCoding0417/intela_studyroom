/*
 * Turns on LEDs in 'X' form
 *
 * Created: 2023-08-14 오후 3:07:03
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY_MS 100.

#include <stdbool.h>


#define LED_DDR DDRD
#define LED_PORT PORTD


#define PATTERN_CNT 8



int main() {
	LED_DDR = 0xff;

	uint8_t pattern_arr[PATTERN_CNT] = {
		0x81, // 1000 0001
		0x42, // 0100 0010
		0x24, // 0010 0100
		0x18, // 0001 1000
		0x24, // 0010 0100
		0x42, // 0100 0010
		0x81, // 1000 0001
		0x00  // 0000 0000
	};

    while (true) {
		for (uint8_t pattern_idx = 0; pattern_idx < PATTERN_CNT; ++pattern_idx) {
			LED_PORT = pattern_arr[pattern_idx];
			_delay_ms(DELAY_MS);
		}
    }
}

