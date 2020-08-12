#include <inspurcloud/oss/model/SetBucketEncryptionRequest.h>
#include <sstream>
#include "../utils/Utils.h"


using namespace InspurCloud::OSS;

SetBucketEncryptionRequest::SetBucketEncryptionRequest(const std::string& bucket, SSEAlgorithm sse, const std::string& key):
    OssBucketRequest(bucket),
    SSEAlgorithm_(sse),
    KMSMasterKeyID_(key)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

void SetBucketEncryptionRequest::setSSEAlgorithm(SSEAlgorithm sse)
{
    SSEAlgorithm_ = sse;
}

void SetBucketEncryptionRequest::setKMSMasterKeyID(const std::string& key)
{
    KMSMasterKeyID_ = key;
}

ParameterCollection SetBucketEncryptionRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["encryption"] = "";
    return parameters;
}

std::string SetBucketEncryptionRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<ServerSideEncryptionConfiguration>" << std::endl;
    ss << "<Rule>" << std::endl;
    ss << "<ApplyServerSideEncryptionByDefault>" << std::endl; 
    ss << "<SSEAlgorithm>" << ToSSEAlgorithmName(SSEAlgorithm_) << "</SSEAlgorithm>" << std::endl;
    ss << "<KMSMasterKeyID>" << KMSMasterKeyID_ << "</KMSMasterKeyID>" << std::endl;
    ss << "</ApplyServerSideEncryptionByDefault>" << std::endl;
    ss << "</Rule>" << std::endl;
    ss << "</ServerSideEncryptionConfiguration>" << std::endl;
    return ss.str();
}
