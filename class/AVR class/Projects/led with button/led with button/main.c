/*
 * Lights up LEDs with button
 *
 * Created: 2023-08-16 오후 12:23:05
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include <stdbool.h>


#define BUTTON_DDR DDRB
#define BUTTON_PIN PINB
#define LED_DDR DDRD
#define LED_PORT PORTD

#define RECOG_INTERVAL 100.
#define LIGHT_INTERVAL 100.



int main() {
	LED_DDR = 0xff;
	BUTTON_DDR = 0x00;
	
	uint8_t byte_data = 0x00;
	uint8_t button_data;
	
	bool is_button2_pressed = 0;
	
    while (true) {
		button_data = BUTTON_PIN;
		
		if ( !(button_data & 0x1 << 0) ) {
			if (byte_data) {
				byte_data = byte_data << 1 | byte_data >> 7;
			}
			else {
				byte_data = 0x01;
			}
			LED_PORT = byte_data;
			_delay_ms(RECOG_INTERVAL);
		}
		if ( !(button_data & 0x1 << 1) ) {
			if (byte_data) {
				byte_data = byte_data >> 1 | byte_data << 7;
			}
			else {
				byte_data = 0x80;
			}
			LED_PORT = byte_data;
			_delay_ms(RECOG_INTERVAL);
		}
		if ( !(button_data & 0x1 << 2) ) {
			is_button2_pressed = true;
		}
		if ( !(button_data & 0x1 << 3) ) {
			LED_PORT = 0x00;
			
			byte_data = 0x00;
			is_button2_pressed = false;
		}
		
		if (is_button2_pressed) {
			LED_PORT = 0xff;
			_delay_ms(LIGHT_INTERVAL);
			LED_PORT = 0x00;
			_delay_ms(LIGHT_INTERVAL);
		}
    }
}

