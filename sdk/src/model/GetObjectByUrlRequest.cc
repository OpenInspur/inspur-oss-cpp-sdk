
#include <inspurcloud/oss/model/GetObjectByUrlRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include <sstream>
using namespace InspurCloud::OSS;


GetObjectByUrlRequest::GetObjectByUrlRequest(const std::string &url):
    GetObjectByUrlRequest(url, ObjectMetaData())
{
}

GetObjectByUrlRequest::GetObjectByUrlRequest(const std::string &url, const ObjectMetaData &metaData) :
    ServiceRequest(),
    metaData_(metaData)
{
    setPath(url);
    setFlags(Flags()|REQUEST_FLAG_PARAM_IN_PATH|REQUEST_FLAG_CHECK_CRC64);
}

HeaderCollection GetObjectByUrlRequest::Headers() const
{
    auto headers = metaData_.toHeaderCollection();
    if (!metaData_.hasHeader(Http::DATE)) {
        headers[Http::DATE] = "";
    }
    return headers;
}

ParameterCollection GetObjectByUrlRequest::Parameters() const
{
    return ParameterCollection();
}

std::shared_ptr<std::iostream> GetObjectByUrlRequest::Body() const
{
    return nullptr;
}
