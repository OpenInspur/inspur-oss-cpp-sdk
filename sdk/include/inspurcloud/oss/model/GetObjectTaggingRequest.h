#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectTaggingRequest : public OssObjectRequest
    {
    public:
        GetObjectTaggingRequest(const std::string& bucket, const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
