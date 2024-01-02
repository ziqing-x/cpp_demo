/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-08-11 18:22:07
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2024-01-02 17:33:57
 * @FilePath: /cpp_demo/src/app/common/thread_safe_queue.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */
#ifndef __THREAD_SAFE_QUEUE_H__
#define __THREAD_SAFE_QUEUE_H__

#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <queue>

template <typename T>
class ThreadSafeQueue {
private:
    int cap_;                    // 容量
    bool is_stop_;               // 用于唤醒等待, 退出线程
    std::mutex mutex_;           // 互斥锁，保证对队列的访问是线程安全的
    std::queue<T> queue_;        // 存储数据的队列
    std::condition_variable cv_; // 条件变量，用于实现线程间的同步
public:
    ThreadSafeQueue(int cap = 1000) : cap_(cap), is_stop_(false) {}
    void push(T value) {
        std::lock_guard<std::mutex> glck(mutex_);
        if (queue_.size() < cap_ && !is_stop_) {
            queue_.push(std::move(value));
        } else {
            std::cout << "queue is full" << std::endl;
        }
        cv_.notify_one(); // 通知等待在条件变量上的线程
    }

    /**
     * @description: 阻塞等待一个数据
     * @return {*}
     */
    const T &front() {
        std::unique_lock<std::mutex> ulck(mutex_);
        // 使用while循环等待队列不为空
        // 防止虚假唤醒（spurious wakeup）
        // 当多个线程等待在条件变量上时，一个线程被唤醒后可能发现队列为空，
        // 所以需要循环检查队列是否为空
        while (queue_.empty() && !is_stop_) {
            cv_.wait(ulck,
                     [this]() { return !queue_.empty() || is_stop_; }); // 阻塞当前线程，并释放锁
        }
        if (is_stop_) {
            return {};
        }
        return queue_.front();
    }

    void pop() {
        std::lock_guard<std::mutex> glck(mutex_);
        if (!queue_.empty() && !is_stop_) {
            queue_.pop();
        }
    }

    void end_wait() {
        std::lock_guard<std::mutex> glck(mutex_);
        is_stop_ = true;
        cv_.notify_all();
    }

    void reset() {
        std::lock_guard<std::mutex> glck(mutex_);
        queue_.clear();
    }
};
#endif // __THREAD_SAFE_QUEUE_H__