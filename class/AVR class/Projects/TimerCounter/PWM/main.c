/*
 * CTC Mode practice
 *
 * Created: 2023-08-18 오후 2:47:07
 * Author : Choi Myeongsu
 */ 

#include <avr/io.h>


int main(void)
{
	TCCR0 |= 0x1 << CS02 | 0x0 << CS01 | 0x0 << CS00; // the prescaler divisor: 64
	TCCR0 |= 0x1 << WGM01 | 0x0 << WGM00;
	TCCR0 |= 0x0 << COM01 | 0x1 << COM00;
	OCR0 = 124; // for 1000Hz OC0
	
	DDRB = 0x10; // PB4(OC0)
	
    while (1) 
    {
    }
}

