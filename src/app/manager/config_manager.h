/*
 * @Author: xiongyi jassimxiong@gmail.com
 * @Date: 2023-12-27 16:06:34
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-03 15:10:50
 * @FilePath: /cpp_demo/src/app/manager/config_manager.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__

#include "config.h"

class ConfigManager {
private:
    Config config_;

public:
    ConfigManager();
    auto get_config() const -> const Config &;
};

#endif // __CONFIG_MANAGER_H__