
#include <inspurcloud/oss/model/DeleteObjectTaggingRequest.h>
using namespace InspurCloud::OSS;

DeleteObjectTaggingRequest::DeleteObjectTaggingRequest(const std::string& bucket, const std::string& key):
    OssObjectRequest(bucket, key)
{
}

ParameterCollection DeleteObjectTaggingRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["tagging"] = "";
    return parameters;
}

