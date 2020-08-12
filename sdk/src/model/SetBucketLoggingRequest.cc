#include <inspurcloud/oss/model/SetBucketLoggingRequest.h>
#include <sstream>
#include <../utils/Utils.h>
#include "ModelError.h"

using namespace InspurCloud::OSS;

SetBucketLoggingRequest::SetBucketLoggingRequest(const std::string& bucket) :
    SetBucketLoggingRequest(bucket, "", "")
{
}

SetBucketLoggingRequest::SetBucketLoggingRequest(const std::string& bucket,
    const std::string& targetBucket, const std::string& targetPrefix) :
    OssBucketRequest(bucket),
    targetBucket_(targetBucket),
    targetPrefix_(targetPrefix)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

std::string SetBucketLoggingRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<BucketLoggingStatus>" << std::endl;
    ss << "<LoggingEnabled>" << std::endl;
    ss << "<TargetBucket>" << targetBucket_ << "</TargetBucket>" << std::endl;
    ss << "<TargetPrefix>" << targetPrefix_ << "</TargetPrefix>" << std::endl;
    ss << "</LoggingEnabled>" << std::endl;
    ss << "</BucketLoggingStatus>" << std::endl;
    return ss.str();
}

ParameterCollection SetBucketLoggingRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["logging"] = "";
    return parameters;
}

int SetBucketLoggingRequest::validate() const
{
    int ret;
    if ((ret = OssBucketRequest::validate()) != 0 ) {
        return ret;
    }

    if (!IsValidBucketName(targetBucket_)) {
        return ARG_ERROR_BUCKET_NAME;
    }

    if (!IsValidLoggingPrefix(targetPrefix_)) {
        return ARG_ERROR_LOGGING_TARGETPREFIX_INVALID;
    }

    return 0;
}
