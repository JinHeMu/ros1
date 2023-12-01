/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-30     49075       the first version
 */

#include <rtdevice.h>
#include <rtdbg.h>


/* common device interface */
rt_err_t  demo_init(rt_device_t dev){rt_kprintf("demo init...\n");return 0;}
rt_err_t  demo_open(rt_device_t dev, rt_uint16_t oflag){rt_kprintf("demo open...\n");return 0;}
rt_err_t  demo_close(rt_device_t dev){rt_kprintf("demo close...\n");return 0;}


int rt_demo_init(void)
{
    rt_device_t demo_dev;
    demo_dev = rt_device_create(RT_Device_Class_Char, 32);
    if (demo_dev == RT_NULL) {
        LOG_E("rt_device_create faild...\n");
        return -1;
    }

    demo_dev->init = demo_init;
    demo_dev->open = demo_open;
    demo_dev->close = demo_close;

    rt_device_register(demo_dev, "demo", RT_DEVICE_FLAG_RDONLY);

    return 0;
}




INIT_BOARD_EXPORT(rt_demo_init);
