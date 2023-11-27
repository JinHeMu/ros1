/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-27     49075       the first version
 */
#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "main.h"

void Encoder_TIM2_Init(void);
int Read_Encoder(uint8_t TIMX);


#endif /* HARDWARE_ENCODER_ENCODER_H_ */
