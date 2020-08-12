#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/LifecycleRule.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CompleteMultipartUploadResult: public OssResult
    {
    public:
        CompleteMultipartUploadResult();
        CompleteMultipartUploadResult(const std::string& data);
        CompleteMultipartUploadResult(const std::shared_ptr<std::iostream>& data, 
            const HeaderCollection& headers);
        CompleteMultipartUploadResult& operator=(const std::string& data);
        const std::string& Location() const;
        const std::string& Bucket() const;
        const std::string& Key() const;
        const std::string& ETag() const;
        const std::string& EncodingType() const;
        uint64_t CRC64() const;
        const std::shared_ptr<std::iostream>& Content() const;
    private:
        std::string location_;
        std::string bucket_;
        std::string key_;
        std::string eTag_;
        std::string encodingType_;
        uint64_t crc64_;
        std::shared_ptr<std::iostream> content_;
    };
} 
}
