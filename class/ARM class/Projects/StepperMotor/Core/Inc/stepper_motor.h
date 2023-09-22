/*
 * stepper.h
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */





#ifndef INC_STEPPER_MOTOR_H_
#define INC_STEPPER_MOTOR_H_




#include "stm32f4xx.h"



enum StepDirection{CCW, CW};
enum StepMode{FULLSTEP_WAVEDRIVE, FULLSTEP_2PHASES_ON, HALFSTEP_12PHASES_ON};


typedef struct {
    GPIO_TypeDef *GPIOx[4];
    uint16_t GPIO_Pin[4];

    float steps_per_cycle;
    float speed_variation_ratio;

    uint8_t step_direction : 1;
    uint8_t step_mode : 2;
    float step_per_min;
} StepperMotor;



void stepperMotor_init(StepperMotor *, GPIO_TypeDef *[4], uint16_t [4],
                       float, float, uint8_t, uint8_t, float);

void stepperMotor_drive(StepperMotor *, float);
void stepperMotor_stepOver(StepperMotor *, int64_t);
void stepperMotor_delay(StepperMotor *);




#endif /* INC_STEPPER_MOTOR_H_ */
