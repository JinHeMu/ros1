/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "rtthread.h"
#include <code/adc.h>
#include <code/OLED/oled.h>
#include <code/encoder.h>
#include <code/motor.h>
#include <code/timer_pit.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USART3_TX_Pin GPIO_PIN_8
#define USART3_TX_GPIO_Port GPIOD
#define USART3_RX_Pin GPIO_PIN_9
#define USART3_RX_GPIO_Port GPIOD
#define OLED_RS_Pin GPIO_PIN_11
#define OLED_RS_GPIO_Port GPIOD
#define OLED_RST_Pin GPIO_PIN_12
#define OLED_RST_GPIO_Port GPIOD
#define OLED_SDIN_Pin GPIO_PIN_13
#define OLED_SDIN_GPIO_Port GPIOD
#define OLED_SCLK_Pin GPIO_PIN_14
#define OLED_SCLK_GPIO_Port GPIOD
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_0
#define KEY_GPIO_Port GPIOE
#define KEY_EXTI_IRQn EXTI0_IRQn


#define PI 3.1415f  //PI //圆周率
//编码器倍频数，取决于编码器初始化设置
#define EncoderRound  800
//编码器数据读取频率
#define CONTROL_FREQUENCY 100
//麦轮直径
#define Mecanum_75  0.075f
#define MEC_wheelspacing         0.0930 //修正2021.03.30
#define MEC_axlespacing           0.085

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
