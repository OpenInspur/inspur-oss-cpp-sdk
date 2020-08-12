
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>


namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT AppendObjectRequest: public OssObjectRequest
    {
    public:
        AppendObjectRequest(const std::string& bucket, const std::string& key,
            const std::shared_ptr<std::iostream>& content);
        AppendObjectRequest(const std::string& bucket, const std::string& key,
            const std::shared_ptr<std::iostream>& content,
            const ObjectMetaData& meta);
        void setPosition(uint64_t position);
        void setCacheControl(const std::string& value);
        void setContentDisposition(const std::string& value);
        void setContentEncoding(const std::string& value);
        void setContentMd5(const std::string& value);
        void setExpires(uint64_t expires);
        void setExpires(const std::string& value);
        void setAcl(const CannedAccessControlList& acl);
        void setTagging(const std::string& value);
        void setTrafficLimit(uint64_t value);
        virtual std::shared_ptr<std::iostream> Body() const;
    protected:
        virtual HeaderCollection specialHeaders() const ;
        virtual ParameterCollection specialParameters() const;
    private:
        uint64_t position_;
        std::shared_ptr<std::iostream> content_;
        ObjectMetaData metaData_;
    };
}
}

