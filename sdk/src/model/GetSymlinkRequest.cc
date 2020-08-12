
#include <inspurcloud/oss/model/GetSymlinkRequest.h>

using namespace InspurCloud::OSS;

GetSymlinkRequest::GetSymlinkRequest(const std::string &bucket, const std::string &key):
    OssObjectRequest(bucket, key)
{
}

ParameterCollection GetSymlinkRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["symlink"] = "";
    return paramters;
}


