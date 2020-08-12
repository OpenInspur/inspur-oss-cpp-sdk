#pragma once

#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    /*the unit of rate is kB/S*/
    class  INSPURCLOUD_OSS_EXPORT RateLimiter
    {
    public:
        virtual ~RateLimiter() {}
        virtual void setRate(int rate) = 0;
        virtual int Rate() const = 0;
    };
} 
}
