/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-12-01     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#include "main.h"
#include "serial.h"


void GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}




rt_device_t uart2_dev;
rt_err_t ret;
struct serial_configure u2_configs = RT_SERIAL_CONFIG_DEFAULT;

int main(int argc, char **argv) {
    uart2_dev = rt_device_find("uart2");
    if(uart2_dev == RT_NULL)
    {
        LOG_E("rt_device_find[uart2] faild...\n");
        return -2;
    }

    ret = rt_device_open(uart2_dev, RT_DEVICE_OFLAG_RDWR);
    if(ret < 0)
    {
        LOG_E("rt_device_open[uart2] faild...\n");
        return ret;
    }

    rt_device_control(uart2_dev, RT_DEVICE_CTRL_CONFIG, (void *)&u2_configs);

    rt_device_write(uart2_dev, 0, "uart2 config\n", rt_strlen("uart2 config\n"));


    return RT_EOK;
}
