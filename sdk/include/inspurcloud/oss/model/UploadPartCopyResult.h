
#pragma once
#include <string>
#include <memory>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT UploadPartCopyResult :public OssResult
    {
    public:
        UploadPartCopyResult();
        UploadPartCopyResult(const std::string& data);
        UploadPartCopyResult(const std::shared_ptr<std::iostream>& data,
             const HeaderCollection &header);
        UploadPartCopyResult& operator=(const std::string& data);
        const std::string& LastModified() const;
        const std::string& ETag() const;
     private:
        std::string sourceRange_;
        std::string lastModified_;
        std::string eTag_;
        HeaderCollection headers;
    };
}
}
