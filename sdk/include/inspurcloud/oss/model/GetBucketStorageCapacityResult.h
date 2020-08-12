#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketStorageCapacityResult : public OssResult
    {
    public:
        GetBucketStorageCapacityResult();
        GetBucketStorageCapacityResult(const std::string& data);
        GetBucketStorageCapacityResult(const std::shared_ptr<std::iostream>& data);
        GetBucketStorageCapacityResult& operator=(const std::string& data);
        int64_t StorageCapacity() const  { return storageCapacity_; }
    private:
        int64_t storageCapacity_;
    };
} 
}
