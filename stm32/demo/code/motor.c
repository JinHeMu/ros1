/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-28     49075       the first version
 */

#include <code/motor.h>

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim9;
TIM_HandleTypeDef htim10;
TIM_HandleTypeDef htim11;

//Smooth control of intermediate variables, dedicated to omni-directional moving cars
//平滑控制中间变量，全向移动小车专用
Smooth_Control smooth_control;

Move_Speed Mec_Car;


//The parameter structure of the motor
//电机的参数结构体
Motor_parameter Motor_A,Motor_B,Motor_C,Motor_D;
float Velocity_KP=300,Velocity_KI=300;


void PWM_TIM1_Init(void)
{

    /* USER CODE BEGIN TIM1_Init 0 */

    /* USER CODE END TIM1_Init 0 */

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

    /* USER CODE BEGIN TIM1_Init 1 */

    /* USER CODE END TIM1_Init 1 */
    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 0;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 7200-1;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
    {
      Error_Handler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
    {
      Error_Handler();
    }
    if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
    {
      Error_Handler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
    {
      Error_Handler();
    }
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 0;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
    {
      Error_Handler();
    }
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
    {
      Error_Handler();
    }
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
    {
      Error_Handler();
    }
    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
    {
      Error_Handler();
    }
    sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
    sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
    sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
    sBreakDeadTimeConfig.DeadTime = 0;
    sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
    sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
    sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
    if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
    {
      Error_Handler();
    }
    /* USER CODE BEGIN TIM1_Init 2 */

    /* USER CODE END TIM1_Init 2 */
    HAL_TIM_MspPostInit(&htim1);


}

void PWM_TIM9_Init(void)
{

  /* USER CODE BEGIN TIM9_Init 0 */

  /* USER CODE END TIM9_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM9_Init 1 */

  /* USER CODE END TIM9_Init 1 */
  htim9.Instance = TIM9;
  htim9.Init.Prescaler = 0;
  htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim9.Init.Period = 7200-1;
  htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim9.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim9) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM9_Init 2 */

  /* USER CODE END TIM9_Init 2 */
  HAL_TIM_MspPostInit(&htim9);

}

/**
  * @brief TIM10 Initialization Function
  * @param None
  * @retval None
  */
void PWM_TIM10_Init(void)
{

  /* USER CODE BEGIN TIM10_Init 0 */

  /* USER CODE END TIM10_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM10_Init 1 */

  /* USER CODE END TIM10_Init 1 */
  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 0;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 7200-1;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim10) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim10, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM10_Init 2 */

  /* USER CODE END TIM10_Init 2 */
  HAL_TIM_MspPostInit(&htim10);

}

/**
  * @brief TIM11 Initialization Function
  * @param None
  * @retval None
  */
void PWM_TIM11_Init(void)
{

  /* USER CODE BEGIN TIM11_Init 0 */

  /* USER CODE END TIM11_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM11_Init 1 */

  /* USER CODE END TIM11_Init 1 */
  htim11.Instance = TIM11;
  htim11.Init.Prescaler = 0;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = 7200-1;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim11, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM11_Init 2 */

  /* USER CODE END TIM11_Init 2 */
  HAL_TIM_MspPostInit(&htim11);

}





float Target_Limit_Float(float insert,float low,float high)
{
    if (insert < low)
        return low;
    else if (insert > high)
        return high;
    else
        return insert;
}
int Target_Limit_Int(int insert,int low,int high)
{
    if (insert < low)
        return low;
    else if (insert > high)
        return high;
    else
        return insert;
}


float float_abs(float insert)
{
    if(insert>=0) return insert;
    else return -insert;
}

/**************************************************************************
Function: Smoothing the three axis target velocity
Input   : Three-axis target velocity
Output  : none
函数功能：对三轴目标速度做平滑处理
入口参数：三轴目标速度
返回  值：无
**************************************************************************/
void Smooth_control(float vx,float vy,float vz)
{
    float step=0.01;

    if     (vx>0)   smooth_control.VX+=step;
    else if(vx<0)       smooth_control.VX-=step;
    else if(vx==0)  smooth_control.VX=smooth_control.VX*0.9f;

    if     (vy>0)   smooth_control.VY+=step;
    else if(vy<0)       smooth_control.VY-=step;
    else if(vy==0)  smooth_control.VY=smooth_control.VY*0.9f;

    if     (vz>0)   smooth_control.VZ+=step;
    else if(vz<0)       smooth_control.VZ-=step;
    else if(vz==0)  smooth_control.VZ=smooth_control.VZ*0.9f;

    smooth_control.VX=Target_Limit_Float(smooth_control.VX,-float_abs(vx),float_abs(vx));
    smooth_control.VY=Target_Limit_Float(smooth_control.VY,-float_abs(vy),float_abs(vy));
    smooth_control.VZ=Target_Limit_Float(smooth_control.VZ,-float_abs(vz),float_abs(vz));
}




