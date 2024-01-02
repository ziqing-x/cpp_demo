/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-02 16:35:16
 * @FilePath: /nest/src/app/manager/config_manager.cpp
 * @Description:
 *
 * Copyright (c) 2023 中国科学院自动化研究所广东人工智能与先进计算研究院, 版权所有
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
        config_.sn = config.at("sn");
        config_.mqtt_broker = config.at("mqtt_broker");
    } catch (...) {
        throw std::runtime_error("Failed to load configuration");
    }
}

auto ConfigManager::get_config() const -> const Config & { return config_; }
