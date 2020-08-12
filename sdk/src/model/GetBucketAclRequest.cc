#include <inspurcloud/oss/model/GetBucketAclRequest.h>

using namespace InspurCloud::OSS;

GetBucketAclRequest::GetBucketAclRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketAclRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["acl"] = "";
    return parameters;
}