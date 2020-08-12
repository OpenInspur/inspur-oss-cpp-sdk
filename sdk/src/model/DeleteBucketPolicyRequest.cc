#include <inspurcloud/oss/model/DeleteBucketPolicyRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketPolicyRequest::DeleteBucketPolicyRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketPolicyRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["policy"] = "";
    return parameters;
}