/*
 * TimerCounter 2.c
 *
 * Created: 2023-08-18 오전 9:29:47
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "FND.h"


uint16_t counter = 0;

uint16_t cnt_TOI0 = 0;
ISR(TIMER0_OVF_vect) {
	cnt_TOI0++;
	TCNT0 = 6;
	
	if (cnt_TOI0 == 100) {
		FND_setData(counter++);
		cnt_TOI0 = 0;
	}
}


int main(void)
{
	TIMSK |= 0x1 << TOIE0;
	TCCR0 |= 0x1 << CS02 | 0x0 << CS01 | 0x0 << CS00; // let the pre-scaler group 64 clock cycles
	TCNT0 = 6; // 256 - 6 = 250; 1ms
	
	sei();
	DDRA = 0xff;
	FND_init();
	
    while (1) 
    {
		FND_ISR_display();
    }
}

