#include "HttpResponse.h"

namespace
{
    #define INVALID_STATUS_CODE -1
}

using namespace InspurCloud::OSS;

HttpResponse::HttpResponse(const std::shared_ptr<HttpRequest> & request) :
    HttpMessage(),
    request_(request),
    statusCode_(INVALID_STATUS_CODE)
{
}

HttpResponse::~HttpResponse()
{
}

const HttpRequest & HttpResponse::request() const
{
    return *request_.get();
}

void HttpResponse::setStatusCode(int code)
{
    statusCode_ = code;
}

int HttpResponse::statusCode() const
{
    return statusCode_;
}

void HttpResponse::setStatusMsg(std::string &msg)
{
    statusMsg_ = msg;
}

void HttpResponse::setStatusMsg(const char *msg)
{
    statusMsg_ = msg;
}

std::string HttpResponse::statusMsg() const
{
    return statusMsg_;
}
