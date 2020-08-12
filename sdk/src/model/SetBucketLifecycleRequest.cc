#include <inspurcloud/oss/model/SetBucketLifecycleRequest.h>
#include <inspurcloud/oss/Const.h>
#include <sstream>
#include <../utils/Utils.h>
#include "ModelError.h"

using namespace InspurCloud::OSS;

SetBucketLifecycleRequest::SetBucketLifecycleRequest(const std::string& bucket) :
    OssBucketRequest(bucket)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketLifecycleRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<LifecycleConfiguration>" << std::endl;
    for (auto const &rule : lifecycleRules_) 
    {
        ss << "  <Rule>" << std::endl;
        ss << "    <ID>" << rule.ID() << "</ID>" << std::endl;
        ss << "    <Prefix>" << rule.Prefix() << "</Prefix>" << std::endl;
        for (const auto& tag : rule.Tags())
        {
            ss << "    <Tag><Key>" << tag.Key() << "</Key><Value>" << tag.Value() << "</Value></Tag>" << std::endl;
        }
        ss << "    <Status>" << ToRuleStatusName(rule.Status()) << "</Status>" << std::endl;
        if (rule.hasExpiration())
        {
            ss << "    <Expiration>" << std::endl;
            if (rule.Expiration().Days() > 0) {
            ss << "      <Days>" << std::to_string(rule.Expiration().Days()) << "</Days>" << std::endl;
            } 
            else {
            ss << "      <CreatedBeforeDate>" << rule.Expiration().CreatedBeforeDate() << "</CreatedBeforeDate>" << std::endl;
            }
            ss << "    </Expiration>" << std::endl;
        }
        for (auto const & transition: rule.TransitionList())
        {
            ss << "    <Transition>" << std::endl;
            if (transition.Expiration().Days() > 0) {
            ss << "      <Days>" << std::to_string(transition.Expiration().Days()) << "</Days>" << std::endl;
            }
            else {
            ss << "      <CreatedBeforeDate>" << transition.Expiration().CreatedBeforeDate() << "</CreatedBeforeDate>" << std::endl;
            }
            ss << "      <StorageClass>" << ToStorageClassName(transition.StorageClass()) << "</StorageClass>" << std::endl;
            ss << "    </Transition>" << std::endl;
        }
        if (rule.hasAbortMultipartUpload())
        {
            ss << "    <AbortMultipartUpload>" << std::endl;
            if (rule.AbortMultipartUpload().Days() > 0) {
            ss << "      <Days>" << std::to_string(rule.AbortMultipartUpload().Days()) << "</Days>" << std::endl;
            }
            else {
            ss << "      <CreatedBeforeDate>" << rule.AbortMultipartUpload().CreatedBeforeDate() << "</CreatedBeforeDate>" << std::endl;
            }
            ss << "    </AbortMultipartUpload>" << std::endl;
        }
        ss << "  </Rule>" << std::endl;
    }
    ss << "</LifecycleConfiguration>" << std::endl;
    return ss.str();
}

ParameterCollection SetBucketLifecycleRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["lifecycle"] = "";
    return parameters;
}

int SetBucketLifecycleRequest::validate() const
{
    int ret;
    if ((ret = OssBucketRequest::validate()) != 0) {
        return ret;
    }

    if (lifecycleRules_.size() > LifecycleRuleLimit) {
        return ARG_ERROR_LIFECYCLE_RULE_LIMIT;
    }

    if (lifecycleRules_.empty()) {
        return ARG_ERROR_LIFECYCLE_RULE_EMPTY;
    }

    for (auto const &rule : lifecycleRules_) {
        //no config rule 
        if (!rule.hasAbortMultipartUpload() &&
            !rule.hasExpiration() &&
            !rule.hasTransitionList()) {
            return ARG_ERROR_LIFECYCLE_RULE_CONFIG_EMPTY;
        }

        if (rule.Prefix().empty() && lifecycleRules_.size() > 1) {
            return ARG_ERROR_LIFECYCLE_RULE_ONLY_ONE_FOR_BUCKET;
        }
    }

    return 0;
}
