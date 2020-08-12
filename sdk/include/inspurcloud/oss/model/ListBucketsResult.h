#pragma once
#include "Bucket.h"
#include <vector>
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListBucketsResult: public OssResult
    {
    public:
        ListBucketsResult();
        ListBucketsResult(const std::string& data);
        ListBucketsResult(const std::shared_ptr<std::iostream>& data);
        ListBucketsResult& operator=(const std::string& data);
        const std::string& Prefix() const { return prefix_; }
        const std::string& Marker() const { return marker_; }
        const std::string& NextMarker() const { return nextMarker_; }
        int MaxKeys() const { return maxKeys_; }
        bool IsTruncated() const { return isTruncated_; }
        const std::vector<Bucket>& Buckets() const { return buckets_; }
    private:
        std::string prefix_;
        std::string marker_;
        std::string nextMarker_;
        bool        isTruncated_;
        int         maxKeys_;
        std::vector<Bucket> buckets_;
    };
} 
}
