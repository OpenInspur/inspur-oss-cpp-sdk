#pragma once

#include <inspurcloud/oss/client/Error.h>

namespace InspurCloud
{
namespace OSS
{
    class  INSPURCLOUD_OSS_EXPORT RetryStrategy
    {
    public:
        virtual ~RetryStrategy() {}
        virtual bool shouldRetry(const Error& error, long attemptedRetries) const = 0;
        virtual long calcDelayTimeMs(const Error& error, long attemptedRetries) const = 0;
    };
} 
}
