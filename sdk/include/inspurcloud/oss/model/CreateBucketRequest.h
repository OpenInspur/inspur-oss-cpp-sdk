#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CreateBucketRequest: public OssBucketRequest
    {
    public:
        CreateBucketRequest(const std::string& bucket, StorageClass storageClass = StorageClass::Standard);
        CreateBucketRequest(const std::string& bucket, StorageClass storageClass, 
            CannedAccessControlList acl);
		void SetRegion(std::string region) {
			issetregion_ = true;
			region_ = region;
		}
    protected:
        virtual std::string payload() const;
        virtual HeaderCollection specialHeaders() const;
		
    private:
		std::string region_;
		bool issetregion_;
        StorageClass storageClass_;
        CannedAccessControlList acl_;
    };
} 
}
