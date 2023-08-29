/*
 * Fast_PWM.c
 *
 * Created: 2023-08-29 오전 9:37:23
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>



int main(void)
{
	DDRB |= 0x1 << 4; // PB4 for OC0
	
	TCCR0 |= 0x0 << CS02 | 0x0 << CS01 | 0x1 << CS00; // pre-scaler factor 128
	TCCR0 |= 0x1 << WGM01 | 0x1 << WGM00; // Fast-PWM
	TCCR0 |= 0x1 << COM01 | 0x0 << COM00; // non-inverting mode
	
    while (1) 
    {
		for (uint8_t i = 0; i < 255; i++) {
			OCR0 = i;
			_delay_ms(10);
		}
		for (uint8_t i = 255; i > 0; i--) {
			OCR0 = i;
			_delay_ms(10);
		}
    }
}

