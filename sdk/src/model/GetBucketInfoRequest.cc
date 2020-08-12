#include <inspurcloud/oss/model/GetBucketInfoRequest.h>

using namespace InspurCloud::OSS;

GetBucketInfoRequest::GetBucketInfoRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketInfoRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["bucketInfo"] = "";
    return parameters;
}