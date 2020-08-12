
#include <inspurcloud/oss/utils/Runnable.h>

using namespace InspurCloud::OSS;

Runnable::Runnable(const std::function<void()> f) :
    f_(f)
{
}

void Runnable::run() const
{
    f_(); 
}