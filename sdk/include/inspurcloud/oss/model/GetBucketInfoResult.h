#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketInfoResult : public OssResult
    {
    public:
        GetBucketInfoResult();
        GetBucketInfoResult(const std::string& data);
        GetBucketInfoResult(const std::shared_ptr<std::iostream>& data);
        GetBucketInfoResult& operator=(const std::string& data);
        const std::string& Location() const { return location_; }
        const std::string& Name() const { return name_; }
        const std::string& CreationDate() const { return creationDate_; }
        const std::string& IntranetEndpoint() const { return intranetEndpoint_; }
        const std::string& ExtranetEndpoint() const { return extranetEndpoint_; }
        InspurCloud::OSS::StorageClass StorageClass() const { return storageClass_; }
        CannedAccessControlList Acl() const { return acl_; }
        const InspurCloud::OSS::Owner& Owner() { return owner_; }
    private:
        std::string location_;
        std::string name_;
        std::string creationDate_;
        std::string intranetEndpoint_;
        std::string extranetEndpoint_;
        InspurCloud::OSS::StorageClass storageClass_;
        CannedAccessControlList acl_;
        InspurCloud::OSS::Owner owner_;
    };
} 
}
