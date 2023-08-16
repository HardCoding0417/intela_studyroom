/*
 * Lights up 4 FNDs with professor
 *
 * Created: 2023-08-16 오전 10:38:44
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include <stdbool.h>


#define FND_DATA_DDR	DDRD
#define FND_SELECT_DDR	DDRB
#define FND_DATA_PORT	PORTD
#define FND_SELECT_PORT	PORTB



void FND_display(uint16_t);


int main() {
	FND_DATA_DDR = 0xff;
	FND_SELECT_DDR = 0xff;
	FND_SELECT_PORT = 0x00;
	
	uint16_t count = 0;
	uint32_t time_tick = 0;
	uint32_t prev_time = 0;
	
    while (true) {
		FND_display(count);
		
		if (time_tick - prev_time > 10) {
			prev_time = time_tick;
			count++;
			
			if (count == 10000) {
				count = 0;
			}
		}
		
		_delay_ms(1.);
		time_tick++;
    }
}


void FND_display(uint16_t data) {
	static uint8_t position = 0;
	uint8_t FND_data[11] = {0x77, 0x14, 0x5b, 0x5e, 0x3c, 0x6e, 0x6f, 0x74, 0x7f, 0x7e, 0x00};
		
	switch (position) {
		case 0:
			FND_SELECT_PORT &= ~(0x1 << 0);
			FND_SELECT_PORT |= 0x1 << 1 | 0x1 << 2 | 0x1 << 3;
			FND_DATA_PORT = FND_data[data % 10];
			break;
		case 1:
			FND_SELECT_PORT &= ~(0x1 << 1);
			FND_SELECT_PORT |= 0x1 << 0 | 0x1 << 2 | 0x1 << 3;
			if (data < 10) {
				FND_DATA_PORT = FND_data[10];
			}
			else {
				FND_DATA_PORT = FND_data[data / 10 % 10];
			}
			break;
		case 2:
			FND_SELECT_PORT &= ~(0x1 << 2);
			FND_SELECT_PORT |= 0x1 << 0 | 0x1 << 1 | 0x1 << 3;
			if (data < 100) {
				FND_DATA_PORT = FND_data[10];
			}
			else {
				FND_DATA_PORT = FND_data[data / 100 % 10];
			}
			break;
		case 3:
			FND_SELECT_PORT &= ~(0x1 << 3);
			FND_SELECT_PORT |= 0x1 << 0 | 0x1 << 1 | 0x1 << 2;
			if (data < 1000) {
				FND_DATA_PORT = FND_data[10];
			}
			else {
				FND_DATA_PORT = FND_data[data / 1000];
			}
			break;
	}
	
	position++;
	position %= 4;
}