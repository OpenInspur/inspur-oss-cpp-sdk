
#pragma once

#include <atomic>
#include <condition_variable>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <unordered_map>

namespace InspurCloud
{
namespace OSS
{
    class Runnable;
    class Executor
    {
    public:
        Executor();
        ~Executor();
        void execute(Runnable* task);
    private:
        enum class State
        {
            Free, Locked, Shutdown
        };
        void detach(std::thread::id id);
        std::atomic<State> state_;
        std::unordered_map<std::thread::id, std::thread> threads_;
    };
}
}
