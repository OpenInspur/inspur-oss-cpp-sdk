
#include <inspurcloud/oss/model/PutObjectByUrlRequest.h>
#include <sstream>
#include <iostream>

using namespace InspurCloud::OSS;

PutObjectByUrlRequest::PutObjectByUrlRequest(
    const std::string &url,
    const std::shared_ptr<std::iostream> &content) :
    PutObjectByUrlRequest(url, content, ObjectMetaData())
{
}

PutObjectByUrlRequest::PutObjectByUrlRequest(
    const std::string &url,
    const std::shared_ptr<std::iostream> &content,
    const ObjectMetaData &metaData) :
    ServiceRequest(),
    content_(content),
    metaData_(metaData)
{
    setPath(url);
    setFlags(Flags()|REQUEST_FLAG_PARAM_IN_PATH|REQUEST_FLAG_CHECK_CRC64);
}

HeaderCollection PutObjectByUrlRequest::Headers() const
{
    auto headers = metaData_.toHeaderCollection();
    if (headers.find(Http::DATE) == headers.end()) {
        headers[Http::DATE] = "";
    }
    return headers;
}

ParameterCollection PutObjectByUrlRequest::Parameters() const
{
    return ParameterCollection();
}

std::shared_ptr<std::iostream> PutObjectByUrlRequest::Body() const
{
    return content_;
}