/**************************************************************************
Function: The inverse kinematics solution is used to calculate the target speed of each wheel according to the target speed of three axes
Input   : X and Y, Z axis direction of the target movement speed
Output  : none
函数功能：运动学逆解，根据三轴目标速度计算各车轮目标转速
入口参数：X和Y、Z轴方向的目标运动速度
返回  值：无
**************************************************************************/
void Drive_Motor(float Vx,float Vy,float Vz)
{
    float amplitude=0.5; //Wheel target speed limit //车轮目标速度限幅


    Smooth_control(Vx,Vy,Vz); //Smoothing the input speed //对输入速度进行平滑处理

    //获取平滑处理后的数据
    Vx=smooth_control.VX;
    Vy=smooth_control.VY;
    Vz=smooth_control.VZ;

    //Inverse kinematics //运动学逆解
    Motor_A.Target   = +Vy+Vx-Vz*(MEC_wheelspacing+MEC_axlespacing);
    Motor_B.Target   = -Vy+Vx-Vz*(MEC_wheelspacing+MEC_axlespacing);
    Motor_C.Target   = +Vy+Vx+Vz*(MEC_wheelspacing+MEC_axlespacing);
    Motor_D.Target   = -Vy+Vx+Vz*(MEC_wheelspacing+MEC_axlespacing);

    //Wheel (Motor) target speed limit //车轮(电机)目标速度限幅
    Motor_A.Target=Target_Limit_Float(Motor_A.Target,-amplitude,amplitude);
    Motor_B.Target=Target_Limit_Float(Motor_B.Target,-amplitude,amplitude);
    Motor_C.Target=Target_Limit_Float(Motor_C.Target,-amplitude,amplitude);
    Motor_D.Target=Target_Limit_Float(Motor_D.Target,-amplitude,amplitude);


    Motor_A.Motor_Pwm=Incremental_PI_A(Motor_A.Speed, Motor_A.Target);
    Motor_B.Motor_Pwm=Incremental_PI_B(Motor_B.Speed, Motor_B.Target);
    Motor_C.Motor_Pwm=Incremental_PI_C(Motor_C.Speed, Motor_C.Target);
    Motor_D.Motor_Pwm=Incremental_PI_D(Motor_D.Speed, Motor_D.Target);

//
//    rt_kprintf("encoderA:%d\t", (int)(Motor_A.Speed*100));
//    rt_kprintf("Motor_Pwm:%d\n", (int)(Motor_A.Motor_Pwm));
    Set_Pwm(Motor_A.Motor_Pwm,  -Motor_B.Motor_Pwm, -Motor_C.Motor_Pwm, Motor_D.Motor_Pwm);

}







int Incremental_PI_A (float Encoder,float Target)
{
     static float Bias,Pwm,Last_bias;
     Bias=Target-Encoder; //Calculate the deviation //计算偏差
     Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;
     if(Pwm>7199)Pwm=7199;
     if(Pwm<-7199)Pwm=-7199;
     Last_bias=Bias; //Save the last deviation //保存上一次偏差
     return Pwm;
}
int Incremental_PI_B (float Encoder,float Target)
{
     static float Bias,Pwm,Last_bias;
     Bias=Target-Encoder; //Calculate the deviation //计算偏差
     Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;
     if(Pwm>7199)Pwm=7199;
     if(Pwm<-7199)Pwm=-7199;
     Last_bias=Bias; //Save the last deviation //保存上一次偏差
     return Pwm;
}
int Incremental_PI_C (float Encoder,float Target)
{
     static float Bias,Pwm,Last_bias;
     Bias=Target-Encoder; //Calculate the deviation //计算偏差
     Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;
     if(Pwm>7199)Pwm=7199;
     if(Pwm<-7199)Pwm=-7199;
     Last_bias=Bias; //Save the last deviation //保存上一次偏差
     return Pwm;
}
int Incremental_PI_D (float Encoder,float Target)
{
     static float Bias,Pwm,Last_bias;
     Bias=Target-Encoder; //Calculate the deviation //计算偏差
     Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;
     if(Pwm>7199)Pwm=7199;
     if(Pwm<-7199)Pwm=-7199;
     Last_bias=Bias; //Save the last deviation //保存上一次偏差
     return Pwm;
}



void Set_Pwm(int motor_a,int motor_b,int motor_c,int motor_d)
{
    //Forward and reverse control of motor
    //电机正反转控制
    if(motor_a<0)           PWMA1=7199,PWMA2=7199+motor_a;
    else                PWMA2=7199,PWMA1=7199-motor_a;

    //Forward and reverse control of motor
    //电机正反转控制
    if(motor_b<0)           PWMB1=7199,PWMB2=7199+motor_b;
    else                PWMB2=7199,PWMB1=7199-motor_b;

    //Forward and reverse control of motor
    //电机正反转控制
    if(motor_c<0)           PWMC1=7199,PWMC2=7199+motor_c;
    else                PWMC2=7199,PWMC1=7199-motor_c;

    //Forward and reverse control of motor
    //电机正反转控制
    if(motor_d<0)           PWMD1=7199,PWMD2=7199+motor_d;
    else                PWMD2=7199,PWMD1=7199-motor_d;
}


void Motor_Init(void)
{
    PWM_TIM1_Init();
    PWM_TIM9_Init();
    PWM_TIM10_Init();
    PWM_TIM11_Init();

   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);//不能用ALL
   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
   HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

   HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
   HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_2);
   HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);
   HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);



}
