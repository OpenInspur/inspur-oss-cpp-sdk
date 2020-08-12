#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT AppendObjectResult : public OssResult
    {
    public:
       public:
        AppendObjectResult();
        AppendObjectResult(const HeaderCollection& header);
        uint64_t Length() const { return length_ ; }
        uint64_t CRC64() const { return crc64_ ; }
     private:
        uint64_t length_;
        uint64_t crc64_;
    };
} 
}

