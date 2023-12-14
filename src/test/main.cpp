/*
 * @Author: xiongyi jassimxiong@gmail.com
 * @Date: 2023-12-14 15:27:48
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:29:42
 * @FilePath: /cpp_demo/src/test/main.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#include "doctest.h"

int main(int argc, char **argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);
    context.run();
    return context.shouldExit();
}