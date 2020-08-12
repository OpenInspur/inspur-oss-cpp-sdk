#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectAclResult : public OssResult
    {
    public:
        GetObjectAclResult();
        GetObjectAclResult(const std::string& data);
        GetObjectAclResult(const std::shared_ptr<std::iostream>& data);
        GetObjectAclResult& operator=(const std::string& data);
        const InspurCloud::OSS::Owner& Owner() { return owner_; }
        CannedAccessControlList Acl()const  { return acl_; }
    private:
        InspurCloud::OSS::Owner owner_;
        CannedAccessControlList acl_;
    };
} 
}

