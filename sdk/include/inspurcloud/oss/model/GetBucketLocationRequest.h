#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketLocationRequest: public OssBucketRequest
    {
    public:
        GetBucketLocationRequest(const std::string& bucket);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
