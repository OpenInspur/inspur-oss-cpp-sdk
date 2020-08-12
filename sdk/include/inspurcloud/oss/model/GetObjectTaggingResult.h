#pragma once
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Tagging.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectTaggingResult : public OssResult
    {
    public:
        GetObjectTaggingResult();
        GetObjectTaggingResult(const std::string& data);
        GetObjectTaggingResult(const std::shared_ptr<std::iostream>& data);
        GetObjectTaggingResult& operator=(const std::string& data);
        const InspurCloud::OSS::Tagging& Tagging() const { return tagging_; };
    private:
        InspurCloud::OSS::Tagging tagging_;
    };
} 
}
