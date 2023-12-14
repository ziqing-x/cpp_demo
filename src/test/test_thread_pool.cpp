/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-08-14 11:15:16
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:27:16
 * @FilePath: /cpp_demo/src/test/test_thread_pool.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#include "doctest.h"
#include "thread_pool.h"

#include <iostream>
#include <string>

static std::string task(const std::string &hello) { return hello; }

TEST_SUITE("线程池") {
    TEST_CASE("线程池::提交任务") {
        ThreadPool tasks(4);
        auto ret1 = tasks.submit(task, "你好");
        std::cout << ret1.get() << std::endl;

        auto ret2 = tasks.submit([]() -> std::string { return "I am Lamda"; });
        std::cout << ret2.get() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
