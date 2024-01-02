/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-02 16:33:45
 * @FilePath: /nest/src/app/common/config.h
 * @Description:
 *
 * Copyright (c) 2023 自动化研究所广东人工智能与先进计算研究院, 版权所有
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

struct Config {
    std::string sn;          // 机巢序列
    std::string mqtt_broker; // mqtt代理地址
};
#endif // __CONFIG_H__