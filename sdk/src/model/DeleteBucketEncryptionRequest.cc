#include <inspurcloud/oss/model/DeleteBucketEncryptionRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketEncryptionRequest::DeleteBucketEncryptionRequest(const std::string& bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketEncryptionRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["encryption"] = "";
    return parameters;
}