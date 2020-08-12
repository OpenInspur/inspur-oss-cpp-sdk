
#include <inspurcloud/oss/model/PutObjectResult.h>
#include "../utils/Utils.h"
#include <inspurcloud/oss/http/HttpType.h>
using namespace InspurCloud::OSS;

PutObjectResult::PutObjectResult():
    OssResult(),
    content_(nullptr)
{
}

PutObjectResult::PutObjectResult(const HeaderCollection& header, const std::shared_ptr<std::iostream>& content):
    PutObjectResult()
{
    if (header.find(Http::ETAG) != header.end())
    {
        eTag_ = TrimQuotes(header.at(Http::ETAG).c_str());
    }

    if (header.find("x-oss-hash-crc64ecma") != header.end()) {
        crc64_ = std::strtoull(header.at("x-oss-hash-crc64ecma").c_str(), nullptr, 10);
    }

    if (header.find("x-oss-request-id") != header.end()) {
        requestId_ = header.at("x-oss-request-id");
    }

    if (content != nullptr && content->peek() != EOF) {
        content_ = content;
    }
}

PutObjectResult::PutObjectResult(const HeaderCollection & header):
    PutObjectResult(header, nullptr)
{
}

const std::string& PutObjectResult::ETag() const
{
    return eTag_;
}

uint64_t PutObjectResult::CRC64() 
{
    return crc64_;
}

const std::shared_ptr<std::iostream>& PutObjectResult::Content() const
{
    return content_;
}
