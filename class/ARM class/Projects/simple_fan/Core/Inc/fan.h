/*
 * fan.h
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */




#ifndef INC_FAN_H_
#define INC_FAN_H_



// For HAL GPIO function
#include "stm32f4xx.h"



// the Fan structure; has timer handler and timer channel
typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t Channel;
} Fan;


void fan_init(Fan *, TIM_HandleTypeDef *, uint32_t);

void fan_changeSpeed(Fan *, float);



#endif /* INC_FAN_H_ */
