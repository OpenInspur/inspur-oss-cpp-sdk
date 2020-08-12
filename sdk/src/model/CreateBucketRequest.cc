#include <inspurcloud/oss/model/CreateBucketRequest.h>
#include <../utils/Utils.h>
using namespace InspurCloud::OSS;

CreateBucketRequest::CreateBucketRequest(const std::string &bucket, StorageClass storageClass):
    CreateBucketRequest(bucket, storageClass, CannedAccessControlList::Default)
{
}

CreateBucketRequest::CreateBucketRequest(const std::string &bucket, StorageClass storageClass, CannedAccessControlList acl):
    OssBucketRequest(bucket),
    storageClass_(storageClass),
    acl_(acl)
{
}

//std::string CreateBucketRequest::payload() const
//{
//    std::string str;
//    str.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
//    str.append("<CreateBucketConfiguration>\n");
//    str.append("<StorageClass>");
//    str.append(ToStorageClassName(storageClass_));
//    str.append("</StorageClass>\n");
//    str.append("</CreateBucketConfiguration>");
//    return str;
//}

std::string CreateBucketRequest::payload() const
{
	std::string str;
	str.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	str.append("<CreateBucketConfiguration>\n");
	str.append("<LocationConstraint>");
	str.append(region_);
	str.append("</LocationConstraint>\n");
	str.append("</CreateBucketConfiguration>");
	return str;
}

HeaderCollection CreateBucketRequest::specialHeaders() const
{
    if (acl_ < CannedAccessControlList::Default) {
        HeaderCollection headers;
        headers["x-oss-acl"] = ToAclName(acl_);
        return headers;
    }
    return OssRequest::specialHeaders();
}
