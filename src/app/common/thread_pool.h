/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-07-17 09:24:46
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 15:17:42
 * @FilePath: /cpp_demo/src/app/common/thread_pool.h
 * @Description:
 *
 * Copyright (c) 2023 xxx, 版权所有
 */

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool {
private:
    bool stop_;
    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex mtx_;
    std::condition_variable cv_;

public:
    explicit ThreadPool(int thread_count) : stop_(false) {
        for (int i = 0; i < thread_count; ++i) {
            workers_.emplace_back([this]() {
                for (;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> ul(mtx_);
                        cv_.wait(ul, [this]() { return stop_ || !tasks_.empty(); });
                        if (stop_ && tasks_.empty()) {
                            return;
                        }
                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    task();
                }
            });
        }
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> gl(mtx_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto &worker : workers_) {
            worker.join();
        }
    }

    template <typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
        auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::lock_guard<std::mutex> lg(mtx_);
            if (stop_) {
                throw std::runtime_error("submit on stopped ThreadPool");
            }
            tasks_.emplace([task_ptr]() { (*task_ptr)(); });
        }
        cv_.notify_one();
        return task_ptr->get_future();
    }
};

#endif // THREAD_POOL_H
