#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/CORSRule.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketCorsRequest : public OssBucketRequest
    {
    public:
        SetBucketCorsRequest(const std::string& bucket);
        void addCORSRule(const CORSRule& rule);
        void setCORSRules(const CORSRuleList& rules);
        void clearCORSRules() { ruleList_.clear(); }
        const CORSRuleList& CORSRules() const { return ruleList_; }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        CORSRuleList ruleList_;
    };
} 
}
