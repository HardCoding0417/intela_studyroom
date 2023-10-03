/*
 * fan.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */




#include "fan.h"



// Initialize Fan structure and initiate timer PWM generation
void fan_init(Fan *fan, TIM_HandleTypeDef *htim, uint32_t Channel) {
    fan->htim = htim;
    fan->Channel = Channel;

    HAL_TIM_PWM_Start(htim, Channel);
}

// Activate or deactivate fan
// percentage: power of output; 0. ~ 100.(%)
void fan_changeSpeed(Fan *fan, float percentage) {
    switch (fan->Channel) {
        case TIM_CHANNEL_1:
            fan->htim->Instance->CCR1 =
                    fan->htim->Instance->ARR * percentage;
            break;
        case TIM_CHANNEL_2:
            fan->htim->Instance->CCR2 =
                    fan->htim->Instance->ARR * percentage;
            break;
        case TIM_CHANNEL_3:
            fan->htim->Instance->CCR3 =
                    fan->htim->Instance->ARR * percentage;
            break;
        case TIM_CHANNEL_4:
            fan->htim->Instance->CCR4 =
                    fan->htim->Instance->ARR * percentage;
            break;
    }
}
