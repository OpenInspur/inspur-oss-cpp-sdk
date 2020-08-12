#include <inspurcloud/oss/model/GetBucketLocationRequest.h>

using namespace InspurCloud::OSS;

GetBucketLocationRequest::GetBucketLocationRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketLocationRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["location"] = "";
    return parameters;
}