/*
 * External Interrupt 3.c
 *
 * Created: 2023-08-17 오후 3:04:08
 * Author : user
 */ 

#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define INT_DELAY_MS 50.

#include <avr/interrupt.h>



volatile uint8_t led_data = 0xfe;
uint8_t is_pressed = 0;


ISR(INT4_vect) {
	is_pressed = 1;
}


int main(void)
{
	DDRD = 0xff;
	PORTD = led_data;
	
	DDRE &= ~(0x1 << DDRE4);
	EIMSK |= 0x1 << INT4;
	EICRB |= 0x1 << ISC41 | 0x1 << ISC40;
	
	sei();

    while (1) 
    {
		if (is_pressed) {
			_delay_ms(INT_DELAY_MS);
			if (!(PINE & 0x1 << PINE4)) {
				led_data = led_data << 1 | 0x01;
				if (led_data == 0xff) {
					led_data = 0xfe;
				}
				
				PORTD = led_data;
			}
			is_pressed = 0;
		}
    }
}

