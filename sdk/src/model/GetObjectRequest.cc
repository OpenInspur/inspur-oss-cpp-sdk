
#include <inspurcloud/oss/model/GetObjectRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include "ModelError.h"
#include <set>
#include <sstream>
using namespace InspurCloud::OSS;

GetObjectRequest::GetObjectRequest(const std::string &bucket, const std::string &key):
    GetObjectRequest(bucket, key, "")
{
}

GetObjectRequest::GetObjectRequest(const std::string &bucket, const std::string &key, const std::string &process) :
    OssObjectRequest(bucket, key),
    rangeIsSet_(false),
    process_(process),
    trafficLimit_(0)
{
    setFlags(Flags() | REQUEST_FLAG_CHECK_CRC64);
}

GetObjectRequest::GetObjectRequest(const std::string& bucket, const std::string& key,
    const std::string &modifiedSince, const std::string &unmodifiedSince,
    const std::vector<std::string> &matchingETags, const std::vector<std::string> &nonmatchingETags,
    const std::map<std::string, std::string> &responseHeaderParameters_) : 
    OssObjectRequest(bucket, key),
    rangeIsSet_(false), 
    modifiedSince_(modifiedSince), 
    unmodifiedSince_(unmodifiedSince), 
    matchingETags_(matchingETags),
    nonmatchingETags_(nonmatchingETags), 
    process_(""),
    responseHeaderParameters_(responseHeaderParameters_),
    trafficLimit_(0)
{
}

void GetObjectRequest::setRange(int64_t start, int64_t end)
{
    range_[0] = start;
    range_[1] = end;
    rangeIsSet_ = true;
}

void GetObjectRequest::setModifiedSinceConstraint(const std::string &gmt)
{
    modifiedSince_ = gmt;
}

void GetObjectRequest::setUnmodifiedSinceConstraint(const std::string &gmt)
{
    unmodifiedSince_ = gmt;
}

void GetObjectRequest::setMatchingETagConstraints(const std::vector<std::string> &match)
{
    matchingETags_ = match;
}

void GetObjectRequest::addMatchingETagConstraint(const std::string &match)
{
    matchingETags_.push_back(match);
}

void GetObjectRequest::setNonmatchingETagConstraints(const std::vector<std::string> &match)
{
    nonmatchingETags_ = match;
}

void GetObjectRequest::addNonmatchingETagConstraint(const std::string &match)
{
    nonmatchingETags_.push_back(match);
}

void GetObjectRequest::setProcess(const std::string &process)
{
    process_ = process;
}

void GetObjectRequest::addResponseHeaders(RequestResponseHeader header, const std::string &value)
{
    static const char *ResponseHeader[] = {
        "response-content-type", "response-content-language", 
        "response-expires", "response-cache-control", 
        "response-content-disposition", "response-content-encoding"};
    responseHeaderParameters_[ResponseHeader[header - RequestResponseHeader::ContentType]] = value;
}

void GetObjectRequest::setTrafficLimit(uint64_t value)
{
    trafficLimit_ = value;
}

void GetObjectRequest::setCustomerSSEKey(const std::string &value)
{
    CustomerSSEKey_ = value;
}

int GetObjectRequest::validate() const
{
    int ret = OssObjectRequest::validate();
    if (ret != 0)
        return ret;

    if (rangeIsSet_ && (range_[0] < 0 || range_[1] < -1 || (range_[1] > -1 && range_[1] < range_[0]) ))
        return ARG_ERROR_OBJECT_RANGE_INVALID;

    return 0;
}

HeaderCollection GetObjectRequest::specialHeaders() const
{
    auto headers = OssObjectRequest::specialHeaders();
    if (rangeIsSet_) {
        std::stringstream ss;
        ss << "bytes=" << range_[0] << "-";
        if (range_[1] != -1) ss << range_[1];
        headers[Http::RANGE] = ss.str();
    }

    if (!modifiedSince_.empty())
    {
        headers["If-Modified-Since"] = modifiedSince_;
    }

    if (!unmodifiedSince_.empty())
    {
        headers["If-Unmodified-Since"] = unmodifiedSince_;
    }

    if (matchingETags_.size() > 0) {
        std::stringstream ss;
        bool first = true;
        for (auto const& str : matchingETags_) {
            if (!first) {
                ss << ",";
            }
            ss << str;
            first = false;
        }
        headers["If-Match"] = ss.str();
    }

    if (nonmatchingETags_.size() > 0) {
        std::stringstream ss;
        bool first = true;
        for (auto const& str : nonmatchingETags_) {
            if (!first) {
                ss << ",";
            }
            ss << str;
            first = false;
        }
        headers["If-None-Match"] = ss.str();
    }

    if (trafficLimit_ != 0) {
        headers["x-oss-traffic-limit"] = std::to_string(trafficLimit_);
    }

    if(!CustomerSSEKey_.empty()){
        headers["x-oss-server-side-encryption-customer-algorithm"]="AES256";
        std::string bas64key = Base64Encode(CustomerSSEKey_);
        headers["x-oss-server-side-encryption-customer-key"]=bas64key;
        std::string keymd5 = ComputeMD5(CustomerSSEKey_);
        std::string base64md5 = Base64Encode(keymd5);
        headers["x-oss-server-side-encryption-customer-key-md5"]=base64md5;
    }

    return headers;
}

ParameterCollection GetObjectRequest::specialParameters() const
{
    ParameterCollection parameters;
    for (auto const& param : responseHeaderParameters_) {
        parameters[param.first] = param.second;
    }

    if (!process_.empty()) {
        parameters["x-oss-process"] = process_;
    }

    return parameters;
}
