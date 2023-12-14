/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-07-14 11:15:16
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:28:04
 * @FilePath: /cpp_demo/src/test/test_singleton.cpp
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */

#include "doctest.h"
#include "singleton.h"

#include <stdio.h>
#include <type_traits>
#include <unistd.h>

class MyClass {
public:
    MyClass() {}
    MyClass(const MyClass &) = delete;
    MyClass &operator=(const MyClass &) = delete;
};
TEST_SUITE("单例模板") {
    TEST_CASE("单例模板::返回一个单例") {
        auto &instance1 = Singleton<MyClass>::instance();
        auto &instance2 = Singleton<MyClass>::instance();
        CHECK(&instance1 == &instance2);
    }

    TEST_CASE("单例模板::禁止拷贝构造") {
        CHECK(std::is_copy_constructible<Singleton<MyClass>>::value == false);
        CHECK(std::is_copy_assignable<Singleton<MyClass>>::value == false);
    }
}