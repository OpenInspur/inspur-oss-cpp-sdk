#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/ServiceRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>
#include <inspurcloud/oss/http/HttpType.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT PutObjectByUrlRequest : public ServiceRequest
    {
    public:
        PutObjectByUrlRequest(const std::string& url, 
            const std::shared_ptr<std::iostream>& content);
        PutObjectByUrlRequest(const std::string& url, 
            const std::shared_ptr<std::iostream>& content,
            const ObjectMetaData& metaData);
        virtual HeaderCollection Headers() const;
        virtual ParameterCollection Parameters() const;
        virtual std::shared_ptr<std::iostream> Body() const;
    private:
        std::shared_ptr<std::iostream> content_;
        ObjectMetaData metaData_;
    };
} 
}
