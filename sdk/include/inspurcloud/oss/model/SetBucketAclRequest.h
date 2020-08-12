#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketAclRequest: public OssBucketRequest
    {
    public:
        SetBucketAclRequest(const std::string& bucket, CannedAccessControlList acl);
        void setAcl(CannedAccessControlList acl);
    protected:
        virtual HeaderCollection specialHeaders() const;
        virtual ParameterCollection specialParameters() const;
    private:
        CannedAccessControlList acl_;
    };
} 
}
