#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketRequestPaymentRequest : public OssBucketRequest
    {
    public:
        SetBucketRequestPaymentRequest(const std::string& bucket);
        SetBucketRequestPaymentRequest(const std::string& bucket, RequestPayer payer);
        void setRequestPayer(RequestPayer payer) { payer_ = payer; }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
    private:
        RequestPayer payer_;
    };
} 
}
