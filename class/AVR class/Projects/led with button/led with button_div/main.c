/*
 * Lights up LEDs with buttons
 *
 * Created: 2023-08-17 오전 9:18:42
 * Author : Choi Myeongsu
 */ 




#include "button.h"


#define LED_DDR DDRD
#define LED_PORT PORTD



int main() {
	LED_DDR = 0xff;
	
	Button button_on;
	Button button_off;
	Button button_toggle;
	
	button_init(&button_on, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
	button_init(&button_off, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
	button_init(&button_toggle, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
	
	
    while (true) {
		if (button_getState(&button_on) == ACT_RELEASED) {
			LED_PORT = 0xff;
		}
		if (button_getState(&button_off) == ACT_RELEASED) {
			LED_PORT = 0x00;
		}
		if (button_getState(&button_toggle) == ACT_RELEASED) {
			LED_PORT ^= 0xff;
		}
    }
}