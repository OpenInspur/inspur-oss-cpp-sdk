/*
 
 *
 *
 
 **/

#include <inspurcloud/oss/model/UploadPartRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include "ModelError.h"
#include <inspurcloud/oss/Const.h>
using namespace InspurCloud::OSS;

UploadPartRequest::UploadPartRequest(const std::string &bucket, const std::string &key,
    const std::shared_ptr<std::iostream> &content) :
    UploadPartRequest(bucket, key, 0, "", content)
{
}

UploadPartRequest::UploadPartRequest(const std::string &bucket, const std::string &key,
    int partNumber, const std::string &uploadId,
    const std::shared_ptr<std::iostream> &content) :
    OssObjectRequest(bucket, key),
    partNumber_(partNumber),
    uploadId_(uploadId),
    content_(content),
    contentLengthIsSet_(false),
    trafficLimit_(0)
{
    setFlags(Flags() | REQUEST_FLAG_CHECK_CRC64);
}

void UploadPartRequest::setPartNumber(int partNumber)
{
    partNumber_ = partNumber;
}

void UploadPartRequest::setUploadId(const std::string &uploadId)
{
    uploadId_ = uploadId;
}

void UploadPartRequest::setConetent(const std::shared_ptr<std::iostream> &content)
{
    content_ = content;
}

void UploadPartRequest::setContentLength(uint64_t length)
{
    contentLength_ = length;
    contentLengthIsSet_ = true;
}

void UploadPartRequest::setTrafficLimit(uint64_t value)
{
    trafficLimit_ = value;
}

void UploadPartRequest::setCustomerSSEKey(const std::string &value)
{
    CustomerSSEKey_ = value;
}

std::shared_ptr<std::iostream> UploadPartRequest::Body() const
{
    return content_;
}

HeaderCollection UploadPartRequest::specialHeaders() const
{
    auto headers = OssObjectRequest::specialHeaders();
    headers[Http::CONTENT_TYPE] = "";
    if (contentLengthIsSet_) {
        headers[Http::CONTENT_LENGTH] = std::to_string(contentLength_);
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

ParameterCollection UploadPartRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["partNumber"] = std::to_string(partNumber_);
    parameters["uploadId"] = uploadId_;
    return parameters;
}

int UploadPartRequest::validate() const
{
    int ret = OssObjectRequest::validate();
    if (ret)
    {
        return ret;
    }

    if (content_ == nullptr) {
        return ARG_ERROR_REQUEST_BODY_NULLPTR;
    }

    if (content_->bad()) {
        return ARG_ERROR_REQUEST_BODY_BAD_STATE;
    }

    if (content_->fail()) {
        return ARG_ERROR_REQUEST_BODY_FAIL_STATE;
    }

    if (!(partNumber_ > 0 && partNumber_ < PartNumberUpperLimit)) {
        return ARG_ERROR_MULTIPARTUPLOAD_PARTNUMBER_RANGE;
    }

    uint64_t partSize;

    if (contentLengthIsSet_) {
        partSize = contentLength_;
    }
    else {
        partSize = GetIOStreamLength(*content_);
    }

    if (partSize > MaxFileSize) {
        return ARG_ERROR_MULTIPARTUPLOAD_PARTSIZE_RANGE;
    }

    return 0;
}

