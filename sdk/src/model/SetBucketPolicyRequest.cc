#include <inspurcloud/oss/model/SetBucketPolicyRequest.h>
#include <sstream>


using namespace InspurCloud::OSS;

SetBucketPolicyRequest::SetBucketPolicyRequest(const std::string& bucket) :
    SetBucketPolicyRequest(bucket, "")
{
}

SetBucketPolicyRequest::SetBucketPolicyRequest(const std::string& bucket,
    const std::string& policy) :
    OssBucketRequest(bucket),
    policy_(policy)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketPolicyRequest::payload() const
{
    return policy_;
}

ParameterCollection SetBucketPolicyRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["policy"] = "";
    return parameters;
}
