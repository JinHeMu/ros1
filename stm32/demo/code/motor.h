/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-28     49075       the first version
 */
#ifndef CODE_MOTOR_H_
#define CODE_MOTOR_H_

#include "main.h"

/*--------Motor_A control pins--------*/
#define PWMA1     TIM10->CCR1    //PWMA
#define PWMA2     TIM11->CCR1    //PWMA
/*------------------------------------*/

/*--------Motor_B control pins--------*/
#define PWMB1     TIM9->CCR1     //PWMB
#define PWMB2     TIM9->CCR2     //PWMB

/*------------------------------------*/

/*--------Motor_C control pins--------*/
#define PWMC1     TIM1->CCR2     //PWMC
#define PWMC2     TIM1->CCR1     //PWMC

/*------------------------------------*/

/*--------Motor_D control pins--------*/
#define PWMD1     TIM1->CCR4     //PWMD
#define PWMD2     TIM1->CCR3     //PWMD

//Motor speed control related parameters of the structure
//电机速度控制相关参数结构�?
typedef struct
{
    float Speed;     //Read the real time speed of the motor by encoder //编码器数值，读取电机实时速度
    float Motor_Pwm;   //Motor PWM value, control the real-time speed of the motor //电机PWM数�?�，控制电机实时速度
    float Target;      //Control the target speed of the motor //电机目标速度值，控制电机目标速度
}Motor_parameter;


//Smoothed the speed of the three axes
//平滑处理后的三轴速度
typedef struct
{
    float VX;
    float VY;
    float VZ;
}Smooth_Control;


typedef struct
{
    float SpeedX;
    float SpeedY;
    float SpeedZ;
}Move_Speed;


typedef struct
{
  int A;
  int B;
  int C;
  int D;
}Encoder;

extern Motor_parameter Motor_A,Motor_B,Motor_C,Motor_D;
extern Move_Speed Mec_Car;



void Motor_Init(void);
void Set_Pwm(int motor_a,int motor_b,int motor_c,int motor_d);
int Incremental_PI_A (float Encoder,float Target);
int Incremental_PI_B (float Encoder,float Target);
int Incremental_PI_C (float Encoder,float Target);
int Incremental_PI_D (float Encoder,float Target);
void Drive_Motor(float Vx,float Vy,float Vz);


#endif /* CODE_MOTOR_H_ */
