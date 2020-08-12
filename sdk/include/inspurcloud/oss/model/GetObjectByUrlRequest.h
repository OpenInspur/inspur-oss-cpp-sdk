#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>
#include <inspurcloud/oss/http/HttpType.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectByUrlRequest: public ServiceRequest
    {
    public:
        GetObjectByUrlRequest(const std::string& url);
        GetObjectByUrlRequest(const std::string& url, const ObjectMetaData& metaData);
        virtual HeaderCollection Headers() const;
        virtual ParameterCollection Parameters() const;
        virtual std::shared_ptr<std::iostream> Body() const;
    private:
        ObjectMetaData metaData_;
    };
} 
}
