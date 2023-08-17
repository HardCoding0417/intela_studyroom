/*
 * Lets the user customize a byte
 *
 * Created: 2023-08-17 오후 3:53:50
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define DEBOUNCE_DELAY_MS 50.

#include <stdbool.h>


#define LED_DDR DDRD
#define LED_PORT PORTD



bool is_button1_pressed = false;
bool is_button2_pressed = false;

ISR(INT4_vect) {
	is_button1_pressed = true;
}
ISR(INT5_vect) {
	is_button2_pressed = true;
}


bool is_TOI0_allowed = false;
bool is_TOI2_allowed = false;

uint16_t cnt_500ms;
uint8_t cnt_15ms;

uint8_t byte_data = 0x00;

ISR(TIMER0_OVF_vect) {
	if (!is_TOI0_allowed) {
		return;
	}
	if (PINE & 0x1 << PINE5) {
		is_TOI0_allowed = false;
		return;
	}
	
	
	cnt_500ms++;
	TCNT0 = 0x83; // 131; 256 - 131 = 125 clock sets correspond to 1ms
	
	if (cnt_500ms == 500) { // 500ms
		byte_data = byte_data << 1 | byte_data >> 7;
		LED_PORT = byte_data;

		TCNT2 = 0x06; // 6; 256 - 6 = 250 clock sets correspond to 0.5ms
		cnt_15ms = 0;
		is_TOI0_allowed = false;
		is_TOI2_allowed = true;
	}
}
ISR(TIMER2_OVF_vect) {
	if (!is_TOI2_allowed) {
		return;
	}
	if (PINE & 0x1 << PINE5) {
		is_TOI2_allowed = false;
		return;
	}
	
	
	cnt_15ms++;
	TCNT2 = 0x06; // 6; 256 - 6 = 250 clock sets correspond to 0.5ms
	
	if (cnt_15ms == 100) { // 50ms
		byte_data = byte_data << 1 | byte_data >> 7;
		LED_PORT = byte_data;
		
		cnt_15ms = 0;
	}
}



int main(void)
{
	LED_DDR = 0xff;
	
	DDRE &= ~(0x1 << DDRE4 | 0x1 << DDRE5);
	
	
	EIMSK |= 0x1 << INT4;
	EICRB |= 0x1 << ISC41 | 0x0 << ISC40;
	
	EIMSK |= 0x1 << INT5;
	EICRB |= 0x1 << ISC51 | 0x0 << ISC50;
	
	TIMSK |= 0x1 << TOIE0;
	TCCR0 |= 0x1 << CS02 | 0x0 << CS01 | 0x1 << CS00; // 128
	
	TIMSK |= 0x1 << TOIE2;
	TCCR2 |= 0x0 << CS22 | 0x1 << CS21 | 0x1 << CS20; // 64
	
	sei();
	
	
    while (1) 
    {
		if (is_button1_pressed) {
			_delay_ms(DEBOUNCE_DELAY_MS);
			if (!(PINE & 0x1 << PINE4)) {
				byte_data ^= 0x1;
				LED_PORT = byte_data;
			}
			is_button1_pressed = false;
		}
		if (is_button2_pressed) {
			_delay_ms(DEBOUNCE_DELAY_MS);
			if (!(PINE & 0x1 << PINE5)) {
				byte_data = byte_data << 1 | byte_data >> 7;
				LED_PORT = byte_data;
				
				TCNT0 = 0x83; // 131; 256 - 131 = 125 clock sets correspond to 1ms
				cnt_500ms = 0;
				is_TOI0_allowed = true;
			}
			is_button2_pressed = false;
		}
    }
}

