#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ProcessObjectRequest: public OssObjectRequest
    {
    public:
        ProcessObjectRequest(const std::string& bucket, const std::string& key);
        ProcessObjectRequest(const std::string& bucket, const std::string& key,
            const std::string& process);
        void setProcess(const std::string& process);

    protected:
        virtual ParameterCollection specialParameters() const;
        virtual std::string payload() const;
    private:
        std::string process_;
    };
} 
}