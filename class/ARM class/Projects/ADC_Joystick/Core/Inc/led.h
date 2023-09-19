/*
 * led.h
 *
 *  Created on: Sep 19, 2023
 *      Author: user
 */




#ifndef INC_LED_H_
#define INC_LED_H_



#include "stm32f4xx.h"



enum LEDState {LED_OFF, LED_ON};


typedef struct {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin;
    uint8_t cur_state;
} LED;


void led_init(LED *, GPIO_TypeDef *, uint16_t);
void led_on(LED *);
void led_off(LED *);
void led_toggle(LED *);



#endif /* INC_LED_H_ */
