#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketEncryptionResult : public OssResult
    {
    public:
        GetBucketEncryptionResult();
        GetBucketEncryptionResult(const std::string& data);
        GetBucketEncryptionResult(const std::shared_ptr<std::iostream>& data);
        GetBucketEncryptionResult& operator=(const std::string& data);
        InspurCloud::OSS::SSEAlgorithm SSEAlgorithm() const { return SSEAlgorithm_; }
        const std::string& KMSMasterKeyID() const { return KMSMasterKeyID_; }
    private:
        InspurCloud::OSS::SSEAlgorithm SSEAlgorithm_;
        std::string KMSMasterKeyID_;
    };
}
}
