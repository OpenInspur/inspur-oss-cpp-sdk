#include <inspurcloud/oss/model/DeleteBucketWebsiteRequest.h>

using namespace InspurCloud::OSS;

DeleteBucketWebsiteRequest::DeleteBucketWebsiteRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection DeleteBucketWebsiteRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["website"] = "";
    return parameters;
}