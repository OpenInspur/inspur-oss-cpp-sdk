#pragma once
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT VoidResult :public OssResult
    {
    public:
        VoidResult() = default;
        ~VoidResult() = default;
    private:
    };
}
}
