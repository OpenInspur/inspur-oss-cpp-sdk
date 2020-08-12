#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketWebsiteResult: public OssResult
    {
    public:
        GetBucketWebsiteResult();
        GetBucketWebsiteResult(const std::string& data);
        GetBucketWebsiteResult(const std::shared_ptr<std::iostream>& data);
        GetBucketWebsiteResult& operator=(const std::string& data);
        const std::string& IndexDocument() const { return indexDocument_; }
        const std::string& ErrorDocument() const { return errorDocument_; }
    private:
        std::string indexDocument_;
        std::string errorDocument_;
    };
} 
}
