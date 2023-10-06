/*
 * app.c
 *
 *  Created on: Oct 6, 2023
 *      Author: user
 */




#include "app.h"

#include <stdbool.h>

#include "delay.h"
#include "led.h"
#include "button.h"


#define FIRST_DURATION_MS 500
#define SECOND_DURATION_MS 100



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *);

void LED_on_off(uint8_t);


uint8_t LED_data = 0x01;

uint32_t ms_cnt;

bool is_button0_start = false;
bool is_button1_start = false;

bool is_first_duration = false;


void app_init() {

}

void app_main() {
	while (1) {
		if (button_getAction(0) == ACT_PUSH) {
			is_button0_start = true;
			is_button1_start = false;

			LED_data = LED_data << 1 | LED_data >> 7;

			is_first_duration = true;
			TIM10->CNT = 0;
			ms_cnt = 0;
		}
		else if (button_getAction(1) == ACT_PUSH) {
			is_button1_start = true;
			is_button0_start = false;

			LED_data = LED_data >> 1 | LED_data << 7;

			is_first_duration = true;
			TIM10->CNT = 0;
			ms_cnt = 0;
		}

		if (button_getState(0) == PUSHED) {
			if (is_button0_start) {
				if (is_first_duration && ms_cnt == FIRST_DURATION_MS) {
					LED_data = LED_data << 1 | LED_data >> 7;
					is_first_duration = false;
					TIM10->CNT = 0;
					ms_cnt = 0;
				}
				else if (!is_first_duration && ms_cnt == SECOND_DURATION_MS) {
					LED_data = LED_data << 1 | LED_data >> 7;
					TIM10->CNT = 0;
					ms_cnt = 0;
				}
			}
		}
		if (button_getState(1) == PUSHED) {
			if (is_button1_start) {
				if (is_first_duration && ms_cnt == FIRST_DURATION_MS) {
					LED_data = LED_data >> 1 | LED_data << 7;
					is_first_duration = false;
					TIM10->CNT = 0;
					ms_cnt = 0;
				}
				else if (!is_first_duration && ms_cnt == SECOND_DURATION_MS) {
					LED_data = LED_data >> 1 | LED_data << 7;
					TIM10->CNT = 0;
					ms_cnt = 0;
				}
			}
		}

		LED_on_off(LED_data);
	}
}



void LED_on_off(uint8_t byte_data) {
	for (int8_t i = 0; i < LED_MAX_CHANNEL; i++) {
		if (byte_data & 0x1) {
			LED_on(i);
		}
		else {
			LED_off(i);
		}
		byte_data >>= 1;
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM10) {
		ms_cnt++;
	}
}
