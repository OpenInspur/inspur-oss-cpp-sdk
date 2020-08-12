

#include <inspurcloud/oss/model/InitiateMultipartUploadRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include <sstream>
using namespace InspurCloud::OSS;

InitiateMultipartUploadRequest::InitiateMultipartUploadRequest(const std::string &bucket, const std::string &key) :
    InitiateMultipartUploadRequest(bucket, key, ObjectMetaData())
{
}

InitiateMultipartUploadRequest::InitiateMultipartUploadRequest(const std::string &bucket, const std::string &key, 
                                                               const ObjectMetaData &metaData) :
    OssObjectRequest(bucket, key),
    metaData_(metaData),
    encodingTypeIsSet_(false)
{
}

void InitiateMultipartUploadRequest::setEncodingType(const std::string &encodingType)
{
    encodingType_ = encodingType;
    encodingTypeIsSet_ = true;
}

void InitiateMultipartUploadRequest::setCacheControl(const std::string &value)
{
    metaData_.addHeader(Http::CACHE_CONTROL, value);
}

void InitiateMultipartUploadRequest::setContentDisposition(const std::string &value)
{
    metaData_.addHeader(Http::CONTENT_DISPOSITION, value);
}

void InitiateMultipartUploadRequest::setContentEncoding(const std::string &value)
{
    metaData_.addHeader(Http::CONTENT_ENCODING, value);
}

void InitiateMultipartUploadRequest::setExpires(const std::string &value)
{
    metaData_.addHeader(Http::EXPIRES, value);
}

void InitiateMultipartUploadRequest::setTagging(const std::string& value)
{
    metaData_.addHeader("x-oss-tagging", value);
}

void InitiateMultipartUploadRequest::setServerSideEncryption(const SSEAlgorithm sse, const std::string& value)
{
    if(sse == SSEAlgorithm::AES256){
        metaData_.addHeader("x-oss-server-side-encryption", ToSSEAlgorithmName(sse));
    }
    if(sse == SSEAlgorithm::KMS){
        metaData_.addHeader("x-oss-server-side-encryption", ToSSEAlgorithmName(sse));
        metaData_.addHeader("x-oss-server-side-encryption-kms-key-id", value);
    }
    if(sse == SSEAlgorithm::CustomerAES256){
        metaData_.addHeader("x-oss-server-side-encryption-customer-algorithm", "AES256");
        std::string bas64key = Base64Encode(value);
        metaData_.addHeader("x-oss-server-side-encryption-customer-key", bas64key);
		std::string keymd5 = ComputeMD5(value);
        std::string base64md5 = Base64Encode(keymd5);
        metaData_.addHeader("x-oss-server-side-encryption-customer-key-md5", base64md5);
    }
}

ObjectMetaData &InitiateMultipartUploadRequest::MetaData()
{
    return metaData_;
}

HeaderCollection InitiateMultipartUploadRequest::specialHeaders() const
{
    auto headers = metaData_.toHeaderCollection();
    if (headers.find(Http::CONTENT_TYPE) == headers.end()) {
        headers[Http::CONTENT_TYPE] = LookupMimeType(Key());
    }

    auto baseHeaders = OssObjectRequest::specialHeaders();
    headers.insert(baseHeaders.begin(), baseHeaders.end());

    return headers;
}

ParameterCollection InitiateMultipartUploadRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["uploads"] = "";
    if (encodingTypeIsSet_)
    {
        parameters["encoding-type"] = encodingType_;
    }
    return parameters;
}
