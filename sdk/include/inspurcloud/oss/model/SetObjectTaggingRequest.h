#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/Tagging.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetObjectTaggingRequest : public OssObjectRequest
    {
    public:
        SetObjectTaggingRequest(const std::string& bucket, const std::string& key);
        SetObjectTaggingRequest(const std::string& bucket, const std::string& key, 
            const Tagging& tagging);
        void setTagging(const Tagging& tagging);
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        Tagging tagging_;
    };
} 
}
