#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/LifecycleRule.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketLifecycleResult : public OssResult
    {
    public:
        GetBucketLifecycleResult();
        GetBucketLifecycleResult(const std::string& data);
        GetBucketLifecycleResult(const std::shared_ptr<std::iostream>& data);
        GetBucketLifecycleResult& operator=(const std::string& data);
        const LifecycleRuleList& LifecycleRules() { return lifecycleRuleList_; }
    private:
        LifecycleRuleList lifecycleRuleList_;
    };
} 
}
