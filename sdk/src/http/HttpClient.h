#pragma once

#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include "HttpRequest.h"
#include "HttpResponse.h"


namespace InspurCloud
{
namespace OSS
{

    class HttpClient
    {
    public:
        HttpClient();
        virtual ~HttpClient();

        virtual std::shared_ptr<HttpResponse> makeRequest(const std::shared_ptr<HttpRequest> &request) = 0;

        bool isEnable();
        void disable();
        void enable();
        void waitForRetry(long milliseconds);
        
    protected:
        std::atomic<bool> disable_;
        std::mutex requestLock_;
        std::condition_variable requestSignal_;
    };
}
}
