#include <inspurcloud/oss/model/SetBucketPaymentRequest.h>
#include <sstream>
#include "../utils/Utils.h"


using namespace InspurCloud::OSS;

SetBucketRequestPaymentRequest::SetBucketRequestPaymentRequest(const std::string& bucket) :
    SetBucketRequestPaymentRequest(bucket, RequestPayer::NotSet)
{
}

SetBucketRequestPaymentRequest::SetBucketRequestPaymentRequest(const std::string& bucket,
    RequestPayer payer) :
    OssBucketRequest(bucket),
    payer_(payer)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketRequestPaymentRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<RequestPaymentConfiguration>" << std::endl;
    ss << "<Payer>" << ToRequestPayerName(payer_) << "</Payer>" << std::endl;
    ss << "</RequestPaymentConfiguration>" << std::endl;
    return ss.str();
}

ParameterCollection SetBucketRequestPaymentRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["requestPayment"] = "";
    return parameters;
}

