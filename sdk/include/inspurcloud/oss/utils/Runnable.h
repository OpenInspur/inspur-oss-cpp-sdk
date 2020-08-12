
#pragma once

#include <functional>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class Runnable
    {
    public:
        explicit Runnable(const std::function<void()> f);
        void run()const;
    private:
        std::function<void()> f_;
    };
}
}
