/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-07-14 11:15:16
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 13:42:13
 * @FilePath: /cpp_demo/src/app/common/s.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string>

template <class T>
class Singleton {
protected:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton() = default;
    ~Singleton() = default;

public:
    template <typename... Args>
    static T &instance(Args &&...args) {
        static T instance(std::forward<Args>(args)...);
        return instance;
    }
};
#endif // __SINGLETON_H__