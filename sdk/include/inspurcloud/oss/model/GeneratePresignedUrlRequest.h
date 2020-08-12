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
    class OssClientImpl;
    class INSPURCLOUD_OSS_EXPORT GeneratePresignedUrlRequest
    {
    public:
        GeneratePresignedUrlRequest(const std::string& bucket, const std::string& key);
        GeneratePresignedUrlRequest(const std::string& bucket, const std::string& key,
            Http::Method method);
        void setBucket(const std::string& bucket);
        void setKey(const std::string& key);
        void setContentType(const std::string& value);
        void setContentMd5(const std::string& value);
        void setExpires(int64_t unixTime);
        void setProcess(const std::string& process);
        void setTrafficLimit(uint64_t value);
        void addResponseHeaders(RequestResponseHeader header, const std::string& value);
        void addParameter(const std::string& key, const std::string& value);
        MetaData& UserMetaData();
    private:
        friend class OssClientImpl;
        std::string bucket_;
        std::string key_;
        Http::Method method_;
        ObjectMetaData metaData_;
        ParameterCollection parameters_;
    };
} 
}
