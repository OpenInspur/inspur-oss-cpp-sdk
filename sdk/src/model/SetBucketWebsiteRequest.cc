#include <inspurcloud/oss/model/SetBucketWebsiteRequest.h>
#include <sstream>
#include <../utils/Utils.h>
#include "ModelError.h"

using namespace InspurCloud::OSS;

SetBucketWebsiteRequest::SetBucketWebsiteRequest(const std::string& bucket) :
    OssBucketRequest(bucket),
    indexDocumentIsSet_(false),
    errorDocumentIsSet_(false)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketWebsiteRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<WebsiteConfiguration>" << std::endl;
    ss << "  <IndexDocument>" << std::endl;
    ss << "    <Suffix>" << indexDocument_ << "</Suffix>" << std::endl;
    ss << "  </IndexDocument>" << std::endl;
    if (errorDocumentIsSet_) {
        ss << "  <ErrorDocument>" << std::endl;
        ss << "    <Key>" << errorDocument_ << "</Key>" << std::endl;
        ss << "  </ErrorDocument>" << std::endl;
    }
    ss << "</WebsiteConfiguration>" << std::endl;
    return ss.str();
}

ParameterCollection SetBucketWebsiteRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["website"] = "";
    return parameters;
}

static bool IsValidWebpage(const std::string &webpage)
{
    const std::string pageSuffix = ".html";
    return (webpage.size() > pageSuffix.size()) &&
        (webpage.substr(webpage.size() - 5).compare(".html") == 0);
}

int SetBucketWebsiteRequest::validate() const
{
    int ret = OssBucketRequest::validate();
    if (ret != 0) 
        return ret;

    if (indexDocument_.empty())
        return ARG_ERROR_WEBSITE_INDEX_DOCCUMENT_EMPTY;

    if (!IsValidWebpage(indexDocument_))
        return ARG_ERROR_WEBSITE_INDEX_DOCCUMENT_NAME_INVALID;

    if (errorDocumentIsSet_ && !IsValidWebpage(errorDocument_))
        return ARG_ERROR_WEBSITE_ERROR_DOCCUMENT_NAME_INVALID;

    return 0;
}

