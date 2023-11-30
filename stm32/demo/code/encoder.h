/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-27     49075       the first version
 */
#ifndef CODE_ENCODER_H_
#define CODE_ENCODER_H_




#include "main.h"

void Encoder_Init(void);
short Read_Encoder(uint8_t TIMX);
void Get_Velocity_Form_Encoder(void);


#endif /* HARDWARE_ENCODER_ENCODER_H_ */
