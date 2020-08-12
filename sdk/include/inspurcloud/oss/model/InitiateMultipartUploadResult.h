
#pragma once
#include <string>
#include <memory>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT InitiateMultipartUploadResult :public OssResult
    {
    public:
        InitiateMultipartUploadResult();
        InitiateMultipartUploadResult(const std::string& data);
        InitiateMultipartUploadResult(const std::shared_ptr<std::iostream>& data);
        InitiateMultipartUploadResult& operator=(const std::string& data);

        const std::string& Bucket() const { return bucket_; }
        const std::string& Key() const { return key_; }
        const std::string& UploadId() const { return uploadId_; }
        const std::string& EncodingType() const { return encodingType_; }
    private:
        std::string bucket_;
        std::string key_;
        std::string uploadId_;
        std::string encodingType_;
    };
}
}
