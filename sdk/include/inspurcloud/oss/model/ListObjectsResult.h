#pragma once
#include <inspurcloud/oss/model/Bucket.h>
#include <vector>
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>

namespace InspurCloud
{
namespace OSS
{
    class ListObjectsResult;
    class INSPURCLOUD_OSS_EXPORT ObjectSummary
    {
    public:
        ObjectSummary() = default;
        const std::string& Key() const { return key_; }
        const std::string& ETag()const { return eTag_; }
        int64_t Size() const { return size_; }
        const std::string& LastModified() const { return lastModified_; }
        const std::string& StorageClass() const { return storageClass_; }
        const std::string& Type() const { return type_; }
        const InspurCloud::OSS::Owner& Owner() const { return owner_; }
    private:
        friend class ListObjectsResult;
        std::string key_;
        std::string eTag_;
        int64_t size_;
        std::string lastModified_;
        std::string storageClass_;
        std::string type_;
        InspurCloud::OSS::Owner owner_;
    };

    using ObjectSummaryList = std::vector<ObjectSummary>;

    class INSPURCLOUD_OSS_EXPORT ListObjectsResult : public OssResult
    {
    public:
        ListObjectsResult();
        ListObjectsResult(const std::string& data);
        ListObjectsResult(const std::shared_ptr<std::iostream>& data);
        ListObjectsResult& operator=(const std::string& data);
        const std::string& Name() const { return name_; }
        const std::string& Prefix() const { return prefix_; }
        const std::string& Marker() const { return marker_; }
        const std::string& NextMarker() const { return nextMarker_; }
        const std::string& Delimiter() const { return delimiter_; }
        const std::string& EncodingType() const { return encodingType_; }
        int MaxKeys() const { return maxKeys_; }
        bool IsTruncated() const { return isTruncated_; }
        const CommonPrefixeList& CommonPrefixes() const { return commonPrefixes_; }
        const ObjectSummaryList& ObjectSummarys() const { return objectSummarys_; }
    private:
        std::string name_;
        std::string prefix_;
        std::string marker_;
        std::string delimiter_;
        std::string nextMarker_;
        std::string encodingType_;
        bool        isTruncated_;
        int         maxKeys_;
        CommonPrefixeList commonPrefixes_;
        ObjectSummaryList objectSummarys_;
    };
} 
}
