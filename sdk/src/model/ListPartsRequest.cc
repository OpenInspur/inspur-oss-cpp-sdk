
#include <set>
#include <sstream>
#include <inspurcloud/oss/model/ListPartsRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"
#include "ModelError.h"
#include <inspurcloud/oss/Const.h>


using namespace InspurCloud::OSS;
using std::stringstream;

ListPartsRequest::ListPartsRequest(const std::string &bucket,
     const std::string &key) :
    ListPartsRequest(bucket, key, std::string())
{
}

ListPartsRequest::ListPartsRequest(const std::string &bucket,
    const std::string &key, const std::string &uploadId) :
    OssObjectRequest(bucket, key),
    uploadId_(uploadId),
    maxPartsIsSet_(false),
    partNumberMarkerIsSet_(false),
    encodingTypeIsSet_(false)
{
}

void ListPartsRequest::setUploadId(const std::string &uploadId)
{
    uploadId_ = uploadId;
}

void ListPartsRequest::setEncodingType(const std::string &str)
{
    encodingType_ = str;
    encodingTypeIsSet_ = true;
}

void ListPartsRequest::setMaxParts(uint32_t maxParts)
{
    maxParts_ = maxParts > MaxReturnedKeys ? MaxReturnedKeys: maxParts;
    maxPartsIsSet_ = true;
}

void ListPartsRequest::setPartNumberMarker(uint32_t partNumberMarker)
{
    partNumberMarker_ = partNumberMarker;
    partNumberMarkerIsSet_ = true;
}

ParameterCollection ListPartsRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["uploadId"] = uploadId_;

    if (maxPartsIsSet_) {
        parameters["max-parts"] = std::to_string(maxParts_);
    }

    if (partNumberMarkerIsSet_) {
        parameters["part-number-marker"] = std::to_string(partNumberMarker_);
    }

    if (encodingTypeIsSet_) {
        parameters["encoding-type"] = encodingType_;
    }

    return parameters;
}
