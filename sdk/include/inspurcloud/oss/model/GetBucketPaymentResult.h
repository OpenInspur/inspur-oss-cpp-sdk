#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketPaymentResult : public OssResult
    {
    public:
        GetBucketPaymentResult();
        GetBucketPaymentResult(const std::string& data);
        GetBucketPaymentResult(const std::shared_ptr<std::iostream>& data);
        GetBucketPaymentResult& operator=(const std::string& data);
        RequestPayer Payer()const { return payer_; }
    private:
        RequestPayer payer_;
    };
} 
}
