#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketStatResult : public OssResult
    {
    public:
        GetBucketStatResult();
        GetBucketStatResult(const std::string& data);
        GetBucketStatResult(const std::shared_ptr<std::iostream>& data);
        GetBucketStatResult& operator=(const std::string& data);
        uint64_t Storage() const { return storage_; }
        uint64_t ObjectCount() const { return objectCount_; }
        uint64_t MultipartUploadCount() const { return multipartUploadCount_; }
    private:
        uint64_t storage_;
        uint64_t objectCount_;
        uint64_t multipartUploadCount_;
    };
} 
}
