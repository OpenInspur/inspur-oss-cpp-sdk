
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT InitiateMultipartUploadRequest: public OssObjectRequest
    {
    public:
        InitiateMultipartUploadRequest(const std::string& bucket, const std::string& key);
        InitiateMultipartUploadRequest(const std::string& bucket, const std::string& key,
            const ObjectMetaData& metaData);
        void setCacheControl(const std::string& value);
        void setContentDisposition(const std::string& value);
        void setContentEncoding(const std::string& value);
        void setExpires(const std::string& value);
        ObjectMetaData& MetaData();
        void setEncodingType(const std::string& encodingType);
        void setTagging(const std::string& value);
        void setServerSideEncryption(const SSEAlgorithm sse, const std::string& value = "");

    protected:
        virtual HeaderCollection specialHeaders() const;
        virtual ParameterCollection specialParameters() const;
    private:
        ObjectMetaData metaData_;
        std::string encodingType_;
        bool encodingTypeIsSet_;
    };
} 
}
