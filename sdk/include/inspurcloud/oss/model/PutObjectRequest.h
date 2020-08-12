#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT PutObjectRequest: public OssObjectRequest
    {
    public:
        PutObjectRequest(const std::string& bucket, const std::string& key,
            const std::shared_ptr<std::iostream>& content);
        PutObjectRequest(const std::string& bucket, const std::string& key,
            const std::shared_ptr<std::iostream>& content, 
            const ObjectMetaData& meta);
        void setCacheControl(const std::string& value);
        void setContentDisposition(const std::string& value);
        void setContentEncoding(const std::string& value);
        void setContentMd5(const std::string& value);
        void setExpires(const std::string& value);
        void setCallback(const std::string& callback, const std::string& callbackVar = "");
        void setTrafficLimit(uint64_t value);
        void setTagging(const std::string& value);
        void setServerSideEncryption(const SSEAlgorithm sse, const std::string& value = "");
        ObjectMetaData& MetaData();
        virtual std::shared_ptr<std::iostream> Body() const;
    protected:
        virtual HeaderCollection specialHeaders() const;
        virtual int validate() const;
    private:
        std::shared_ptr<std::iostream> content_;
        ObjectMetaData metaData_;
    };
} 
}
