#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <vector>

namespace InspurCloud
{
namespace OSS
{
    class MultipartUpload
    {
    public:
        MultipartUpload() = default;
    public:
        std::string Key;
        std::string UploadId;
        std::string Initiated;
    };

    using MultipartUploadList = std::vector<MultipartUpload>;
    class INSPURCLOUD_OSS_EXPORT ListMultipartUploadsResult : public OssResult
    {
    public:
        ListMultipartUploadsResult();
        ListMultipartUploadsResult(const std::string& data);
        ListMultipartUploadsResult(const std::shared_ptr<std::iostream>& data);
        ListMultipartUploadsResult& operator=(const std::string& data);

        const std::string& Bucket() const { return bucket_; }
        const std::string& KeyMarker() const { return keyMarker_; }
        const std::string& UploadIdMarker() const { return uploadIdMarker_; }
        const std::string& EncodingType() const { return encodingType_; }
        const std::string& NextKeyMarker() const { return nextKeyMarker_; }
        const std::string& NextUploadIdMarker() const { return nextUploadIdMarker_; }
        uint32_t MaxUploads() const { return maxUploads_; }
        bool IsTruncated() const { return isTruncated_; }
        const CommonPrefixeList& CommonPrefixes() const { return commonPrefixes_; }
        const InspurCloud::OSS::MultipartUploadList& MultipartUploadList() const { return multipartUploadList_; }
    private:
        std::string bucket_;
        std::string keyMarker_;
        std::string uploadIdMarker_;
        std::string encodingType_;
        std::string nextKeyMarker_;
        std::string nextUploadIdMarker_;
        uint32_t maxUploads_;
        bool isTruncated_;
        CommonPrefixeList commonPrefixes_;
        InspurCloud::OSS::MultipartUploadList multipartUploadList_;
    };
} 
}
