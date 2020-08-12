
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/Part.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>
#include <sstream>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CompleteMultipartUploadRequest: public OssObjectRequest
    {
    public:
        CompleteMultipartUploadRequest(const std::string& bucket, const std::string& key);
        CompleteMultipartUploadRequest(const std::string& bucket, const std::string& key,
            const PartList& partList);
        CompleteMultipartUploadRequest(const std::string& bucket, const std::string& key, 
            const PartList& partList, 
            const std::string& uploadId);
        void setEncodingType(const std::string& encodingType);
        void setPartList(const InspurCloud::OSS::PartList& partList);
        void setUploadId(const std::string& uploadId);
        void setAcl(CannedAccessControlList acl);
        void setCallback(const std::string& callback, const std::string& callbackVar = "");
        ObjectMetaData& MetaData();
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual HeaderCollection specialHeaders() const;
        virtual int validate() const;
    private:
        InspurCloud::OSS::PartList partList_;
        std::string uploadId_;
        std::string encodingType_;
        bool encodingTypeIsSet_;
        ObjectMetaData metaData_;
    };
} 
}