#include <inspurcloud/oss/model/GetBucketCorsRequest.h>

using namespace InspurCloud::OSS;

GetBucketCorsRequest::GetBucketCorsRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketCorsRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["cors"] = "";
    return parameters;
}