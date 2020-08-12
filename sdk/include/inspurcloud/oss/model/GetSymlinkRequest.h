
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

#include <string>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetSymlinkRequest: public OssObjectRequest
    {
    public:
        GetSymlinkRequest(const std::string& bucket, const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
}
}

