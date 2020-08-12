#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetSymlinkResult : public OssResult
    {
    public:
       public:
        GetSymlinkResult();
        GetSymlinkResult(const std::string& symlink,const std::string& etag);
        const std::string& SymlinkTarget() const { return symlink_; }
        const std::string& ETag() const { return etag_; }
     private:
        std::string symlink_;
        std::string etag_;
    };
} 
}

