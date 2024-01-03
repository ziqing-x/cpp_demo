/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-03 15:10:24
 * @FilePath: /cpp_demo/src/app/manager/config_manager.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#include "config_manager.h"
#include "json.hpp"

#include <fstream>
#include <stdexcept>

#define CONFIG_PATH "./config/app.conf"

using Json = nlohmann::json;

ConfigManager::ConfigManager() {
    Json config;
    std::ifstream ifs(CONFIG_PATH);
    try {
        ifs >> config;
        config_.mqtt_broker = config.at("mqtt_broker");
    } catch (...) {
        throw std::runtime_error("Failed to load configuration");
    }
}

auto ConfigManager::get_config() const -> const Config & { return config_; }
