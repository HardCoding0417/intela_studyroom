/*
 * TimerCounter 1.c
 *
 * Created: 2023-08-17 오후 3:49:35
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int cnt;

ISR(TIMER0_OVF_vect) {
	cnt++;
	TCNT0 = 131;
	
	if (cnt == 50) {
		PORTD = ~PORTD;
		cnt = 0;
	}
}

int main(void)
{
	DDRD = 0xff;
	
	
	TCCR0 |= 0x1 << CS02 | 0x1 << CS01 | 0x0 << CS00; // 256
	
	TIMSK |= 0x1 << TOIE0;
	sei();
	
	
    while (1) 
    {
    }
}

