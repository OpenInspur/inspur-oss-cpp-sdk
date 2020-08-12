

#include <inspurcloud/oss/model/AppendObjectRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;

AppendObjectRequest::AppendObjectRequest(const std::string &bucket, const std::string &key,
        const std::shared_ptr<std::iostream>& content):
    OssObjectRequest(bucket, key),
    position_(0),
    content_(content)
{
}

AppendObjectRequest::AppendObjectRequest(const std::string &bucket, const std::string &key,
        const std::shared_ptr<std::iostream>& content, const ObjectMetaData &metaData):
    OssObjectRequest(bucket, key),
    position_(0),
    content_(content),
    metaData_(metaData)
{
}

void AppendObjectRequest::setPosition(uint64_t position)
{
    position_ = position;
}

void AppendObjectRequest::setCacheControl(const std::string& value)
{
    metaData_.addHeader(Http::CACHE_CONTROL, value);
}

void AppendObjectRequest::setContentDisposition(const std::string& value)
{
    metaData_.addHeader(Http::CONTENT_DISPOSITION, value);
}

void AppendObjectRequest::setContentEncoding(const std::string& value)
{
    metaData_.addHeader(Http::CONTENT_ENCODING, value);
}

void AppendObjectRequest::setContentMd5(const std::string& value)
{
    metaData_.addHeader(Http::CONTENT_MD5, value);
}

void AppendObjectRequest::setExpires(uint64_t expires)
{
	metaData_.addHeader(Http::EXPIRES, std::to_string(expires));
}

void AppendObjectRequest::setExpires(const std::string& value)
{
    metaData_.addHeader(Http::EXPIRES, value);
}

void AppendObjectRequest::setAcl(const CannedAccessControlList& acl)
{
	metaData_.addHeader("x-oss-object-acl", ToAclName(acl));
}

void AppendObjectRequest::setTagging(const std::string& value)
{
    metaData_.addHeader("x-oss-tagging", value);
}

void AppendObjectRequest::setTrafficLimit(uint64_t value)
{
    metaData_.addHeader("x-oss-traffic-limit", std::to_string(value));
}

std::shared_ptr<std::iostream> AppendObjectRequest::Body() const
{
    return content_;
}


HeaderCollection AppendObjectRequest::specialHeaders() const
{
    auto headers = metaData_.toHeaderCollection();

    if (headers.find(Http::CONTENT_TYPE) == headers.end()) {
        headers[Http::CONTENT_TYPE] = LookupMimeType(Key());
    }

    auto baseHeaders = OssObjectRequest::specialHeaders();
    headers.insert(baseHeaders.begin(), baseHeaders.end());

    return headers;
}

ParameterCollection AppendObjectRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["append"] = "";
    paramters["position"] = std::to_string(position_);

    return paramters;
}


