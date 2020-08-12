#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <vector>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketRefererRequest : public OssBucketRequest
    {
    public:
        SetBucketRefererRequest(const std::string& bucket);
        SetBucketRefererRequest(const std::string& bucket, const RefererList& refererList);
        SetBucketRefererRequest(const std::string& bucket, const RefererList& refererList,
            bool allowEmptyReferer);
        void setAllowEmptyReferer(bool allow) 
        { 
            allowEmptyReferer_ = allow; 
        }
        void addReferer(const std::string& referer)
        {
            refererList_.push_back(referer);
        }
        void clearRefererList()
        {
            refererList_.clear();
        }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
    private:
        bool allowEmptyReferer_;
        RefererList refererList_;
    };
} 
}
