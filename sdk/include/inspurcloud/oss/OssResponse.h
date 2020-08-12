
#pragma once

#include <string>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT OssResponse
    {
    public:
        OssResponse();
        explicit OssResponse(const std::string& payload);
        ~OssResponse();
        std::string payload()const;
    private:
        std::string payload_;
    };
}
}
