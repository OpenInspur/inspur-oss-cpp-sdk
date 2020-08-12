#include <inspurcloud/oss/model/SetBucketAclRequest.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;


SetBucketAclRequest::SetBucketAclRequest(const std::string &bucket, CannedAccessControlList acl) :
    OssBucketRequest(bucket),
    acl_(acl)
{
}

void SetBucketAclRequest::setAcl(CannedAccessControlList acl)
{
    acl_ = acl;
}

HeaderCollection SetBucketAclRequest::specialHeaders() const
{
    HeaderCollection headers;
    if (acl_ < CannedAccessControlList::Default) {
        headers["x-oss-acl"] = ToAclName(acl_);
    }
    return headers;
}

ParameterCollection SetBucketAclRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["acl"] = "";
    return parameters;
}

