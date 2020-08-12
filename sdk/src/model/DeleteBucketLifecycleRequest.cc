#include <inspurcloud/oss/model/DeleteBucketLifecycleRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketLifecycleRequest::DeleteBucketLifecycleRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketLifecycleRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["lifecycle"] = "";
    return parameters;
}