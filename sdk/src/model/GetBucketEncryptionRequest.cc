#include <inspurcloud/oss/model/GetBucketEncryptionRequest.h>

using namespace InspurCloud::OSS;

GetBucketEncryptionRequest::GetBucketEncryptionRequest(const std::string& bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketEncryptionRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["encryption"] = "";
    return parameters;
}