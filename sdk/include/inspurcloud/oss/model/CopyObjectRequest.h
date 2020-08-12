
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>


namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CopyObjectRequest: public OssObjectRequest
    {
    public:
        CopyObjectRequest(const std::string& bucket, const std::string& key);
        CopyObjectRequest(const std::string& bucket, const std::string& key,
            const ObjectMetaData& meta);
        void setCopySource(const std::string& srcBucket,const std::string& srcObject);
        void setSourceIfMatchETag(const std::string& value);
        void setSourceIfNotMatchETag(const std::string& value);
        void setSourceIfUnModifiedSince(const std::string& value);
        void setSourceIfModifiedSince(const std::string& value);
        void setMetadataDirective(const CopyActionList& action);
        void setAcl(const CannedAccessControlList& acl);
        void setTagging(const std::string& value);
        void setTaggingDirective(const CopyActionList& action);
        void setTrafficLimit(uint64_t value);

    protected:
        virtual HeaderCollection specialHeaders() const ;
    private:
        ObjectMetaData metaData_;
    };
}
}

