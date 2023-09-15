/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef uint8_t SPN;
typedef enum {
    DO, DO_SHARP, RE, RE_SHARP, MI, FA, FA_SHARP,
    SOL, SOL_SHARP, LA, LA_SHARP, SI
} Note;
typedef enum {
    PSC, ARR, CCR1
} TIM_Register;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TIM TIM11
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define PIANISSIMO 0.1
#define PIANO 0.3
#define MEZZOFORTE 0.6
#define FORTE 0.7

#define DELAY_QUARTER_NOTE 349
#define DELAY_HALF_NOTE DELAY_QUARTER_NOTE * 2
#define DELAY_EIGHTH_NOTE DELAY_QUARTER_NOTE / 2
#define DELAY_SIXTEENTH_NOTE DELAY_QUARTER_NOTE / 4
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t PWM_TONE[9][12][2] = {
        {
                {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
        },
        {
                {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
        },
        {
                {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
        },
        // octave 3
        {
                {0, 0}, {0, 0}, {0, 0},
                {56 - 1, 11479 - 1},
                {14 - 1, 43339 - 1},
                {21 - 1, 27271 - 1},
                {9 - 1, 60061 - 1},
                {10 - 1, 51021 - 1},
                {15 - 1, 32105 - 1},
                {15 - 1, 30303 - 1},
                {33 - 1, 13001 - 1},
                {22 - 1, 18407 - 1}
        },
        // octave 4
        {
                {25 - 1, 15289 - 1},
                {7 - 1, 51539 - 1},
                {12 - 1, 28377 - 1},
                {28 - 1, 11479 - 1},
                {7 - 1, 43339 - 1},
                {5 - 1, 57269 - 1},
                {5 - 1, 54055 - 1},
                {5 - 1, 51021 - 1},
                {4 - 1, 60197 - 1},
                {4 - 1, 56818 - 1},
                {4 - 1, 53679 - 1},
                {11 - 1, 18407 - 1}
        },
        // octave 5
        {
                {4 - 1, 47778 - 1},
                {3 - 1, 60129 - 1},
                {6 - 1, 28377 - 1},
                {14 - 1, 11479 - 1},
                {6 - 1, 25281 - 1},
                {4 - 1, 35793 - 1},
                {6 - 1, 22523 - 1},
                {2 - 1, 63776 - 1},
                {2 - 1, 60197 - 1},
                {2 - 1, 56818 - 1},
                {2 - 1, 53629 - 1},
                {2 - 1, 50619 - 1}
        },
        // octave 6
        {
                {2 - 1, 47778 - 1},
                {2 - 1, 45097 - 1},
                {3 - 1, 28377 - 1},
                {7 - 1, 11479 - 1},
                {3 - 1, 25281 - 1},
                {2 - 1, 35793 - 1},
                {3 - 1, 22523 - 1},
                {1 - 1, 63776 - 1},
                {1 - 1, 60196 - 1},
                {1 - 1, 56818 - 1},
                {1 - 1, 53629 - 1},
                {1 - 1, 50619 - 1}
        },
        // octave 7
        {
                {1 - 1, 47778 - 1},
                {1 - 1, 45097 - 1},
                {1 - 1, 42566 - 1},
                {1 - 1, 40177 - 1},
                {1 - 1, 37922 - 1},
                {1 - 1, 35793 - 1},
                {1 - 1, 33784 - 1},
                {1 - 1, 31888 - 1},
                {1 - 1, 30098 - 1},
                {1 - 1, 28409 - 1}
        }
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void sound_note(uint8_t, uint8_t, float, uint16_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    // page 1, bar 1
    sound_note(6, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 2
    sound_note(6, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 3
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 4
    sound_note(5, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 5
    sound_note(4, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 6
    sound_note(4, MI, FORTE - 0.025 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, FORTE - 0.025 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE - 0.025 * 7, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 7
    sound_note(4, MI, FORTE - 0.025 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.025 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 11, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, FORTE - 0.025 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE - 0.025 * 15, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 8
    sound_note(4, MI, FORTE - 0.025 * 16, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.025 * 17, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 18, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 19, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.025 * 20, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.025 * 21, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, FORTE - 0.025 * 22, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE - 0.025 * 23, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 9
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 10
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 11
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 12
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 13
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 14
    sound_note(4, DO, PIANISSIMO + 0.025 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO + 0.025 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 15
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 1, bar 16
    sound_note(4, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);

    // page 2, bar 1
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 2
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 3
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 4
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 5
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 6
    sound_note(4, FA, PIANISSIMO + 0.025 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.025 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 7
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 8
    sound_note(4, FA, PIANISSIMO + 0.025 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.025 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 9
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA, PIANISSIMO + 0.02 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SOL_SHARP, PIANISSIMO + 0.02 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA, PIANISSIMO + 0.02 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SOL_SHARP, PIANISSIMO + 0.02 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA, PIANISSIMO + 0.02 * 4, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 10
    sound_note(3, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA_SHARP, PIANISSIMO + 0.25 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.25 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA_SHARP, PIANISSIMO + 0.25 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.25 * 1, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 11
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.02 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.02 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.02 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.02 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.02 * 4, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 12
    sound_note(4, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO + 0.1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.25 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO + 0.25 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.25 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO + 0.25 * 1, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 13
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 14
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.15 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANISSIMO + 0.15 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, PIANISSIMO + 0.15 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL_SHARP, PIANISSIMO + 0.15 * 3, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 15
    sound_note(4, LA, FORTE - 0.1333333 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, FORTE - 0.133 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, FORTE - 0.1333333 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 16
    sound_note(4, LA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 2, bar 17
    sound_note(4, LA, PIANO, DELAY_EIGHTH_NOTE);
    sound_note(4, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 1
    sound_note(4, RE_SHARP, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 2
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 3
    sound_note(5, RE_SHARP, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 4
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 5
    sound_note(5, RE, PIANO + 0.05 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO + 0.05 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO + 0.05 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO + 0.05 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO + 0.05 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO + 0.05 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO + 0.05 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO + 0.05 * 7, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 6
    sound_note(5, RE, FORTE - 0.1333333 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE - 0.133 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE - 0.1333333 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 7
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 8
    sound_note(5, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(0, 0, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 9
    sound_note(6, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 10
    sound_note(6, RE, PIANO + 0.025 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO + 0.025 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO + 0.025 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO + 0.025 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO + 0.025 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO + 0.025 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANO + 0.025 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANO + 0.025 * 7, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 11
    sound_note(5, LA_SHARP, PIANO + 0.025 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO + 0.025 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO + 0.025 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO + 0.025 * 11, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO + 0.025 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO + 0.025 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANO + 0.025 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO + 0.025 * 15, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 12
    sound_note(6, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 13
    sound_note(6, DO, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 14
    sound_note(5, MI, FORTE + 0.3, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 15
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 16
    sound_note(0, 0, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE - 0.01428571 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, FORTE - 0.01428571 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE - 0.01428571 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.01428571 * 3, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 17
    sound_note(4, MI, FORTE - 0.01428571 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, FORTE - 0.01428571 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE - 0.01428571 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.01428571 * 7, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE - 0.01428571 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, FORTE - 0.01428571 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(4, MI, FORTE - 0.01428571 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.01428571 * 11, DELAY_SIXTEENTH_NOTE);
    // page 3, bar 18
    sound_note(4, MI, FORTE - 0.01428571 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE_SHARP, FORTE - 0.01428571 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.01428571 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.01428571 * 15, DELAY_SIXTEENTH_NOTE);
    sound_note(4, RE, FORTE - 0.01428571 * 16, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO_SHARP, FORTE - 0.01428571 * 17, DELAY_SIXTEENTH_NOTE);
    sound_note(4, DO, FORTE - 0.01428571 * 18, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE - 0.01428571 * 19, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 1
    sound_note(4, DO, FORTE - 0.01428571 * 20, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SI, FORTE - 0.01428571 * 21, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA_SHARP, FORTE - 0.01428571 * 22, DELAY_SIXTEENTH_NOTE);
    sound_note(3, LA, FORTE - 0.01428571 * 23, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SOL_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, SOL, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 2
    sound_note(3, MI, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 3
    sound_note(3, MI, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 4
    sound_note(3, MI, PIANO + 0.35, DELAY_SIXTEENTH_NOTE);
    sound_note(3, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(3, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(5, DO, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    // page 4, bar 5
    sound_note(4, LA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(4, FA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(4, LA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(5, DO, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    // page 4, bar 6
    sound_note(5, MI, MEZZOFORTE, DELAY_EIGHTH_NOTE);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE);
    sound_note(6, MI, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(6, DO, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    // page 4, bar 7
    sound_note(5, LA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(5, FA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(5, LA, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    sound_note(6, DO, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE * 4 / 5);
    // page 4, bar 8
    sound_note(6, MI, MEZZOFORTE, DELAY_EIGHTH_NOTE / 5);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE);
    sound_note(4, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, FA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SOL, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 9
    sound_note(4, SOL_SHARP, MEZZOFORTE - 0.02083333 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA, MEZZOFORTE - 0.02083333 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(4, LA_SHARP, MEZZOFORTE - 0.02083333 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, MEZZOFORTE - 0.02083333 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, MEZZOFORTE - 0.02083333 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, MEZZOFORTE - 0.02083333 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, MEZZOFORTE - 0.02083333 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, MEZZOFORTE - 0.02083333 * 7, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 10
    sound_note(5, MI, MEZZOFORTE - 0.02083333 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, MEZZOFORTE - 0.02083333 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, MEZZOFORTE - 0.02083333 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, MEZZOFORTE - 0.02083333 * 11, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, MEZZOFORTE - 0.02083333 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, MEZZOFORTE - 0.02083333 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, MEZZOFORTE - 0.02083333 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, MEZZOFORTE - 0.02083333 * 15, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 11
    sound_note(6, DO, MEZZOFORTE - 0.02083333 * 16, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, MEZZOFORTE - 0.02083333 * 17, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, MEZZOFORTE - 0.02083333 * 18, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE - 0.02083333 * 19, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE - 0.02083333 * 20, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, MEZZOFORTE - 0.02083333 * 21, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, MEZZOFORTE - 0.02083333 * 22, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, MEZZOFORTE - 0.02083333 * 23, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 12
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 13
    sound_note(5, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 14
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 15
    sound_note(5, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 16
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO + 0.0125 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO + 0.0125 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANISSIMO + 0.0125 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANISSIMO + 0.0125 * 3, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 17
    sound_note(5, DO, PIANISSIMO + 0.0125 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANISSIMO + 0.0125 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO + 0.0125 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO + 0.0125 * 7, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO + 0.0125 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO + 0.0125 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO + 0.0125 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO + 0.0125 * 11, DELAY_SIXTEENTH_NOTE);
    // page 4, bar 18
    sound_note(5, MI, PIANISSIMO + 0.0125 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANISSIMO + 0.0125 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANISSIMO + 0.0125 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO + 0.0125 * 15, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO - 0.01666667 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO - 0.01666667 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO, PIANO - 0.01666667 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(4, SI, PIANO - 0.01666667 * 3, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 1
    sound_note(5, DO, PIANO - 0.01666667 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, DO_SHARP, PIANO - 0.01666667 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE, PIANO - 0.01666667 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, RE_SHARP, PIANO - 0.01666667 * 7, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANO - 0.01666667 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANO - 0.01666667 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANO - 0.01666667 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANO - 0.01666667 * 11, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 2
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 3
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 4
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 5
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 6
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO + 0.0125 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO + 0.0125 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANISSIMO + 0.0125 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, MI, PIANISSIMO + 0.0125 * 3, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 7
    sound_note(5, FA, PIANISSIMO + 0.0125 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO + 0.0125 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO + 0.0125 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO + 0.0125 * 7, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO + 0.0125 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO + 0.0125 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO + 0.0125 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO + 0.0125 * 11, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 8
    sound_note(5, LA, PIANISSIMO + 0.0125 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO + 0.0125 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANISSIMO + 0.0125 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANISSIMO + 0.0125 * 15, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO - 0.01666667 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANO - 0.01666667 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANO - 0.01666667 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, PIANO - 0.01666667 * 3, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 9
    sound_note(5, LA, PIANO - 0.01666667 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO - 0.01666667 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO - 0.01666667 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANO - 0.01666667 * 7, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANO - 0.01666667 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANO - 0.01666667 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANO - 0.01666667 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO - 0.01666667 * 11, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 10
    sound_note(6, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 11
    sound_note(6, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 12
    sound_note(6, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 13
    sound_note(6, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 14
    sound_note(6, LA, PIANISSIMO, DELAY_EIGHTH_NOTE);
    sound_note(5, SOL_SHARP, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO - 0.001666667 * 0 + 0.05 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANISSIMO - 0.001666667 * 1 + 0.05 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANISSIMO - 0.001666667 * 2 + 0.05 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO - 0.001666667 * 3 + 0.05 * 3, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 15
    sound_note(6, RE, PIANO - 0.001666667 * 4 - 0.05 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO - 0.001666667 * 5 - 0.05 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO - 0.001666667 * 6 - 0.05 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO - 0.001666667 * 7 - 0.05 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANISSIMO - 0.001666667 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANISSIMO - 0.001666667 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO - 0.001666667 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO - 0.001666667 * 11, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 16
    sound_note(5, SOL_SHARP, PIANISSIMO - 0.001666667 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANISSIMO - 0.001666667 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANISSIMO - 0.001666667 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANISSIMO - 0.001666667 * 15, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANISSIMO - 0.001666667 * 16, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANISSIMO - 0.001666667 * 17, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANISSIMO - 0.001666667 * 18, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO - 0.001666667 * 19, DELAY_SIXTEENTH_NOTE);
    // page 5, bar 17
    sound_note(6, MI, PIANISSIMO - 0.001666667 * 20, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANISSIMO - 0.001666667 * 21, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANISSIMO - 0.001666667 * 22, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO - 0.001666667 * 23, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANISSIMO - 0.001666667 * 24, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANISSIMO - 0.001666667 * 25, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, PIANISSIMO - 0.001666667 * 26, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANISSIMO - 0.001666667 * 27, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 1
    sound_note(6, MI, PIANISSIMO - 0.001666667 * 28, DELAY_EIGHTH_NOTE);
    sound_note(6, SOL_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 2
    sound_note(7, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 3
    sound_note(6, SOL_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 4
    sound_note(7, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(7, MI, PIANO + 0.075 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA_SHARP, PIANO + 0.075 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL, PIANO + 0.075 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL_SHARP, PIANO + 0.075 * 3, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 5
    sound_note(7, LA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 6
    sound_note(7, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 7
    sound_note(6, LA, MEZZOFORTE - 0.01 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL_SHARP, MEZZOFORTE - 0.01 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL, MEZZOFORTE - 0.01 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA_SHARP, MEZZOFORTE - 0.01 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL, MEZZOFORTE - 0.01 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA_SHARP, MEZZOFORTE - 0.01 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, MEZZOFORTE - 0.01 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE - 0.01 * 7, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 8
    sound_note(6, FA, MEZZOFORTE - 0.01 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE - 0.01 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE - 0.01 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, MEZZOFORTE - 0.01 * 11, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, MEZZOFORTE - 0.01 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, MEZZOFORTE - 0.01 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, MEZZOFORTE - 0.01 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, MEZZOFORTE - 0.01 * 15, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 9
    sound_note(5, LA, MEZZOFORTE - 0.01 * 16 + 0.3, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, MEZZOFORTE - 0.01 * 17, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, MEZZOFORTE - 0.01 * 18, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, MEZZOFORTE - 0.01 * 19, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, MEZZOFORTE + 0.3, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 10
    sound_note(5, LA, MEZZOFORTE + 0.3, DELAY_EIGHTH_NOTE);
    sound_note(5, LA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 11
    sound_note(6, MI, MEZZOFORTE + 0.3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE + 0.3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 12
    sound_note(6, MI, MEZZOFORTE + 0.3, DELAY_EIGHTH_NOTE);
    sound_note(6, RE_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, MI, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL_SHARP, MEZZOFORTE, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 13
    sound_note(6, LA, MEZZOFORTE, DELAY_EIGHTH_NOTE);
    sound_note(0, 0, MEZZOFORTE, DELAY_EIGHTH_NOTE);
    sound_note(5, MI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, FA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SOL, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 14
    sound_note(5, SOL_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, LA_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(5, SI, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, DO_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE, PIANO, DELAY_SIXTEENTH_NOTE);
    sound_note(6, RE_SHARP, PIANO, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 15
    sound_note(6, MI, PIANO - 0.0125 * 0, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA, PIANO - 0.0125 * 1, DELAY_SIXTEENTH_NOTE);
    sound_note(6, FA_SHARP, PIANO - 0.0125 * 2, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL, PIANO - 0.0125 * 3, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SOL_SHARP, PIANO - 0.0125 * 4, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA, PIANO - 0.0125 * 5, DELAY_SIXTEENTH_NOTE);
    sound_note(6, LA_SHARP, PIANO - 0.0125 * 6, DELAY_SIXTEENTH_NOTE);
    sound_note(6, SI, PIANO - 0.0125 * 7, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 16
    sound_note(7, DO, PIANO - 0.0125 * 8, DELAY_SIXTEENTH_NOTE);
    sound_note(7, DO_SHARP, PIANO - 0.0125 * 9, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE, PIANO - 0.0125 * 10, DELAY_SIXTEENTH_NOTE);
    sound_note(7, RE_SHARP, PIANO - 0.0125 * 11, DELAY_SIXTEENTH_NOTE);
    sound_note(7, MI, PIANO - 0.0125 * 12, DELAY_SIXTEENTH_NOTE);
    sound_note(7, FA_SHARP, PIANO - 0.0125 * 13, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL, PIANO - 0.0125 * 14, DELAY_SIXTEENTH_NOTE);
    sound_note(7, SOL_SHARP, PIANO - 0.0125 * 15, DELAY_SIXTEENTH_NOTE);
    // page 6, bar 17
    sound_note(7, LA, PIANISSIMO, DELAY_EIGHTH_NOTE);
    sound_note(0, 0, PIANISSIMO, DELAY_EIGHTH_NOTE);
    sound_note(0, 0, PIANISSIMO, DELAY_QUARTER_NOTE);
    // page 6, bar 18
    sound_note(4, LA, PIANISSIMO, DELAY_SIXTEENTH_NOTE / 2);
    sound_note(5, DO, PIANISSIMO, DELAY_SIXTEENTH_NOTE / 2);
    sound_note(5, MI, PIANISSIMO, DELAY_SIXTEENTH_NOTE / 2);
    sound_note(5, LA, PIANISSIMO, DELAY_HALF_NOTE - DELAY_SIXTEENTH_NOTE * 3 / 2);
    // page 6, bar 19
    sound_note(3, LA, PIANISSIMO, DELAY_QUARTER_NOTE / 10);
    sound_note(0, 0, PIANISSIMO, DELAY_QUARTER_NOTE * 9 / 5);
    sound_note(0, 0, PIANISSIMO, DELAY_QUARTER_NOTE);

    while (1) {
        /* EMPTY LOOP BODY */
    }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void sound_note(uint8_t octave, uint8_t note,
                float intensity, uint16_t length_ms) {
    TIM->PSC = PWM_TONE[octave][note][PSC];
    TIM->ARR = PWM_TONE[octave][note][ARR];
    TIM->CCR1 = (uint16_t)(PWM_TONE[octave][note][ARR] * intensity);
    __HAL_TIM_SET_COUNTER(&htim11, 0);
    HAL_Delay(length_ms * 19 / 20);
    TIM->CCR1 = 0;
    HAL_Delay(length_ms / 20);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
