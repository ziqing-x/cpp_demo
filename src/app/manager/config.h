/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-03 15:10:29
 * @FilePath: /cpp_demo/src/app/manager/config.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

struct Config {
    std::string mqtt_broker; // mqtt代理地址
};
#endif // __CONFIG_H__