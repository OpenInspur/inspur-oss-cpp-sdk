#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketStorageCapacityRequest : public OssBucketRequest
    {
    public:
        SetBucketStorageCapacityRequest(const std::string& bucket, int64_t storageCapacity);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual std::string payload() const;
        virtual int validate() const;
    private:
        int64_t storageCapacity_;
    };
} 
}
