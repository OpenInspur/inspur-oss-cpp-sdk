
#include <inspurcloud/oss/model/SetObjectTaggingRequest.h>
#include <inspurcloud/oss/Const.h>
#include "../utils/Utils.h"
#include "ModelError.h"
#include <sstream>
using namespace InspurCloud::OSS;

SetObjectTaggingRequest::SetObjectTaggingRequest(const std::string& bucket, const std::string& key):
    OssObjectRequest(bucket, key)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

SetObjectTaggingRequest::SetObjectTaggingRequest(const std::string& bucket, const std::string& key,
    const Tagging& tagging):
    OssObjectRequest(bucket, key),
    tagging_(tagging)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

void SetObjectTaggingRequest::setTagging(const Tagging& tagging)
{
    tagging_ = tagging;
}


std::string SetObjectTaggingRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<Tagging>"  << std::endl;
    ss << "  <TagSet>" << std::endl;
    for (const auto& tag : tagging_.Tags()) {
        ss << "    <Tag><Key>"<< tag.Key() <<"</Key><Value>" << tag.Value() << "</Value></Tag>" << std::endl;
    }
    ss << "  </TagSet>" << std::endl;
    ss << "</Tagging>"  << std::endl;
    return ss.str();
}

ParameterCollection SetObjectTaggingRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["tagging"] = "";
    return parameters;
}

int SetObjectTaggingRequest::validate() const
{
    int ret;
    if ((ret = OssObjectRequest::validate()) != 0) {
        return ret;
    }

    if (tagging_.Tags().empty() || tagging_.Tags().size() > MaxTagSize) {
        return ARG_ERROR_TAGGING_TAGS_LIMIT;
    }

    for (const auto& tag : tagging_.Tags()) {

        if (!IsValidTagKey(tag.Key()))
            return ARG_ERROR_TAGGING_TAG_KEY_LIMIT;

        if (!IsValidTagValue(tag.Value()))
            return ARG_ERROR_TAGGING_TAG_VALUE_LIMIT;
    }

    return 0;
}