/*
 * delay.c
 *
 *  Created on: Sep 12, 2023
 *      Author: user
 */




#include "delay.h"



void delay_us(uint16_t us) {
    __HAL_TIM_SET_COUNTER(&htim3, 0);

    while (__HAL_TIM_GET_COUNTER(&htim3) < us) {
        /* EMPTY LOOP BODY */
    }
}
