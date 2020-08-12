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
    class INSPURCLOUD_OSS_EXPORT UploadObjectRequest : public OssResumableBaseRequest
    {
    public:
        UploadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath, const std::string& checkpointDir,
            const uint64_t partSize, const uint32_t threadNum);
        UploadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath, const std::string &checkpointDir,
            const uint64_t partSize, const uint32_t threadNum, const ObjectMetaData& meta);
        UploadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath, const std::string& checkpointDir,
            const ObjectMetaData& meta);
        UploadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath, const std::string& checkpointDir);
        UploadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath);

        std::shared_ptr<std::iostream> Content(){ return content_; }
        const std::string& EncodingType() const{return encodingType_;}
        const std::string& FilePath() const{return filePath_;}
        const ObjectMetaData& MetaData() const { return metaData_; }
        ObjectMetaData& MetaData() { return metaData_; }

        void setCacheControl(const std::string& value){metaData_.addHeader(Http::CACHE_CONTROL, value);}
        void setContentDisposition(const std::string& value){metaData_.addHeader(Http::CONTENT_DISPOSITION, value);}
        void setContentEncoding(const std::string& value){metaData_.addHeader(Http::CONTENT_ENCODING, value);}
        void setExpires(const std::string& value){metaData_.addHeader(Http::EXPIRES, value);}
        void setAcl(CannedAccessControlList& acl);
        void setCallback(const std::string& callback, const std::string& callbackVar = "");
        void setEncodingType(const std::string& type) {encodingType_ = type; }       
        void setTagging(const std::string& value);

    protected:
        virtual int validate() const;
    private:
        std::string filePath_;
        std::shared_ptr<std::iostream> content_;
        ObjectMetaData metaData_;
        std::string encodingType_;
    };
} 
}