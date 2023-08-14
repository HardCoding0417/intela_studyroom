/*
 * Separates the project led_shift
 *
 * Created: 2023-08-14 오후 2:34:50
 * Author : Choi Myeongsu
 */ 




#include "ledshift.h"



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