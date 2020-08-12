#pragma once
#include <memory>
#include <string>
#include <inspurcloud/oss/auth/CredentialsProvider.h>
#include <inspurcloud/oss/http/HttpType.h>

namespace InspurCloud
{
namespace OSS
{
    class RetryStrategy;
    class RateLimiter;
    class INSPURCLOUD_OSS_EXPORT ClientConfiguration
    {
    public:
        ClientConfiguration();
        ~ClientConfiguration() = default;
    public:
        /**
        * User Agent string user for http calls.
        */
        std::string userAgent;
        /**
        * Http scheme to use. E.g. Http or Https.
        */
        Http::Scheme scheme;
        /**
        * Max concurrent tcp connections for a single http client to use.
        */
        unsigned maxConnections;
        /**
        * Socket read timeouts. Default 3000 ms. 
        */
        long requestTimeoutMs;
        /**
        * Socket connect timeout. 
        */
        long connectTimeoutMs;
        /**
        * Strategy to use in case of failed requests.
        */
        std::shared_ptr<RetryStrategy> retryStrategy;
        /**
        * The proxy scheme. Default HTTP
        */
        Http::Scheme proxyScheme;
        /**
        * The proxy host.
        */
        std::string proxyHost;
        /**
        * The proxy port.
        */
        unsigned int proxyPort;
        /**
        * The proxy username.
        */
        std::string proxyUserName;
        /**
        *  The proxy password
        */
        std::string proxyPassword;
        /**
        * set false to bypass SSL check.
        */
        bool verifySSL;
        /**
        * your Certificate Authority path. 
        */
        std::string caPath;
        /**
        * your certificate file.
        */
        std::string caFile;
        /**
        * your certificate file.
        */
        bool isCname;
        /**
        * enable or disable crc64 check.
        */
        bool enableCrc64;
        /**
        * enable or disable auto correct http request date.
        */
        bool enableDateSkewAdjustment;
        /**
        * Rate limit data upload speed.
        */
        std::shared_ptr<RateLimiter> sendRateLimiter;
        /**
        * Rate limit data download speed.
        */
        std::shared_ptr<RateLimiter> recvRateLimiter;
        /**
        * The interface for outgoing traffic. E.g. eth0 in linux
        */
        std::string networkInterface;
    };
}
}
