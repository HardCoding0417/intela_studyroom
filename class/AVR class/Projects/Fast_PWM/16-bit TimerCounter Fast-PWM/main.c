/*
 * 16-bit TimerCounter Fast-PWM.c
 *
 * Created: 2023-08-29 오전 10:43:04
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>
#define DELAY_MS 0.4



int main(void)
{
	DDRB |= 0x1 << DDRB5; // for OC1A
	
	TCCR1B |= 0x0 << CS12 | 0x1 << CS11 | 0x1 << CS10; // pre-scaler factor 64
	TCCR1B |= 0x1 << WGM13 | 0x1 << WGM12;
	TCCR1A |= 0x1 << WGM11 | 0x0 << WGM10; // Fast-PWM Mode with TOP ICR1
	TCCR1A |= 0x1 << COM1A1 | 0x0 << COM1A0; // non-inverting mode
	ICR1 = 2499; // for 100Hz PWM
	
    while (1) 
    {
		for (uint16_t i = 0; i < 2499; i++) {
			OCR1A = i;
			_delay_ms(DELAY_MS);
		}
		for (uint16_t i = 2499; i > 0; i--) {
			OCR1A = i;
			_delay_ms(DELAY_MS);
		}
    }
}

