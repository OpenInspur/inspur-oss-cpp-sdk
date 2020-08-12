
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CreateSymlinkRequest: public OssObjectRequest
    {
    public:
        CreateSymlinkRequest(const std::string& bucket, const std::string& key);
        CreateSymlinkRequest(const std::string& bucket, const std::string& key,
            const ObjectMetaData& meta);
        void SetSymlinkTarget(const std::string& value);
        void setTagging(const std::string& value);
    protected:
        virtual HeaderCollection specialHeaders() const ;
        virtual ParameterCollection specialParameters() const;
    private:
        ObjectMetaData metaData_;
    };
}
}

