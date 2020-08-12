#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketRefererResult : public OssResult
    {
    public:
        GetBucketRefererResult();
        GetBucketRefererResult(const std::string& data);
        GetBucketRefererResult(const std::shared_ptr<std::iostream>& data);
        GetBucketRefererResult& operator=(const std::string& data);
        const InspurCloud::OSS::RefererList& RefererList() const { return refererList_;}
        bool AllowEmptyReferer() const { return allowEmptyReferer_; }
    private:
        InspurCloud::OSS::RefererList refererList_;
        bool allowEmptyReferer_;
    };
} 
}
