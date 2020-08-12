#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT DeleteObjectTaggingRequest : public OssObjectRequest
    {
    public:
        DeleteObjectTaggingRequest(const std::string& bucket, const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
