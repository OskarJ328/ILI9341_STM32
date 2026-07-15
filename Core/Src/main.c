/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "fonts.h"
#include "images.h"
#include "my_delay.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ili9341.h"
#include <iso646.h>
#include <stdint.h>
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
ili9341_t ili = {
  .csPort = CS_GPIO_Port,
  .csPin = CS_Pin,
  .resPort = RESET_GPIO_Port,
  .resPin = RESET_Pin,
  .dcPort = DC_GPIO_Port,
  .dcPin = DC_Pin,
  .spiHandle = &hspi1,
  .height = ILI9341_HEIGHT,
  .width = ILI9341_WIDTH,
  .colorFormat = BGR
};


#define HEART_WIDTH 16
#define HEART_HEIGHT 16


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
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  uint16_t TS_x = 20;
  uint16_t JK_x = 20;
  uint16_t SC_x = 20;
  uint16_t TS_y = 10;
  uint16_t JK_y = TS_y + TS60x60.Height + 10;
  uint16_t SC_y = JK_y + JK60x68.Height + 10;
  ILI9341_init(&ili);
  myDelay(1000);
  ILI9341_swapAxes(&ili);
  ILI9341_invertAxis(&ili, invertBoth);
  //char Text[] = "Twoj Stary\nLezy Najebany\nNa Wersalce";
  ILI9341_fillScreen(&ili, ILI9341_WHITE);
  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    
    for(uint16_t i = 0; i < 220; i++){
      ILI9341_drawRectangle(&ili, TS_x + i - 1, TS_y, 1, TS60x60.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, TS_x + i, TS_y, &TS60x60);
      ILI9341_drawRectangle(&ili, JK_x + i - 1, JK_y, 1, JK60x68.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, JK_x + i, JK_y, &JK60x68);
      ILI9341_drawRectangle(&ili, SC_x + i - 1, SC_y, 1, susCat60x60.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, SC_x + i, SC_y, &susCat60x60);
      myDelay(2);
    }
    for(uint16_t i = 220; i > 0; i--){
      ILI9341_drawRectangle(&ili, TS_x + i + TS60x60.Width, TS_y, 1, TS60x60.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, TS_x + i, TS_y, &TS60x60);
      ILI9341_drawRectangle(&ili, JK_x + i + JK60x68.Width, JK_y, 1, JK60x68.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, JK_x + i, JK_y, &JK60x68);
      ILI9341_drawRectangle(&ili, SC_x + i + susCat60x60.Width,  SC_y, 1, susCat60x60.Height, ILI9341_WHITE);
      ILI9341_drawImage(&ili, SC_x + i, SC_y, &susCat60x60);
      myDelay(1);
    }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
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
#ifdef USE_FULL_ASSERT
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
