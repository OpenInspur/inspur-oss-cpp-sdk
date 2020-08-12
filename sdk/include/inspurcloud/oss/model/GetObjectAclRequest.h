#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectAclRequest: public OssObjectRequest
    {
    public:
        GetObjectAclRequest(const std::string& bucket, const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
} 
}
