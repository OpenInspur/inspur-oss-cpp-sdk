#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>
namespace InspurCloud
{
namespace OSS
{
    class ListPartsResult;
    class ResumableUploader;
    class ResumableCopier;
    class INSPURCLOUD_OSS_EXPORT Part
    {
    public:
        Part() :partNumber_(0), size_(0), cRC64_(0) {}
        Part(int32_t partNumber, const std::string& eTag):partNumber_(partNumber), eTag_(eTag){}
        int32_t PartNumber() const { return partNumber_; }
        int64_t Size() const { return size_; }
        uint64_t CRC64() const { return cRC64_; }
        const std::string& LastModified() const { return lastModified_; }
        const std::string& ETag() const { return eTag_; }
    private:
        friend class ListPartsResult;
        friend class ResumableUploader;
        friend class ResumableCopier;
        int32_t partNumber_;
        int64_t size_;
        uint64_t cRC64_;
        std::string lastModified_;
        std::string eTag_;
    };
    using PartList = std::vector<Part>;
}
}
