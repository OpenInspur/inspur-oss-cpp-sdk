#pragma once

#include <iostream>
#include <memory>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/http/HttpType.h>

namespace InspurCloud
{
namespace OSS
{

    class  HttpMessage
    {
    public:

        HttpMessage(const HttpMessage &other);
        HttpMessage(HttpMessage &&other);
        HttpMessage& operator=(const HttpMessage &other);
        HttpMessage& operator=(HttpMessage &&other);
        virtual ~HttpMessage();

        void addHeader(const std::string &name, const std::string &value);
        void setHeader(const std::string &name, const std::string &value);
        void removeHeader(const std::string &name);
        bool hasHeader(const std::string &name) const ;
        std::string Header(const std::string &name)const;
        const HeaderCollection &Headers()const;

        void addBody(const std::shared_ptr<std::iostream>& body) { body_ = body;}
        std::shared_ptr<std::iostream>& Body() { return body_;}
    protected:
        HttpMessage();
    private:
        HeaderCollection headers_;
        std::shared_ptr<std::iostream> body_;
    };
}
}
