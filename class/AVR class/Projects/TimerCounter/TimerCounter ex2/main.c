/*
 * Practice to use PWM Mode
 *
 * Created: 2023-08-21 오후 4:07:29
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
	DDRB = 0x10;
	
	
	TCCR0 |= 0x0 << CS02 | 0x1 << CS01 | 0x1 << CS00; // prescaler factor 32
	TCCR0 |= 0x0 << WGM01 | 0x1 << WGM00;
	TCCR0 |= 0x1 << COM01 | 0x0 << COM00;
	
	OCR0 = 51; // 51/255 = 1/4; 20% duty cycle
	
	sei();


    while (1) 
    {
    }
}

