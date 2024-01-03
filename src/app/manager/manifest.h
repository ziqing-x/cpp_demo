/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-03 15:11:23
 * @FilePath: /cpp_demo/src/app/manager/manifest.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __MANIFEST_H__
#define __MANIFEST_H__

#include <string>

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

#endif // __MANIFEST_H__