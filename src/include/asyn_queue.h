#ifndef __ASYN_QUEUE_H__
#define __ASYN_QUEUE_H__

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
 * @brief 异步日志队列
 */

namespace morpc
{
    template <class T>
    class AsynQueue
    {
    public:
        void Push(const T &data)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(data);
            condition_.notify_one();
        }

        T Pop()
        {
            std::unique_lock<std::mutex> lock(mutex_);
            while (queue_.empty())
            {
                condition_.wait(lock);
            }
            T data = queue_.front();
            queue_.pop();

            return data;
        }

    private:
        std::queue<T> queue_;
        std::mutex mutex_;
        std::condition_variable condition_;
    };
}

#endif