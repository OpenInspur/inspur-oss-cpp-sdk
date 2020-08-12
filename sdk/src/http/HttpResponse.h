#pragma once

#include <string>
#include <memory>
#include "HttpMessage.h"
#include "HttpRequest.h"

namespace InspurCloud
{
namespace OSS
{

    class  HttpResponse : public HttpMessage
    {
        public:
            HttpResponse(const std::shared_ptr<HttpRequest> & request);
            ~HttpResponse();

            const HttpRequest &request()const;
            void setStatusCode(int code);
            int statusCode()const;
            void setStatusMsg(std::string &msg);
            void setStatusMsg(const char *msg);
            std::string statusMsg()const;
        private:
            HttpResponse() = delete;
            std::shared_ptr<HttpRequest> request_;
            mutable int statusCode_;
            mutable std::string statusMsg_;
    };
}
}
