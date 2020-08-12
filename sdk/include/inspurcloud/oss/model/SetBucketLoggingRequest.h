#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketLoggingRequest : public OssBucketRequest
    {
    public:
        SetBucketLoggingRequest(const std::string& bucket);
        SetBucketLoggingRequest(const std::string& bucket,
            const std::string& targetBucket, const std::string& targetPrefix);
        void setTargetBucket(const std::string& bucket) { targetBucket_ = bucket; }
        void setTargetPrefix(const std::string& prefix) { targetPrefix_ = prefix; }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        std::string targetBucket_;
        std::string targetPrefix_;
    };
} 
}
