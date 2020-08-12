#include <inspurcloud/oss/model/DeleteBucketLoggingRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketLoggingRequest::DeleteBucketLoggingRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketLoggingRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["logging"] = "";
    return parameters;
}