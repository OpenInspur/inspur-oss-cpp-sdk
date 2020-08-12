#include <inspurcloud/oss/model/SetBucketRefererRequest.h>
#include <sstream>

using namespace InspurCloud::OSS;

SetBucketRefererRequest::SetBucketRefererRequest(const std::string& bucket) :
    OssBucketRequest(bucket),
    allowEmptyReferer_(true)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

SetBucketRefererRequest::SetBucketRefererRequest(const std::string& bucket, const RefererList& refererList) :
    SetBucketRefererRequest(bucket, refererList, true)
{
}

SetBucketRefererRequest::SetBucketRefererRequest(const std::string& bucket, const RefererList& refererList,
    bool allowEmptyReferer) :
    OssBucketRequest(bucket),
    allowEmptyReferer_(allowEmptyReferer),
    refererList_(refererList)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketRefererRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<RefererConfiguration>" << std::endl;
    ss << "  <AllowEmptyReferer>" << (allowEmptyReferer_ ? "true" : "false") << "</AllowEmptyReferer>" << std::endl;
    ss << "  <RefererList>" << std::endl;
    for (const auto &referer : refererList_) {
        ss << "    <Referer>" << referer << "</Referer>" << std::endl;
    }
    ss << "  </RefererList>" << std::endl;
    ss << "</RefererConfiguration>" << std::endl;
    return ss.str();
}
ParameterCollection SetBucketRefererRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["referer"] = "";
    return parameters;
}
