/*
 * FND.c
 *
 * Created: 2023-08-18 오전 9:32:11
 *  Author: user
 */ 




#include "FND.h"



uint16_t FND_data = 0;


void FND_init() {
	FND_GND_DDR |= 0x1 << FND_DIGIT0 | 0x1 << FND_DIGIT1 | 0x1 << FND_DIGIT2 | 0x1 << FND_DIGIT3;
	FND_DATA_DDR = 0xff;
	
	FND_GND_PORT |= 0x1 << FND_DIGIT0 | 0x1 << FND_DIGIT1 | 0x1 << FND_DIGIT2 | 0x1 << FND_DIGIT3; 
}

void FND_setData(uint16_t data) {
	if (data >= 10000) {
		data = 9999;
	}
	FND_data = data;
}
uint16_t FND_getData() {
	return FND_data;
}

void FND_selectDigit(uint8_t digit) {
	FND_GND_PORT &= ~(0x1 << digit);
}

void FND_numDisplay(uint8_t digit) {
	uint8_t byte_data[11] = {0x77, 0x14, 0x5b, 0x5e, 0x3c, 0x6e, 0x6f, 0x74, 0x7f, 0x7e, 0x00};
	FND_DATA_PORT = byte_data[digit];
}

void FND_off() {
	FND_GND_PORT |= 0x1 << FND_DIGIT0 | 0x1 << FND_DIGIT1 | 0x1 << FND_DIGIT2 | 0x1 << FND_DIGIT3; 
}

void FND_ISR_display() {
	static uint8_t FND_digit_pos = 0;
	uint16_t FND_data = FND_getData();
	
	FND_off();
	switch (FND_digit_pos) {
		case 0:
			FND_numDisplay(FND_data % 10);
			FND_selectDigit(FND_DIGIT0);
			break;
		case 1:
			if (FND_data >= 10) {
				FND_numDisplay(FND_data / 10 % 10);
				FND_selectDigit(FND_DIGIT1);
			}
			break;
		case 2:
			if (FND_data >= 100) {
				FND_numDisplay(FND_data / 100 % 10);
				FND_selectDigit(FND_DIGIT2);
			}
			break;
		case 3:
			if (FND_data >= 1000) {
				FND_numDisplay(FND_data / 1000);
				FND_selectDigit(FND_DIGIT3);
			}
			break;
	}
	_delay_ms(1.);
	
	FND_digit_pos++;
	if (FND_digit_pos == 4) {
		FND_digit_pos = 0;
	}
}