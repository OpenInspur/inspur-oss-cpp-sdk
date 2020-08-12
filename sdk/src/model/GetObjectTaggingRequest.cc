
#include <inspurcloud/oss/model/GetObjectTaggingRequest.h>
using namespace InspurCloud::OSS;

GetObjectTaggingRequest::GetObjectTaggingRequest(const std::string &bucket, const std::string &key)
    :OssObjectRequest(bucket, key)
{
}

ParameterCollection GetObjectTaggingRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["tagging"] = "";
    return paramters;
}

