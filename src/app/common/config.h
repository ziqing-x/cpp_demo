/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:19:47
 * @FilePath: /cpp_demo/src/app/common/config.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "singleton.h"

#include <string>

#define CONFIG_FILE_PATH "./config/app.conf"

class Config {
public:
    struct Manifest {
        std::string pkg_name;
        std::string app_name;
        std::string service;
        std::string version;
        std::string arch;
        std::string platform;
        std::string build_date;
        std::string git_hash;
        std::string description;
    };

private:
    Manifest manifest_;

public:
    Config(const std::string &file_name);
    const auto get_manifest_config() -> Manifest &;
};

#define CONFIG Singleton<Config>::instance(CONFIG_FILE_PATH)
#endif // __CONFIG_H__