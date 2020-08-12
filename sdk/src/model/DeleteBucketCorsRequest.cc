#include <inspurcloud/oss/model/DeleteBucketCorsRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketCorsRequest::DeleteBucketCorsRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketCorsRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["cors"] = "";
    return parameters;
}