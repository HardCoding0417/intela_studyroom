/*
 * Implements ledshift.h
 *
 * Created: 2023-08-14 오후 2:37:50
 *  Author: Choi Myeongsu
 */ 



#include "ledshift.h"
#include "hardware.h"


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