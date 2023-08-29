/*
 * UART.c
 *
 * Created: 2023-08-29 오후 2:26:54
 *  Author: user
 */ 




#include "UART.h"



void UART_init() {
	UCSR0C &= ~(0x1 << UMSEL0); // Asynchronous Mode
	UBRR0H &= ~0x0f;
	UBRR0L = 0xcf; // for 9600bps
	UCSR0A |= 0x1 << U2X0; // Double the USART transmission speed
	UCSR0B |= 0x1 << RXEN0 | 0x1 << TXEN0; // Enable receive and transmit
	UCSR0C |= 0x1 << UCSZ01 | 0x1 << UCSZ00; // 8-bit character size
}

void UART_transmit(uint8_t data) {
	while (!(UCSR0A & 0x1 << UDRE0)) {
		/* Empty Loop Body */
	}
	UDR0 = data;
}
uint8_t UART_receive() {
	while (!(UCSR0A & 0x1 << RXC0)) {
		/* Empty Loop Body */
	}
	return UDR0;
}