/*
 * UART.c
 *
 * Created: 2023-08-29 오전 11:56:04
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>



void UART0_init();
void UART0_transmit(uint8_t);
uint8_t UART0_receive();


int main(void)
{
	UART0_init();
	
    while (1) 
    {
		UART0_transmit(UART0_receive());
    }
}


void UART0_init() {
	UCSR0C &= ~(0x1 << UMSEL0); // Asynchronous Mode
	UBRR0H &= ~0x0f;
	UBRR0L = 207; // for 9600bps
	UCSR0A |= 0x1 << U2X0; // Double the USART transmission speed
	UCSR0B |= 0x1 << RXEN0 | 0x1 << TXEN0; // Enable receive and transmit
	UCSR0C |= 0x1 << UCSZ01 | 0x1 << UCSZ00; // 8-bit character size
}

void UART0_transmit(uint8_t data) {
	while (!(UCSR0A & 0x1 << UDRE0)) {
		/* Empty Loop Body */
	}
	UDR0 = data;
}
uint8_t UART0_receive() {
	while (!(UCSR0A & 0x1 << RXC0)) {
		/* Empty Loop Body */
	}
	return UDR0;
}