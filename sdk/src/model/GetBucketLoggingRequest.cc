#include <inspurcloud/oss/model/GetBucketLoggingRequest.h>

using namespace InspurCloud::OSS;

GetBucketLoggingRequest::GetBucketLoggingRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketLoggingRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["logging"] = "";
    return parameters;
}