/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 16:10:00
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-27 16:24:48
 * @FilePath: /nest/src/app/common/manifest.h
 * @Description:
 *
 * Copyright (c) 2023 中国科学院自动化研究所广东人工智能与先进计算研究院, 版权所有
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