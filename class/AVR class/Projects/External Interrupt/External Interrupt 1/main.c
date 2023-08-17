/*
 * External Interrupt 1.c
 *
 * Created: 2023-08-17 오후 12:15:49
 * Author : user
 */ 

#include <avr/io.h>

#include <avr/interrupt.h>


#define LED_DDR DDRD
#define LED_PORT PORTD



ISR(INT4_vect) {
	LED_PORT ^= 0x1 << 0;
}
ISR(INT5_vect) {
	LED_PORT ^= 0x1 << 1;
}


int main(void)
{
	EIMSK |= 0x1 << INT4;
	EIMSK |= 0x1 << INT5;
	
	EICRB |= 0x1 << ISC41 | 0x0 << ISC40; // falling edge
	EICRB |= 0x1 << ISC51 | 0x1 << ISC50; // rising edge
	
	
	DDRE &= ~(0x1 << DDRE4 | 0x1 << DDRE5);
	
	LED_DDR = 0xff;
	
	
	sei(); // enable external interrupt
	// cli(); disable external interrupt
	
    while (1) 
    {
		
    }
}

