

#include <inspurcloud/oss/model/RestoreObjectRequest.h>
using namespace InspurCloud::OSS;

RestoreObjectRequest::RestoreObjectRequest(const std::string &bucket, const std::string &key)
    :OssObjectRequest(bucket,key)
{
}
    
ParameterCollection RestoreObjectRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["restore"]="";
    return paramters;
}

