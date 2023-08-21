/*
 * Implements FND.h
 *
 * Created: 2023-08-21 오전 9:43:58
 *  Author: Choi Myeongsu
 */ 




#include "FND.h"



// A number to be displayed at FND
uint16_t FND_num;


// Set data direction for FND_DATA and FND_GND
void FND_init() {
	FND_DATA_DDR = 0xff;
	// initially off
	FND_off();
	FND_GND_DDR |= 0x1 << FND_GND3 | 0x1 << FND_GND2 | 0x1 << FND_GND1 | 0x1 << FND_GND0;
}

// Set the number to be displayed
void FND_setNum(uint16_t num) {
	FND_num = num;
	if (FND_num > 9999) {
		FND_num = 9999;
	}
}
// Get the number to be displayed
uint16_t FND_getNum() {
	return FND_num;
}

// Set a digit with FND_DATA_PORT
void FND_setDigit(uint8_t digit, uint8_t dp_pos) {
	static uint8_t digitByte_arr[11] = {0xeb, 0x28, 0xb3, 0xba, 0x78, 0xda, 0xdb, 0xe8, 0xfb, 0xfa, 0x00};
	uint8_t digit_byte = digitByte_arr[digit];
	
	switch (dp_pos) {
		case 0:
			digit_byte |= DP0 << FND_DATA_DP;
			break;
		case 1:
			digit_byte |= DP1 << FND_DATA_DP;
			break;
		case 2:
			digit_byte |= DP2 << FND_DATA_DP;
			break;
		case 3:
			digit_byte |= DP3 << FND_DATA_DP;
			break;
	}
	
	FND_DATA_PORT = digit_byte;
}
// Set a certain GND with FND_GND_PORT
void FND_setGND(uint8_t pin_num) {
	FND_GND_PORT &= ~(0x1 << pin_num);
}

// Turn off FND
void FND_off() {
	FND_GND_PORT |= 0x1 << FND_GND3 | 0x1 << FND_GND2 | 0x1 << FND_GND1 | 0x1 << FND_GND0;
}

// A display function to be called continuously
void FND_display() {
	static uint8_t digit_pos = 0;
	uint16_t num = FND_getNum();
	
	FND_off();
	switch (digit_pos) {
		case 0:
			FND_setDigit(num % 10, 0);
			FND_setGND(FND_GND0);
			break;
		case 1:
			if (MIN_DIGIT < 2 && num < 10) {
				break;
			}
			FND_setDigit(num / 10 % 10, 1);
			FND_setGND(FND_GND1);
			break;
		case 2:
			if (MIN_DIGIT < 3 && num < 100) {
				break;
			}
			FND_setDigit(num / 100 % 10, 2);
			FND_setGND(FND_GND2);
			break;
		case 3:
			if (MIN_DIGIT < 4 && num < 1000) {
				break;
			}
			FND_setDigit(num / 1000, 3);
			FND_setGND(FND_GND3);
			break;
	}
	// for clear appearance of digits
	_delay_ms(.9);
	
	digit_pos++;
	if (digit_pos == 4) {
		digit_pos = 0;
	}
}