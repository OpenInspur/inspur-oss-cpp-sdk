
#include <inspurcloud/oss/model/AbortMultipartUploadRequest.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

AbortMultipartUploadRequest::AbortMultipartUploadRequest(
    const std::string &bucket, const std::string &key, const std::string &uploadId) :
    OssObjectRequest(bucket, key),
    uploadId_(uploadId)
{
}

ParameterCollection AbortMultipartUploadRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["uploadId"] = uploadId_;
    return parameters;
}
