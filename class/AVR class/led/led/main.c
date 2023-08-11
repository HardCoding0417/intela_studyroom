/*
 * Lights LD2 on and off regularly
 *
 * Created: 2023-08-11 오전 11:48:24
 * Author : Choi Myeongsu
 */ 




#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>

#include <stdbool.h>


#define TIME_DELAY 30



int main() {
    DDRG |= 0x1 << DDRG0;
	
    while (true) {
		PORTG |= 0x1 << PORTG0;
		
		_delay_ms(TIME_DELAY);
		
		PORTG &= ~(0x1 << PORTG0);
		
		_delay_ms(TIME_DELAY);
    }
}