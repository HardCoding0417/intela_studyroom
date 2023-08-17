/*
 * External Interrupt 2.c
 *
 * Created: 2023-08-17 오후 2:10:00
 * Author : user
 */ 

#include <avr/io.h>

#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>



volatile uint8_t led_data = 0xfe;

ISR(INT4_vect) {
	led_data = led_data << 1 | 0x01;
	
	if (led_data == 0xff) {
		led_data = 0xfe;
	}
	
	PORTD = led_data;
}


int main(void)
{
	EIMSK |= 0x1 << INT4;
	EICRB |= 0x1 << ISC40 | 0x1 << ISC41;
	DDRE &= ~(0x1 << DDRE4);
	
	sei();
	
	
	DDRD = 0xff;
	PORTD = led_data;
	
    while (1) 
    {
    }
}

