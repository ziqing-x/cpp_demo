/*
 * @Author: xiongyi jassimxiong@gmail.com
 * @Date: 2023-12-27 17:26:3
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-03 15:11:39
 * @FilePath: /cpp_demo/src/app/manager/manifest_manager.cpp
 * @Description:
 *
 * Copyright (c) 2023 广东人工智能与先进计算研究院, 版权所有
 */
#include "manifest_manager.h"
#include "json.hpp"

#include <fstream>
#include <stdexcept>

#define CONFIG_PATH "./manifest.info"

using Json = nlohmann::json;
ManifestManager::ManifestManager()
{
    Json manifest;
    std::ifstream ifs(CONFIG_PATH);
    try
    {
        ifs >> manifest;
        manifest_.pkg_name = manifest.at("pkg_name");
        manifest_.app_name = manifest.at("app_name");
        manifest_.service = manifest.at("service");
        manifest_.version = manifest.at("version");
        manifest_.arch = manifest.at("arch");
        manifest_.platform = manifest.at("platform");
        manifest_.build_date = manifest.at("build_date");
        manifest_.git_hash = manifest.at("git_hash");
        manifest_.description = manifest.at("description");
    }
    catch (...)
    {
        throw std::runtime_error("load manifest failed");
    }
}
ManifestManager::~ManifestManager() {}
auto ManifestManager::get_manifest() const -> const Manifest &
{
    return manifest_;
}