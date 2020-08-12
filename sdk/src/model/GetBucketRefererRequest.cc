#include <inspurcloud/oss/model/GetBucketRefererRequest.h>

using namespace InspurCloud::OSS;

GetBucketRefererRequest::GetBucketRefererRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketRefererRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["referer"] = "";
    return parameters;
}