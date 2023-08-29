/*
 * UART_INT.c
 *
 * Created: 2023-08-29 오후 2:25:45
 * Author : Choi Myeongsu
 */ 




#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <stdbool.h>

#include "UART.h"



FILE OUTPUT = FDEV_SETUP_STREAM(UART_transmit, NULL, _FDEV_SETUP_WRITE);

char rx_buf[100] = {0};
bool rx_flag = false;



ISR(USART0_RX_vect) {
	static uint8_t rx_head = 0;
	uint8_t rx_data = UDR0;
	
	if (rx_data == '\n' || rx_data == '\r') {
		rx_buf[rx_head] = '\0';
		rx_head = 0;
		rx_flag = true;
	}
	else {
		rx_buf[rx_head] = rx_data;
		rx_head++;
	}
}



int main(void)
{
	UART_init();
	
	UCSR0B |= 0x1 << RXCIE0;
	sei();
	
	stdout = &OUTPUT;
	
	while (1) 
    {
		if (rx_flag) {
			rx_flag = false;
			printf(rx_buf);
		}
    }
}

