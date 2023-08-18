/*
 * TimerCounter with FND and Button.c
 *
 * Created: 2023-08-18 오전 11:49:30
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "FND.h"
#include "button.h"


ISR(TIMER0_OVF_vect) {
	FND_ISR_display();
	TCNT0 = 6;
}


enum {BUTTON_RUN_TOGGLE, BUTTON_RESET};
enum {STOP, RUN, RESET};


int main(void)
{
	TIMSK |= 0x1 << TOIE0;
	TCCR0 |= 0x1 << CS02 | 0x0 << CS01 | 0x0 << CS00;
	TCNT0 = 6;
	
	sei();
	
	
	FND_init();
	
	
	uint16_t counter = 0;
	uint8_t counter_state = STOP;
	
	Button button_runToggle;
	Button button_reset;
	button_init(&button_runToggle, &BUTTON_DDR, &BUTTON_PIN, BUTTON_RUN_TOGGLE);
	button_init(&button_reset, &BUTTON_DDR, &BUTTON_PIN, BUTTON_RESET);
	
	

    while (1) 
    {
		switch (counter_state) {
			case RUN:
				if (button_getState(&button_runToggle) == ACT_PUSH) {
					counter_state = STOP;
				}
				else if (button_getState(&button_reset) == ACT_PUSH) {
					counter_state = RESET;
				}
				break;
			case STOP:
				if (button_getState(&button_runToggle) == ACT_PUSH) {
					counter_state = RUN;
				}
				else if (button_getState(&button_reset) == ACT_PUSH) {
					counter_state = RESET;
				}
				break;
		}
		
		switch (counter_state) {
			case STOP:
				FND_setData(counter);
				break;
			case RUN:
				FND_setData(counter++);
				_delay_ms(50.);
				break;
			case RESET:
				counter = 0;
				FND_setData(counter);
				counter_state = STOP;
				break;
		}
    }
}

