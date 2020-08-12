#include <inspurcloud/oss/model/GetBucketStatRequest.h>

using namespace InspurCloud::OSS;

GetBucketStatRequest::GetBucketStatRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketStatRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["stat"] = "";
    return parameters;
}