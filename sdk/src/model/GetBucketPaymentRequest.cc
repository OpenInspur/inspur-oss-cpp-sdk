#include <inspurcloud/oss/model/GetBucketPaymentRequest.h>

using namespace InspurCloud::OSS;

GetBucketRequestPaymentRequest::GetBucketRequestPaymentRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketRequestPaymentRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["requestPayment"] = "";
    return parameters;
}