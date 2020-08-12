#include "HttpMessage.h"

using namespace InspurCloud::OSS;

HttpMessage::HttpMessage() :
    headers_(),
    body_()
{
}

HttpMessage::HttpMessage(const HttpMessage &other) :
    headers_(other.headers_),
    body_(other.body_)
{
}

HttpMessage::HttpMessage(HttpMessage &&other)
{
    *this = std::move(other);
}

HttpMessage& HttpMessage::operator=(const HttpMessage &other)
{
    if (this != &other) {
        body_ = other.body_;
        headers_ = other.headers_;
    }
    return *this;
}

HttpMessage& HttpMessage::operator=(HttpMessage &&other)
{
    if (this != &other)
        *this = std::move(other);
    return *this;
}

void HttpMessage::addHeader(const std::string & name, const std::string & value)
{
    setHeader(name, value);
}

void HttpMessage::setHeader(const std::string & name, const std::string & value)
{
    headers_[name] = value;
}

void HttpMessage::removeHeader(const std::string & name)
{
    headers_.erase(name);
}


bool HttpMessage::hasHeader(const std::string &name) const
{
    return  (headers_.find(name) != headers_.end()) ? true : false;
}

std::string HttpMessage::Header(const std::string & name) const
{
    auto it = headers_.find(name);
    if (it != headers_.end())
        return it->second;
    else    
        return std::string();
}

const HeaderCollection &HttpMessage::Headers() const
{
    return headers_;
}

HttpMessage::~HttpMessage()
{

}


