#include <code/timer_pit.h>
/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-27     49075       the first version
 */


rt_timer_t Timer1;


void timer1_pit_entry(void *parameter)
{

    Get_Velocity_Form_Encoder();
    Drive_Motor(Mec_Car.SpeedX,Mec_Car.SpeedY,Mec_Car.SpeedZ);



}


void Timer1_Init(void)
{


    //创建一个定时器 周期运行
    Timer1 = rt_timer_create("Timer1", timer1_pit_entry,RT_NULL, 10, RT_TIMER_FLAG_PERIODIC);
    //启动定时器
    if(RT_NULL != Timer1)
    {
        rt_timer_start(Timer1);
    }


}

