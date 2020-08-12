#pragma once
#include <inspurcloud/oss/model/Bucket.h>
#include <vector>
#include <memory>
#include <iostream>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Part.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListPartsResult :public OssResult
    {
    public:
        ListPartsResult();
        ListPartsResult(const std::string& data);
        ListPartsResult(const std::shared_ptr<std::iostream>& data);
        ListPartsResult& operator=(const std::string& data);
        const std::string& Bucket() const;
        const std::string& Key() const;
        const std::string& UploadId() const;
        const std::string& EncodingType() const;
        uint32_t MaxParts() const;
        uint32_t PartNumberMarker() const;
        uint32_t NextPartNumberMarker() const;
        const InspurCloud::OSS::PartList& PartList()const;
        bool IsTruncated() const;
    private:
        std::string uploadId_;
        uint32_t maxParts_;
        uint32_t partNumberMarker_;
        uint32_t nextPartNumberMarker_;
        std::string encodingType_;
        std::string key_;
        std::string bucket_;
        bool isTruncated_;
        InspurCloud::OSS::PartList partList_;
    };
} 
}
