/*
 * Declare FND macros, variables, and functions
 *
 * Created: 2023-08-21 오전 9:29:31
 *  Author: Choi Myeongsu
 */ 




#ifndef FND_H_
#define FND_H_



#include <avr/io.h>

// MCU's crystal oscillator frequency
#define F_CPU 16000000UL
#include <util/delay.h>



// define the ports for FND's Vcc and GND
#define FND_DATA_DDR DDRC
#define FND_DATA_PORT PORTC
#define FND_GND_DDR DDRG
#define FND_GND_PORT PORTG

// define pin number for each FND's led position
// L: left, R: right, B: bottom, T: top
#define FND_DATA_LB 0
#define FND_DATA_B 1
#define FND_DATA_DP 2
#define FND_DATA_RB 3
#define FND_DATA_C 4
#define FND_DATA_RT 5
#define FND_DATA_LT 6
#define FND_DATA_T 7

// define pin number for each FND's digit GND
// FND_GND3 for the leftmost digit
#define FND_GND3 4
#define FND_GND2 3
#define FND_GND1 2
#define FND_GND0 1


// 1 for decimal point use
// DP3 for the leftmost decimal point
#define DP3 0
#define DP2 0
#define DP1 1
#define DP0 0

// minimum number of digits to be displayed
// choose one; 1, 2, 3, 4
#define MIN_DIGIT 2



void FND_init();

void FND_setNum(uint16_t);
uint16_t FND_getNum();

void FND_setDigit(uint8_t, uint8_t);
void FND_setGND(uint8_t);

void FND_off();

void FND_display();



#endif /* FND_H_ */