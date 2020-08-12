#include <inspurcloud/oss/model/GetBucketPolicyRequest.h>

using namespace InspurCloud::OSS;

GetBucketPolicyRequest::GetBucketPolicyRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketPolicyRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["policy"] = "";
    return parameters;
}