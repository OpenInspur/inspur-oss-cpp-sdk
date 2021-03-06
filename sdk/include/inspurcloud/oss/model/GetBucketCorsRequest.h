#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketCorsRequest: public OssBucketRequest
    {
    public:
        GetBucketCorsRequest(const std::string& bucket);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
