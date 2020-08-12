#include <inspurcloud/oss/model/GetBucketLifecycleRequest.h>

using namespace InspurCloud::OSS;

GetBucketLifecycleRequest::GetBucketLifecycleRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketLifecycleRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["lifecycle"] = "";
    return parameters;
}