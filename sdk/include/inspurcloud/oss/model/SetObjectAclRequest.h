#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <string>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetObjectAclRequest: public OssObjectRequest
    {
    public:
        SetObjectAclRequest(const std::string& bucket, const std::string& key);
        SetObjectAclRequest(const std::string& bucket, const std::string& key,
            CannedAccessControlList acl);
        void setAcl(CannedAccessControlList acl);
    protected:
        virtual HeaderCollection specialHeaders() const;
        virtual ParameterCollection specialParameters() const;
    private:
        CannedAccessControlList acl_;
        bool hasSetAcl_ ;
    };
} 
}
