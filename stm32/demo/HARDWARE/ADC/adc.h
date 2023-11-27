/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-25     49075       the first version
 */
#ifndef __ADC_H__
#define __ADC_H__


#include "main.h"

extern ADC_HandleTypeDef hadc1;
extern float ADC_Value;


void ADC1_Thread_Init(void);

#endif
