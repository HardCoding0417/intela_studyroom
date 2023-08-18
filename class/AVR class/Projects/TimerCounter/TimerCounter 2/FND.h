/*
 * FND.h
 *
 * Created: 2023-08-18 오전 9:32:22
 *  Author: user
 */ 


#ifndef FND_H_
#define FND_H_



#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>


#define FND_DIGIT0 1
#define FND_DIGIT1 2
#define FND_DIGIT2 3
#define FND_DIGIT3 4

#define FND_GND_DDR DDRG
#define FND_GND_PORT PORTG
#define FND_DATA_DDR DDRC
#define FND_DATA_PORT PORTC


void FND_init();
void FND_setData(uint16_t);
uint16_t FND_getData();
void FND_selectDigit(uint8_t);
void FND_numDisplay(uint8_t);
void FND_off();
void FND_ISR_display();


#endif /* FND_H_ */