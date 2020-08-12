#include <inspurcloud/oss/http/HttpType.h>
#include "HttpRequest.h"

using namespace InspurCloud::OSS;

std::string Http::MethodToString(Method method)
{
    static const char* name[] = {"GET", "HEAD", "POST", "PUT", "DELETE", 
        "CONNECT", "OPTIONS", "PATCH", "TRACE"};
    return name[(method - Http::Method::Get)];
}

std::string Http::SchemeToString(Scheme scheme)
{
    static const char* name[] = {"http", "https"};
    return name[scheme - Http::Scheme::HTTP];
}

const char* Http::ACCEPT = "Accept";
const char* Http::ACCEPT_CHARSET = "Accept-Charset";
const char* Http::ACCEPT_ENCODING = "Accept-Encoding";
const char* Http::ACCEPT_LANGUAGE = "Accept-Language";
const char* Http::AUTHORIZATION = "Authorization";
const char* Http::CACHE_CONTROL = "Cache-Control";
const char* Http::CONTENT_DISPOSITION = "Content-Disposition";
const char* Http::CONTENT_ENCODING = "Content-Encoding";
const char* Http::CONTENT_LENGTH = "Content-Length";
const char* Http::CONTENT_MD5 = "Content-MD5";
const char* Http::CONTENT_RANGE = "Content-Range";
const char* Http::CONTENT_TYPE = "Content-Type";
const char* Http::DATE = "Date";
const char* Http::EXPECT = "Expect";
const char* Http::EXPIRES = "Expires";
const char* Http::ETAG = "ETag";
const char* Http::LAST_MODIFIED = "Last-Modified";
const char* Http::RANGE = "Range";
const char* Http::USER_AGENT = "User-Agent";


HttpRequest::HttpRequest(Http::Method method) :
    HttpMessage(),
    method_(method),
    url_(),
    responseStreamFactory_(nullptr),
    hasCheckCrc64_(false),
    crc64Result_(0),
    transferedBytes_(0)
{
}

HttpRequest::~HttpRequest()
{
}

Http::Method HttpRequest::method() const
{
    return method_;
}


void HttpRequest::setMethod(Http::Method method)
{
    method_ = method;
}

void HttpRequest::setUrl(const Url &url)
{
    url_ = url;
}

Url HttpRequest::url()const
{
    return url_;
}
