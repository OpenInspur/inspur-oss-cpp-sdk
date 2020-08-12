
#include <inspurcloud/oss/model/GeneratePresignedUrlRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include <sstream>
#include <chrono>
using namespace InspurCloud::OSS;

GeneratePresignedUrlRequest::GeneratePresignedUrlRequest(const std::string &bucket, const std::string &key) :
    GeneratePresignedUrlRequest(bucket, key, Http::Method::Get)
{
}

GeneratePresignedUrlRequest::GeneratePresignedUrlRequest(const std::string &bucket, const std::string &key, Http::Method method):
    bucket_(bucket),
    key_(key),
    method_(method)
{
    //defalt 15 min
    std::time_t t = std::time(nullptr) + 15*60;
    metaData_.setExpirationTime(std::to_string(t));
}

void GeneratePresignedUrlRequest::setBucket(const std::string &bucket)
{
    bucket_ = bucket;
}

void GeneratePresignedUrlRequest::setKey(const std::string &key)
{
    key_ = key;
}

void GeneratePresignedUrlRequest::setContentType(const std::string &value)
{
    metaData_.HttpMetaData()[Http::CONTENT_TYPE] = value;
}

void GeneratePresignedUrlRequest::setContentMd5(const std::string &value)
{
    metaData_.HttpMetaData()[Http::CONTENT_MD5] = value;
}

void GeneratePresignedUrlRequest::setExpires(int64_t unixTime)
{
    metaData_.setExpirationTime(std::to_string(unixTime));
}

void GeneratePresignedUrlRequest::setProcess(const std::string &value)
{
    parameters_["x-oss-process"] = value;
}

void GeneratePresignedUrlRequest::setTrafficLimit(uint64_t value)
{
    parameters_["x-oss-traffic-limit"] = std::to_string(value);
}

void GeneratePresignedUrlRequest::addResponseHeaders(RequestResponseHeader header, const std::string &value)
{
    static const char *ResponseHeader[] = {
        "response-content-type", "response-content-language",
        "response-expires", "response-cache-control",
        "response-content-disposition", "response-content-encoding" };
    parameters_[ResponseHeader[header - RequestResponseHeader::ContentType]] = value;
}

void GeneratePresignedUrlRequest::addParameter(const std::string&key, const std::string &value)
{
    parameters_[key] = value;
}

MetaData &GeneratePresignedUrlRequest::UserMetaData()
{
    return metaData_.UserMetaData();
}
