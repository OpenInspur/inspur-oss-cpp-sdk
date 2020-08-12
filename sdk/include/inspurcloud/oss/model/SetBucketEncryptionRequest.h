#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketEncryptionRequest : public OssBucketRequest
    {
    public:
        SetBucketEncryptionRequest(const std::string& bucket, SSEAlgorithm sse = SSEAlgorithm::AES256, const std::string& key = "");
        void setSSEAlgorithm(SSEAlgorithm sse);
        void setKMSMasterKeyID(const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual std::string payload() const;
    private:
        SSEAlgorithm SSEAlgorithm_;
        std::string KMSMasterKeyID_;
    };
} 
}
