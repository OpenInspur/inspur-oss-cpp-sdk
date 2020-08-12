#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectMetaRequest : public OssObjectRequest
    {
    public:
        GetObjectMetaRequest(const std::string& bucket, const std::string& key):
            OssObjectRequest(bucket, key)
        {
        }
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
