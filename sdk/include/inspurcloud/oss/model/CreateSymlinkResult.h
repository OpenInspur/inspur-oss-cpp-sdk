#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CreateSymlinkResult : public OssResult
    {
    public:
        CreateSymlinkResult();
        CreateSymlinkResult(const std::string& etag);
        const std::string& ETag() const { return etag_; }
    private:
        std::string etag_;
    };
} 
}

