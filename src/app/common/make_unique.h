/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-10-16 15:59:55
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:19:56
 * @FilePath: /cpp_demo/src/app/common/make_unique.h
 * @Description: 
 * 
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __MAKE_UNIQUE_H__
#define __MAKE_UNIQUE_H__

#include <memory>

#if __cplusplus >= 201402L
// 如果支持C++14，则使用标准库中的std::make_unique
#else
// 如果不支持C++14，则使用手动实现的make_unique
namespace std {
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
} // namespace std
#endif
#endif // __MAKE_UNIQUE_H__