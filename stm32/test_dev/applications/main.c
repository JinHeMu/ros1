/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-11-30     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "serial.h"


rt_device_t uart3_dev;
rt_err_t ret;
struct serial_configure u3_configs = RT_SERIAL_CONFIG_DEFAULT;

int main(int argc, char **argv) {
    uart3_dev = rt_device_find("uart3");
    if(uart3_dev == RT_NULL)
    {
        LOG_E("rt_device_find[uart2] faild...\n");
        return -3;
    }

    ret = rt_device_open(uart3_dev, RT_DEVICE_OFLAG_RDWR);
    if(ret < 0)
    {
        LOG_E("rt_device_open[uart2] faild...\n");
        return ret;
    }

    rt_device_control(uart3_dev, RT_DEVICE_CTRL_CONFIG, (void *)&u3_configs);

    rt_device_write(uart3_dev, 0, "uart3 config", rt_strlen("uart3 config"));


    return RT_EOK;
}

























//rt_device_t dev;
//
//int main(int argc, char **argv) {
//    dev = rt_device_find("demo");
//    if (dev == RT_NULL) {
//        LOG_E("rt_device_find faild...\n");
//        return -1;
//    }
//
//
//    rt_device_init(dev);
//    rt_device_open(dev, RT_DEVICE_OFLAG_RDWR);
//    rt_device_close(dev);
//
//    return 0;
//}















//rt_device_t u2_dev;
//
//struct serial_configure u2_configs = RT_SERIAL_CONFIG_DEFAULT;
//
//int main(void)
//{
//    rt_err_t result = 0;
//    u2_dev = rt_device_find("uart2");
//    if (u2_dev == RT_NULL) {
//        LOG_E("rt_device_find[uart2] faild!!!\n");
//        return -1;
//    }
//    result = rt_device_open(u2_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);
//    if (result < 0) {
//        LOG_E("rt_device_open[uart2] faild!!!\n");
//        return result;
//    }
//
//    rt_device_control(u2_dev, RT_DEVICE_CTRL_CONFIG, (void *)&u2_configs);
//
//    rt_device_write(u2_dev, 0, "hello uart2\n", rt_strlen("hello uart2\n"));
//
//    return RT_EOK;
//}
