#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT DeleteBucketRequest : public OssBucketRequest
    {
    public:
        DeleteBucketRequest(const std::string& bucket):
            OssBucketRequest(bucket)
        {
        }
    };
} 
}
