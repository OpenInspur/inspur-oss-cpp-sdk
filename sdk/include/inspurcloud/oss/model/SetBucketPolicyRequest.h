
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketPolicyRequest : public OssBucketRequest
    {
    public:
        SetBucketPolicyRequest(const std::string& bucket);
        SetBucketPolicyRequest(const std::string& bucket, const std::string& policy);
        void setPolicy(const std::string& policy) { policy_ = policy; }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
    private:
        std::string policy_;
    };
}
}
