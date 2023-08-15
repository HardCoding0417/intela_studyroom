/*
 * 
 *
 * Created: 
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000
#include <util/delay.h>
#define DELAY_MS 30.


#define LED_DDR DDRD
#define LED_PORT PORTD



int main() {
	LED_DDR = 0xff;
	
    while (1) {
		LED_PORT = 0xff;
		_delay_ms(DELAY_MS);
		LED_PORT = 0x00;
		_delay_ms(DELAY_MS);
    }
}

