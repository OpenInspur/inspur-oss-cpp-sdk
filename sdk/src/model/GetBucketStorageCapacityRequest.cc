#include <inspurcloud/oss/model/GetBucketStorageCapacityRequest.h>

using namespace InspurCloud::OSS;

GetBucketStorageCapacityRequest::GetBucketStorageCapacityRequest(const std::string &bucket) :
    OssBucketRequest(bucket)
{
}

ParameterCollection GetBucketStorageCapacityRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["qos"] = "";
    return parameters;
}