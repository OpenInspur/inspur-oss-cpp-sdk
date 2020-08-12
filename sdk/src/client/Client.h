#pragma once

#include <functional>
#include <memory>
#include <inspurcloud/oss/ServiceRequest.h>
#include <inspurcloud/oss/ServiceResult.h>
#include <inspurcloud/oss/client/ClientConfiguration.h>
#include <inspurcloud/oss/client/Error.h>
#include <inspurcloud/oss/utils/Outcome.h>
#include "../http/HttpClient.h"

namespace InspurCloud
{
namespace OSS
{

    class  Client
    {
    public:
        using ClientOutcome =  Outcome<Error, std::shared_ptr<HttpResponse>> ;

        Client(const std::string & servicename, const ClientConfiguration &configuration);
        virtual ~Client();

        std::string serviceName()const;
        const ClientConfiguration &configuration()const;

        bool isEnableRequest() const;

    protected:
        ClientOutcome AttemptRequest(const std::string & endpoint, const ServiceRequest &request, Http::Method method) const;
        ClientOutcome AttemptOnceRequest(const std::string & endpoint, const ServiceRequest &request, Http::Method method) const;
        virtual std::shared_ptr<HttpRequest> buildHttpRequest(const std::string & endpoint, const ServiceRequest &msg, Http::Method method) const = 0;
        virtual bool hasResponseError(const std::shared_ptr<HttpResponse>&response) const;
        
        void setRequestDateOffset(uint64_t offset) const;
        uint64_t getRequestDateOffset() const;

        void disableRequest();
        void enableRequest();
    private:
        Error buildError(const std::shared_ptr<HttpResponse> &response) const ;
        std::string analyzeServerTime(const std::string &message) const;

        mutable uint64_t requestDateOffset_;
        std::string serviceName_;
        ClientConfiguration configuration_;
        std::shared_ptr<HttpClient> httpClient_;
    };
}
}
