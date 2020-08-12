
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

#include <string>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT RestoreObjectRequest: public OssObjectRequest
    {
    public:
        RestoreObjectRequest(const std::string& bucket, const std::string& key);
    protected:
        virtual ParameterCollection specialParameters() const;
    };
}
}

