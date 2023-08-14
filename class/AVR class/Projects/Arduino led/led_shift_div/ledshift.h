/*
 * Declare LED shift control functions
 *
 * Created: 2023-08-14 오후 2:37:08
 *  Author: Choi Myeongsu
 */ 




#ifndef LEDSHIFT_H_
#define LEDSHIFT_H_



#include <avr/io.h>

#include "include.h"


void led_init();

void GPIO_Output(uint8_t);

void led_leftShift(uint8_t *);
void led_rightShift(uint8_t *);



#endif /* LEDSHIFT_H_ */