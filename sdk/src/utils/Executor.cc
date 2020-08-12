
#include "Executor.h"
#include <inspurcloud/oss/utils/Runnable.h>
#include <assert.h>
#include "../utils/LogUtils.h"

using namespace InspurCloud::OSS;

static const char *TAG = "Executor";

Executor::Executor():
    state_(State::Free)
{
}

Executor::~Executor()
{
    auto expected = State::Free;
    while (!state_.compare_exchange_strong(expected, State::Shutdown))
    {
        assert(expected == State::Locked);
        expected = State::Free;
    }

    auto it = threads_.begin();
    while (!threads_.empty())
    {
        it->second.join();
        it = threads_.erase(it);
    }
}

void Executor::execute(Runnable* task)
{
    auto main = [task, this] {
        OSS_LOG(LogLevel::LogDebug, TAG, "task(%p) enter execute main thread", task);
        task->run();
        delete task;
        detach(std::this_thread::get_id());
        OSS_LOG(LogLevel::LogDebug, TAG, "task(%p) leave execute main thread", task);
    };

    State expected;
    do
    {
        expected = State::Free;
        if (state_.compare_exchange_strong(expected, State::Locked))
        {
            std::thread t(main);
            const auto id = t.get_id(); 
            threads_.emplace(id, std::move(t));
            state_ = State::Free;
            return;
        }
    } while (expected != State::Shutdown);
    return;
}

void Executor::detach(std::thread::id id)
{
    State expected;
    do
    {
        expected = State::Free;
        if (state_.compare_exchange_strong(expected, State::Locked))
        {
            auto it = threads_.find(id);
            assert(it != threads_.end());
            it->second.detach();
            threads_.erase(it);
            state_ = State::Free;
            return;
        }
    } while (expected != State::Shutdown);
}