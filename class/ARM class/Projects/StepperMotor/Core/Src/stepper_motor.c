/*
 * stepper.c
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */




#include "stepper_motor.h"
#include "delay.h"



uint8_t PinState_FULLSTEP_WAVEDRIVE[4][4] = {
        {GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET}
};
uint8_t PinState_FULLSTEP_2PHASES_ON[4][4] = {
        {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET},
        {GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET}
};
uint8_t PinState_HALFSTEP_12PHASES_ON[8][4] = {
        {GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET},
        {GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET},
        {GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET}
};


void stepperMotor_init(StepperMotor *stepper_motor,
                       GPIO_TypeDef *GPIOx[4], uint16_t GPIO_Pin[4],
                       float steps_per_cycle, float speed_variation_ratio,
                       uint8_t step_direction, uint8_t step_mode,
                       float step_per_min) {
    stepper_motor->GPIOx[0] = GPIOx[0];
    stepper_motor->GPIOx[1] = GPIOx[1];
    stepper_motor->GPIOx[2] = GPIOx[2];
    stepper_motor->GPIOx[3] = GPIOx[3];
    stepper_motor->GPIO_Pin[0] = GPIO_Pin[0];
    stepper_motor->GPIO_Pin[1] = GPIO_Pin[1];
    stepper_motor->GPIO_Pin[2] = GPIO_Pin[2];
    stepper_motor->GPIO_Pin[3] = GPIO_Pin[3];
    stepper_motor->steps_per_cycle = steps_per_cycle;
    stepper_motor->speed_variation_ratio = speed_variation_ratio;
    stepper_motor->step_direction = step_direction;
    stepper_motor->step_mode = step_mode;
    stepper_motor->step_per_min = step_per_min;
}

void stepperMotor_drive(StepperMotor *stepper_motor, float angle) {
    int64_t step_tot = angle / 360 * stepper_motor->steps_per_cycle / stepper_motor->speed_variation_ratio;

    for (int64_t step = 0; step < step_tot; step++) {
        stepperMotor_stepOver(stepper_motor, step);
        stepperMotor_delay(stepper_motor);
    }
}
void stepperMotor_stepOver(StepperMotor *stepper_motor, int64_t step) {
    switch (stepper_motor->step_mode) {
        case FULLSTEP_WAVEDRIVE:
            step %= 4;
            if (stepper_motor->step_direction == CCW) {
                step = 3 - step;
            }
            switch (step) {
                case 0:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_WAVEDRIVE[0][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_WAVEDRIVE[0][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_WAVEDRIVE[0][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_WAVEDRIVE[0][3]);
                    break;
                case 1:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_WAVEDRIVE[1][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_WAVEDRIVE[1][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_WAVEDRIVE[1][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_WAVEDRIVE[1][3]);
                    break;
                case 2:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_WAVEDRIVE[2][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_WAVEDRIVE[2][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_WAVEDRIVE[2][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_WAVEDRIVE[2][3]);
                    break;
                case 3:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_WAVEDRIVE[3][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_WAVEDRIVE[3][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_WAVEDRIVE[3][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_WAVEDRIVE[3][3]);
                    break;
            }
            break;
        case FULLSTEP_2PHASES_ON:
            step %= 4;
            if (stepper_motor->step_direction == CW) {
                step = 3 - step;
            }
            switch (step) {
                case 0:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_2PHASES_ON[0][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_2PHASES_ON[0][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_2PHASES_ON[0][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_2PHASES_ON[0][3]);
                    break;
                case 1:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_2PHASES_ON[1][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_2PHASES_ON[1][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_2PHASES_ON[1][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_2PHASES_ON[1][3]);
                    break;
                case 2:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_2PHASES_ON[2][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_2PHASES_ON[2][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_2PHASES_ON[2][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_2PHASES_ON[2][3]);
                    break;
                case 3:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_FULLSTEP_2PHASES_ON[3][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_FULLSTEP_2PHASES_ON[3][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_FULLSTEP_2PHASES_ON[3][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_FULLSTEP_2PHASES_ON[3][3]);
                    break;
            }
            break;
        case HALFSTEP_12PHASES_ON:
            step %= 8;
            if (stepper_motor->step_direction == CW) {
                step = 7 - step;
            }
            switch (step) {
                case 0:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[0][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[0][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[0][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[0][3]);
                    break;
                case 1:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[1][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[1][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[1][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[1][3]);
                    break;
                case 2:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[2][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[2][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[2][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[2][3]);
                    break;
                case 3:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[3][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[3][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[3][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[3][3]);
                    break;
                case 4:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[4][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[4][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[4][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[4][3]);
                    break;
                case 5:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[5][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[5][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[5][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[5][3]);
                    break;
                case 6:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[6][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[6][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[6][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[6][3]);
                    break;
                case 7:
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[0],
                                      stepper_motor->GPIO_Pin[0],
                                      PinState_HALFSTEP_12PHASES_ON[7][0]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[1],
                                      stepper_motor->GPIO_Pin[1],
                                      PinState_HALFSTEP_12PHASES_ON[7][1]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[2],
                                      stepper_motor->GPIO_Pin[2],
                                      PinState_HALFSTEP_12PHASES_ON[7][2]);
                    HAL_GPIO_WritePin(stepper_motor->GPIOx[3],
                                      stepper_motor->GPIO_Pin[3],
                                      PinState_HALFSTEP_12PHASES_ON[7][3]);
                    break;
            }
            break;
    }
}
void stepperMotor_delay(StepperMotor *stepper_motor) {
    delay_us(60000000 / stepper_motor->steps_per_cycle *
             stepper_motor->speed_variation_ratio /
             stepper_motor->step_per_min);
}
