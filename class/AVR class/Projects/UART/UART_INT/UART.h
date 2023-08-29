/*
 * UART.h
 *
 * Created: 2023-08-29 오후 2:27:03
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_



#include <avr/io.h>



void UART_init();
void UART_transmit(uint8_t);
uint8_t UART_receive();



#endif /* UART_H_ */