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
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "led.h"
#include "lcd.h"
#include "button.h"

#include "fan.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  // GPIO pin specifications for buttons and LEDs
  GPIO_TypeDef *button_GPIOx[4] = {GPIOB, GPIOB, GPIOB, GPIOB};
  uint16_t button_GPIO_Pin[4] = {
          GPIO_PIN_1, GPIO_PIN_15, GPIO_PIN_14, GPIO_PIN_13
  };

  GPIO_TypeDef *led_GPIOx[3] = {GPIOA, GPIOA, GPIOB};
  uint16_t led_GPIO_Pin[3] = {GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_6};
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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  // Declare and initialize buttons/LEDs/fan structures
  // initialize LCD
  Button button_stop;
  Button button_speed1, button_speed2, button_speed3;

  button_init(&button_stop, button_GPIOx[0], button_GPIO_Pin[0]);
  button_init(&button_speed1, button_GPIOx[1], button_GPIO_Pin[1]);
  button_init(&button_speed2, button_GPIOx[2], button_GPIO_Pin[2]);
  button_init(&button_speed3, button_GPIOx[3], button_GPIO_Pin[3]);


  LED led_speed1, led_speed2, led_speed3;

  led_init(&led_speed1, led_GPIOx[0], led_GPIO_Pin[0]);
  led_init(&led_speed2, led_GPIOx[1], led_GPIO_Pin[1]);
  led_init(&led_speed3, led_GPIOx[2], led_GPIO_Pin[2]);


  LCD_init();
  LCD_send_str("Stopped");


  Fan fan;

  fan_init(&fan, &htim11, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	// Detect 'button push' for each button and do the corresponding directives
    if (button_getAction(&button_stop) == ACT_PUSH) {
    	// Turn the fan off
        fan_changeSpeed(&fan, 0.);

        // Turn the LEDs off
        led_off(&led_speed1);
        led_off(&led_speed2);
        led_off(&led_speed3);

        // Display 'Stopped'
        LCD_put_cursor(0, 0);
        LCD_send_str("Stopped");
    }
    if (button_getAction(&button_speed1) == ACT_PUSH) {
    	// Turn the fan on at speed 1
        fan_changeSpeed(&fan, 0.65);

        // Turn on only the LED indicating speed 1
        led_off(&led_speed2);
        led_off(&led_speed3);
        led_on(&led_speed1);

        // Display 'Speed 1'
        LCD_put_cursor(0, 0);
        LCD_send_str("Speed 1");
    }
    if (button_getAction(&button_speed2) == ACT_PUSH) {
    	// Turn the fan on at speed 2
        fan_changeSpeed(&fan, 0.82);

        // Turn on only the LED indicating speed 2
        led_off(&led_speed1);
        led_off(&led_speed3);
        led_on(&led_speed2);

        // Display 'Speed 2'
        LCD_put_cursor(0, 0);
        LCD_send_str("Speed 2");
    }
    if (button_getAction(&button_speed3) == ACT_PUSH) {
    	// Turn the fan on at speed 3
        fan_changeSpeed(&fan, 1.);

        // Turn on only the LED indicating speed 3
        led_off(&led_speed1);
        led_off(&led_speed2);
        led_on(&led_speed3);

        // Display 'Speed 3'
        LCD_put_cursor(0, 0);
        LCD_send_str("Speed 3");
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
