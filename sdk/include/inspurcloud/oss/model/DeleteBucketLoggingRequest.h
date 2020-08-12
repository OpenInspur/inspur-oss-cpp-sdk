#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT DeleteBucketLoggingRequest : public OssBucketRequest
    {
    public:
        DeleteBucketLoggingRequest(const std::string& bucket);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
