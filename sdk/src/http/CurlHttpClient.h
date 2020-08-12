#pragma once

#include <inspurcloud/oss/client/ClientConfiguration.h>
#include "HttpClient.h"

namespace InspurCloud
{
namespace OSS
{

    class CurlContainer;
    class RateLimiter;

    class CurlHttpClient : public HttpClient
    {
    public:
        CurlHttpClient(const ClientConfiguration &configuration);
        ~CurlHttpClient();

        static void initGlobalState();
        static void cleanupGlobalState();

        virtual std::shared_ptr<HttpResponse> makeRequest(const std::shared_ptr<HttpRequest> &request) override;
    private:
        CurlContainer *curlContainer_;
        std::string userAgent_;
        Http::Scheme proxyScheme_;
        std::string proxyHost_;
        unsigned int proxyPort_;
        std::string proxyUserName_;
        std::string proxyPassword_;
        bool verifySSL_;
        std::string caPath_;
        std::string caFile_;
        std::string networkInterface_;
    public:
        std::shared_ptr<RateLimiter> sendRateLimiter_;
        std::shared_ptr<RateLimiter> recvRateLimiter_;
    };
}
}
