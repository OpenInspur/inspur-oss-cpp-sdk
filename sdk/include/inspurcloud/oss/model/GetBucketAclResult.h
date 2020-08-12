#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketAclResult : public OssResult
    {
    public:
        GetBucketAclResult();
        GetBucketAclResult(const std::string& data);
        GetBucketAclResult(const std::shared_ptr<std::iostream>& data);
        GetBucketAclResult& operator=(const std::string& data);
        const InspurCloud::OSS::Owner& Owner() { return owner_; }
        CannedAccessControlList Acl()const  { return acl_; }
    private:
        InspurCloud::OSS::Owner owner_;
        CannedAccessControlList acl_;
    };
} 
}
