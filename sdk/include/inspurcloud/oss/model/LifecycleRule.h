#pragma once
#include <string>
#include <vector>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/Tagging.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT LifeCycleExpiration
    {
    public:
        LifeCycleExpiration();
        LifeCycleExpiration(uint32_t days);
        LifeCycleExpiration(const std::string& createdBeforeDate);
        void setDays(uint32_t days);
        void setCreatedBeforeDate(const std::string& date);
        uint32_t Days() const { return days_; }
        const std::string& CreatedBeforeDate() const { return createdBeforeDate_; }
    private:
        uint32_t days_;
        std::string createdBeforeDate_;
    };

    class INSPURCLOUD_OSS_EXPORT LifeCycleTransition
    {
    public:
        LifeCycleTransition() = default;
        LifeCycleTransition(const LifeCycleExpiration& expiration, InspurCloud::OSS::StorageClass storageClass);
        void setExpiration(const LifeCycleExpiration& expiration);
        void setStorageClass(InspurCloud::OSS::StorageClass storageClass);
        const LifeCycleExpiration& Expiration() const { return expiration_; }
        LifeCycleExpiration& Expiration() { return expiration_; }
        InspurCloud::OSS::StorageClass StorageClass() const { return storageClass_; }
    private:
        LifeCycleExpiration expiration_;
        InspurCloud::OSS::StorageClass storageClass_;
    };

    using LifeCycleTransitionList = std::vector<LifeCycleTransition>;

    class INSPURCLOUD_OSS_EXPORT LifecycleRule
    {
    public:
        LifecycleRule() = default;
        const std::string& ID() const { return id_; }
        const std::string& Prefix() const { return prefix_; }
        RuleStatus Status() const {  return status_;}
        const LifeCycleExpiration& Expiration() const { return expiration_; }
        const LifeCycleTransitionList& TransitionList() const { return transitionList_; }
        const LifeCycleExpiration& AbortMultipartUpload() const { return abortMultipartUpload_; }
        LifeCycleExpiration& Expiration() { return expiration_; }
        LifeCycleTransitionList& TransitionList() { return transitionList_; }
        LifeCycleExpiration& AbortMultipartUpload() { return abortMultipartUpload_; }
        const TagSet& Tags() const { return tagSet_; }
        void setID(const std::string& id) { id_ = id; }
        void setPrefix(const std::string& prefix) { prefix_ = prefix; }
        void setStatus(RuleStatus status) { status_ = status; }
        void setExpiration(const LifeCycleExpiration& expiration) { expiration_ = expiration; }
        void addTransition(const LifeCycleTransition&transition) { transitionList_.push_back(transition); }
        void setTransitionList(const LifeCycleTransitionList& transitionList) { transitionList_ = transitionList; }
        void setAbortMultipartUpload(const LifeCycleExpiration& expiration) { abortMultipartUpload_ = expiration; }
        void addTag(const Tag& tag) { tagSet_.push_back(tag); }
        void setTags(const TagSet& tags) { tagSet_ = tags; }
        bool hasExpiration() const;
        bool hasTransitionList() const;
        bool hasAbortMultipartUpload() const;
        bool operator==(const LifecycleRule& right) const;
    private:
        std::string id_;
        std::string prefix_;
        RuleStatus status_;
        LifeCycleExpiration expiration_;
        LifeCycleTransitionList transitionList_;
        LifeCycleExpiration abortMultipartUpload_;
        TagSet tagSet_;
    };
    using LifecycleRuleList = std::vector<LifecycleRule>;
} 
}
