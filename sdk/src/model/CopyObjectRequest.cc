

#include <inspurcloud/oss/model/CopyObjectRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include <sstream>
using namespace InspurCloud::OSS;

CopyObjectRequest::CopyObjectRequest(const std::string &bucket, const std::string &key):
    OssObjectRequest(bucket, key)
{
}

CopyObjectRequest::CopyObjectRequest(const std::string &bucket, const std::string &key,
    const ObjectMetaData &metaData):
    OssObjectRequest(bucket, key),
    metaData_(metaData)
{
}

void CopyObjectRequest::setCopySource(const std::string& srcBucket,const std::string& srcObject)
{
    std::stringstream ssDesc;
    ssDesc << "/" << srcBucket << "/" << UrlEncode(srcObject);
    std::string value = ssDesc.str();
    metaData_.addHeader("x-oss-copy-source", value);
}

void CopyObjectRequest::setSourceIfMatchETag(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-match", value);
}

void CopyObjectRequest::setSourceIfNotMatchETag(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-none-match", value);
}

void CopyObjectRequest::setSourceIfUnModifiedSince(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-unmodified-since", value);
}

void CopyObjectRequest::setSourceIfModifiedSince(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-modified-since", value);
}

void CopyObjectRequest::setMetadataDirective(const CopyActionList& action)
{
    metaData_.addHeader("x-oss-metadata-directive", ToCopyActionName(action));
}

void CopyObjectRequest::setAcl(const CannedAccessControlList& acl)
{
    metaData_.addHeader("x-oss-object-acl", ToAclName(acl));
}

void CopyObjectRequest::setTagging(const std::string& value)
{
    metaData_.addHeader("x-oss-tagging", value);
}

void CopyObjectRequest::setTaggingDirective(const CopyActionList& action)
{
    metaData_.addHeader("x-oss-tagging-directive", ToCopyActionName(action));
}

void CopyObjectRequest::setTrafficLimit(uint64_t value)
{
    metaData_.addHeader("x-oss-traffic-limit", std::to_string(value));
}

HeaderCollection CopyObjectRequest::specialHeaders() const
{
    auto headers = metaData_.toHeaderCollection();

    if (headers.find(Http::CONTENT_TYPE) == headers.end()) {
        headers[Http::CONTENT_TYPE] = LookupMimeType(Key());
    }

    auto baseHeaders = OssObjectRequest::specialHeaders();
    headers.insert(baseHeaders.begin(), baseHeaders.end());

    return headers;
}

