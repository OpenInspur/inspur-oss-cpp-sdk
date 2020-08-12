#include <inspurcloud/oss/model/GetBucketWebsiteRequest.h>

using namespace InspurCloud::OSS;

GetBucketWebsiteRequest::GetBucketWebsiteRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketWebsiteRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["website"] = "";
    return parameters;
}