#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/LifecycleRule.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketLifecycleRequest : public OssBucketRequest
    {
    public:
        SetBucketLifecycleRequest(const std::string& bucket);
        void addLifecycleRule(const LifecycleRule& rule) { lifecycleRules_.push_back(rule); }
        void setLifecycleRules(const LifecycleRuleList& ruleList) { lifecycleRules_= ruleList; }
        void clearLifecycleRules() { lifecycleRules_.clear(); }
        const LifecycleRuleList& LifecycleRules() const { return lifecycleRules_; }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        LifecycleRuleList lifecycleRules_;
    };
} 
}
