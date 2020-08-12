#include "HttpClient.h"


using namespace InspurCloud::OSS;

HttpClient::HttpClient():
    disable_(false)
{
}

HttpClient::~HttpClient()
{
}

bool HttpClient::isEnable()
{
    return disable_.load() == false;
}

void HttpClient::disable()
{
    disable_ = true;
    requestSignal_.notify_all();
}

void HttpClient::enable()
{
    disable_ = false;
}

void HttpClient::waitForRetry(long milliseconds)
{
    if (milliseconds == 0)
        return;
    std::unique_lock<std::mutex> lck(requestLock_);
    requestSignal_.wait_for(lck, std::chrono::milliseconds(milliseconds), [this] ()-> bool { return disable_.load() == true; });
}

