#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketPolicyResult : public OssResult
    {
    public:
        GetBucketPolicyResult();
        GetBucketPolicyResult(const std::string& data);
        GetBucketPolicyResult(const std::shared_ptr<std::iostream>& data);
        GetBucketPolicyResult& operator=(const std::string& data);
        const std::string& Policy()const  { return policy_; }
    private:
        std::string policy_;
    };
} 
}
