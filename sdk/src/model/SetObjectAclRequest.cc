
#include <inspurcloud/oss/model/SetObjectAclRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;

SetObjectAclRequest::SetObjectAclRequest(const std::string &bucket, const std::string &key) :
	OssObjectRequest(bucket,key),
    hasSetAcl_(false)
{
}

SetObjectAclRequest::SetObjectAclRequest(const std::string &bucket
        ,const std::string &key, CannedAccessControlList acl) :
	OssObjectRequest(bucket,key),
    acl_(acl),
    hasSetAcl_(true)
{
}


void SetObjectAclRequest::setAcl(CannedAccessControlList acl)
{
    acl_ = acl;
	hasSetAcl_ = true;
}

HeaderCollection SetObjectAclRequest::specialHeaders() const
{
    auto headers = OssObjectRequest::specialHeaders();
    if (hasSetAcl_) {
        headers["x-oss-object-acl"] = ToAclName(acl_);
    }
    return headers;
}

ParameterCollection SetObjectAclRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["acl"] = "";
    return paramters;
}




