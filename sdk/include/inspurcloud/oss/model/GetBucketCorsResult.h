#pragma once
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/CORSRule.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetBucketCorsResult : public OssResult
    {
    public:
        GetBucketCorsResult();
        GetBucketCorsResult(const std::string& data);
        GetBucketCorsResult(const std::shared_ptr<std::iostream>& data);
        GetBucketCorsResult& operator=(const std::string& data);
        const CORSRuleList& CORSRules() const { return ruleList_; };
    private:
        CORSRuleList ruleList_;
    };
} 
}
