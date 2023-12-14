/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 14:13:19
 * @FilePath: /cpp_demo/src/app/common/config.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#include "config.h"
#include "json.hpp"

#include <fstream>
#include <stdexcept>

using Json = nlohmann::json;

Config::Config(const std::string &file_name) {
    Json config;
    std::ifstream ifs(file_name);
    try {
        ifs >> config;
        manifest_.pkg_name = config.at("manifest").at("pkg_name");
        manifest_.app_name = config.at("manifest").at("app_name");
        manifest_.service = config.at("manifest").at("service");
        manifest_.version = config.at("manifest").at("version");
        manifest_.arch = config.at("manifest").at("arch");
        manifest_.platform = config.at("manifest").at("platform");
        manifest_.pkg_name = config.at("manifest").at("pkg_name");
        manifest_.build_date = config.at("manifest").at("build_date");
        manifest_.git_hash = config.at("manifest").at("git_hash");
        manifest_.description = config.at("manifest").at("description");
    } catch (...) {
        throw std::runtime_error("load config failed");
    }
}

const auto Config::get_manifest_config() -> Config::Manifest & { return manifest_; }