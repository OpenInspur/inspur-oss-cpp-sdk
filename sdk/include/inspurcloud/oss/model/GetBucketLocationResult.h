#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketLocationResult : public OssResult
    {
    public:
        GetBucketLocationResult();
        GetBucketLocationResult(const std::string& data);
        GetBucketLocationResult(const std::shared_ptr<std::iostream>& data);
        GetBucketLocationResult& operator=(const std::string& data);
        const std::string& Location() const { return location_; }
    private:
        std::string location_;
    public:
    };
} 
}
