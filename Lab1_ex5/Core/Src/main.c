/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
enum _2WaysState {
      	RED1_GREEN2,
		RED1_YELLOW2,
		RED2_GREEN1,
		RED2_YELLOW1,
  };
  enum LightState {
	  RED1,
	  GREEN1,
	  YELLOW1,
	  RED2,
	  GREEN2,
	  YELLOW2
  };
  int counter = 3;
  int light_1 = 5;
  int light_2 = 3;
    enum _2WaysState finiteState = RED1_GREEN2;
    void lightState(enum LightState light) {
  	  switch(light) {
  	  case RED1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 1);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 0);
  		  break;
  	  case GREEN1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 1);
  		  break;
  	  case YELLOW1:
  		  HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_1_GPIO_Port, YEL_1_Pin, 1);
  		  HAL_GPIO_WritePin(GRE_1_GPIO_Port, GRE_1_Pin, 0);
  		  break;
  	  case RED2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 1);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 0);
  		  break;
  	  case GREEN2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 0);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 1);
  		  break;
  	  case YELLOW2:
  		  HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, 0);
  		  HAL_GPIO_WritePin(YEL_2_GPIO_Port, YEL_2_Pin, 1);
  		  HAL_GPIO_WritePin(GRE_2_GPIO_Port, GRE_2_Pin, 0);
  		  break;
  	  }
    }
void display7SEG_1(int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 1);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 1);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 1);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 1);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 1);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 1);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 1);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 1);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 0);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 0);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 0);
			HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 0);
			HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 0);
			HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 0);
			HAL_GPIO_WritePin(S7_GPIO_Port, S7_Pin, 0);
			break;

	}
}
void display7SEG_2(int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 0);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 1);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 1);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 0);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 1);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 1);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 1);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 0);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 1);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 1);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 0);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		case 9:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 1);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
			HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
			HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
			HAL_GPIO_WritePin(E4_GPIO_Port, E4_Pin, 0);
			HAL_GPIO_WritePin(E5_GPIO_Port, E5_Pin, 0);
			HAL_GPIO_WritePin(E6_GPIO_Port, E6_Pin, 0);
			HAL_GPIO_WritePin(E7_GPIO_Port, E7_Pin, 0);
			break;

	}
}
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
    {

  	  display7SEG_1(light_1);
  	  display7SEG_2(light_2);
  	  switch (finiteState) {
  	  case RED1_GREEN2:
  		  lightState(RED1);
  		  lightState(GREEN2);
  		  if(counter == 0) {
  			  finiteState = RED1_YELLOW2;
  			  counter = 2;
  			  light_2 = 2;
  		  }
  		  break;
  	  case RED1_YELLOW2:
  		  lightState(RED1);
  		  lightState(YELLOW2);
  		  if(counter == 0) {
  			  finiteState = RED2_GREEN1;
  			  counter = 3;
  			  light_1 = 3;
  			  light_2 = 5;
  		  }
  		  break;
  	  case RED2_GREEN1:
  		  lightState(RED2);
  		  lightState(GREEN1);
  		  if(counter == 0) {
  			  finiteState = RED2_YELLOW1;
  			  counter = 2;
  			  light_1 = 2;
  		  }
  		  break;
  	  case RED2_YELLOW1:
  		  lightState(RED2);
  		  lightState(YELLOW1);
  		  if(counter == 0) {
  			  finiteState = RED1_GREEN2;
  			  counter = 3;
  			  light_1 = 5;
  			  light_2 = 3;
  		  }
  		  break;
  	  }
  	  HAL_Delay(1000);
  	  counter--;
  	  light_1--;
  	  light_2--;
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_2_Pin|YEL_2_Pin|GRE_2_Pin|RED_1_Pin
                          |YEL_1_Pin|GRE_1_Pin|E2_Pin|E3_Pin
                          |E4_Pin|E5_Pin|E6_Pin|E7_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin|S7_Pin|E1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : RED_2_Pin YEL_2_Pin GRE_2_Pin RED_1_Pin
                           YEL_1_Pin GRE_1_Pin E2_Pin E3_Pin
                           E4_Pin E5_Pin E6_Pin E7_Pin */
  GPIO_InitStruct.Pin = RED_2_Pin|YEL_2_Pin|GRE_2_Pin|RED_1_Pin
                          |YEL_1_Pin|GRE_1_Pin|E2_Pin|E3_Pin
                          |E4_Pin|E5_Pin|E6_Pin|E7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S1_Pin S2_Pin S3_Pin S4_Pin
                           S5_Pin S6_Pin S7_Pin E1_Pin */
  GPIO_InitStruct.Pin = S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin|S7_Pin|E1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
