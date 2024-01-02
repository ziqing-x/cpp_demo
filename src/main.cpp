/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-17 12:24:06
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-02 17:36:47
 * @FilePath: /cpp_demo/src/main.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#include "application.h"
#include "logger.h"
#include "manifest_manager.h"
#include "singleton.h"

#define BLUE "\033[;34m"  // 蓝色
#define GREE "\033[;32m"  // 绿色
#define YELL "\033[;33m"  // 黄色
#define PURP "\033[;35m"  // 紫色
#define RESET "\033[0m\n" // 结束

void print_info() {
    auto &manifest = Singleton<ManifestManager>::instance().get_manifest();
    // clang-format off
    LOGI("\n"
        GREE "                   __                              " RESET
        GREE "              ____/ /__  ____ ___  ____            " RESET     
        GREE "             / __  / _ \\/ __ `__ \\/ __ \\           " RESET
        GREE "            / /_/ /  __/ / / / / / /_/ /           " RESET
        GREE "            \\__,_/\\___/_/ /_/ /_/\\____/            " RESET  
        BLUE "╭───────────────────────────────────────────────── " RESET
        BLUE "│ app_name    : {}                                 " RESET
        BLUE "│ pkg_name    : {}                                 " RESET
        BLUE "│ service     : {}                                 " RESET
        BLUE "│ version     : {}                                 " RESET
        BLUE "│ arch        : {}                                 " RESET
        BLUE "│ platform    : {}                                 " RESET
        BLUE "│ build_date  : {}                                 " RESET
        BLUE "│ git_hash    : {}                                 " RESET
        BLUE "│ description : {}                                 " RESET
        BLUE "╰───────────────────────────────────────────────── " RESET,
        manifest.app_name,
        manifest.pkg_name,
        manifest.service,
        manifest.version,
        manifest.arch,
        manifest.platform,
        manifest.build_date,
        manifest.git_hash,
        manifest.description);
    // clang-format on
}

int main(int argc, char *argv[]) {
    Application app;

    print_info();
    if (!app.start()) {
        LOGE("Application start failed");
        return -1;
    }
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
