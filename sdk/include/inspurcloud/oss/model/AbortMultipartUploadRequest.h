
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT AbortMultipartUploadRequest: public OssObjectRequest
    {
    public:
        AbortMultipartUploadRequest(const std::string& bucket, const std::string& key, 
            const std::string& uploadId);
    protected:
        virtual ParameterCollection specialParameters() const;
    private:
        std::string uploadId_;
    };
} 
}