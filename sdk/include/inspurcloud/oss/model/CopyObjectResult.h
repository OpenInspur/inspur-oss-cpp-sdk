#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CopyObjectResult : public OssResult
    {
    public:
        CopyObjectResult();
        CopyObjectResult(const std::string& data);
        CopyObjectResult(const std::shared_ptr<std::iostream>& data);
        CopyObjectResult& operator=(const std::string& data);
        const std::string& ETag() const { return etag_; }
        const std::string& LastModified() const { return lastModified_; }

        void setEtag(const std::string& etag) { etag_ = etag; }
        void setLastModified(const std::string& lastModified) { lastModified_ = lastModified; }
     private:
        std::string etag_;
        std::string lastModified_;
    };
} 
}

