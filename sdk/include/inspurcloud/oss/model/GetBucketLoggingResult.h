#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketLoggingResult : public OssResult
    {
    public:
        GetBucketLoggingResult();
        GetBucketLoggingResult(const std::string& data);
        GetBucketLoggingResult(const std::shared_ptr<std::iostream>& data);
        GetBucketLoggingResult& operator=(const std::string& data);
        const std::string& TargetBucket() const { return targetBucket_; }
        const std::string& TargetPrefix() const { return targetPrefix_; }
    private:
        std::string targetBucket_;
        std::string targetPrefix_;
    };
} 
}
