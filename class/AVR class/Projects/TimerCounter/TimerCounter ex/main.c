/*
 * A simple timer
 *
 * Created: 2023-08-21 오전 9:22:33
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdbool.h>

#include "FND.h"
#include "button.h"



enum ButtonPin {RUN_TOGGLE, RESET};


uint16_t timer_100ms;
uint8_t cnt_1ms;

bool is_paused = true;

ISR(TIMER0_OVF_vect) { // called for every 1ms
	if (is_paused) {
		return;
	}
	
	cnt_1ms++;
	TCNT0 = 6; // for TOI0 with 1ms period
	
	if (cnt_1ms == 100) { // 0.1s
		timer_100ms++;
		if (timer_100ms > 9999) {
			timer_100ms = 9999;
		}
		
		FND_setNum(timer_100ms);
		
		cnt_1ms = 0;
	}
}


int main(void)
{
	// FND initialization
	FND_init();
	
	
	// button initialization
	Button button_runToggle;
	Button button_reset;
	
	button_init(&button_runToggle, &BUTTON_DDR, &BUTTON_PIN, &BUTTON_PORT, RUN_TOGGLE);
	button_init(&button_reset, &BUTTON_DDR, &BUTTON_PIN, &BUTTON_PORT, RESET);
	
	
	// Timer/Counter Interrupt initialization
	TIMSK |= 0x1 << TOIE0;
	TCCR0 |= 0x1 << CS02 | 0x0 << CS01 | 0x0 << CS00; // pre-scaler factor 64
	TCNT0 = 6; // for TOI0 with 1ms period
	
	sei();
	
	
    while (1) {
		if (button_getAct(&button_runToggle) == ACT_PUSH) {
			is_paused = !is_paused;
			
			TCNT0 = 6; // for TOI0 with 1ms period
		}
		
		if (button_getAct(&button_reset) == ACT_PUSH) {
			is_paused = true;
			
			cnt_1ms = 0;
			timer_100ms = 0;
			FND_setNum(timer_100ms);
		}
		
		
	    FND_display();
    }
}

