#pragma once
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT PutObjectResult :public OssResult
    {
    public:
        PutObjectResult();
        PutObjectResult(const HeaderCollection& header);
        PutObjectResult(const HeaderCollection& header, const std::shared_ptr<std::iostream>& content);
        PutObjectResult(const std::string eTag, const uint64_t crc64) :eTag_(eTag), crc64_(crc64) {}
        const std::string& ETag() const;
        uint64_t CRC64();
        const std::shared_ptr<std::iostream>& Content() const;
     private:
        std::string eTag_;
        uint64_t crc64_;
        std::shared_ptr<std::iostream> content_;
    };
}
}
