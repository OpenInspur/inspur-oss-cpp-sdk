
#include <inspurcloud/oss/model/GetObjectAclRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;

GetObjectAclRequest::GetObjectAclRequest(const std::string &bucket, const std::string &key)
    :OssObjectRequest(bucket,key)
{
}
    
ParameterCollection GetObjectAclRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["acl"]="";
    return paramters;
}

