#pragma once
#include <string>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectResult :public OssResult
    {
    public:
        GetObjectResult();
        GetObjectResult(const std::string& bucket, const std::string& key, 
            const std::shared_ptr<std::iostream>& content,
            const HeaderCollection& headers);
        GetObjectResult(const std::string& bucket, const std::string& key,
            const ObjectMetaData& metaData);
        const std::string& Bucket() const { return bucket_; }
        const std::string& Key()  const { return key_; }
        const ObjectMetaData& Metadata()  const { return metaData_; }
        const std::shared_ptr<std::iostream>& Content() const { return content_; }
        void setContent(const std::shared_ptr<std::iostream>& content) { content_ = content; }
    private:
        std::string bucket_;
        std::string key_;
        ObjectMetaData metaData_;
        std::shared_ptr<std::iostream> content_;
    };
}
}
