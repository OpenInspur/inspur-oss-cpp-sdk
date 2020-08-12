
#include <inspurcloud/oss/model/CreateSelectObjectMetaRequest.h>
#include <sstream>
#include "ModelError.h"
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

CreateSelectObjectMetaRequest::CreateSelectObjectMetaRequest(const std::string& bucket, const std::string& key) :
    OssObjectRequest(bucket, key), 
    inputFormat_(nullptr), 
    overWriteIfExists_(false)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

void CreateSelectObjectMetaRequest::setOverWriteIfExists(bool overWriteIfExists)
{
    overWriteIfExists_ = overWriteIfExists;
}

void CreateSelectObjectMetaRequest::setInputFormat(InputFormat& inputFormat)
{
    inputFormat_ = &inputFormat;
}

std::string CreateSelectObjectMetaRequest::payload() const
{
    std::stringstream ss;
    if (inputFormat_->Type() == "csv") {
        ss << "<CsvMetaRequest>" << std::endl;
        ss << inputFormat_->toXML(0) << std::endl;
        ss << "<OverwriteIfExists>" << (overWriteIfExists_ ? "true" : "false") << "</OverwriteIfExists>" << std::endl;
        ss << "</CsvMetaRequest>" << std::endl;
    }
    else {
        ss << "<JsonMetaRequest>" << std::endl;
        ss << inputFormat_->toXML(0) << std::endl;
        ss << "<OverwriteIfExists>" << (overWriteIfExists_ ? "true" : "false") << "</OverwriteIfExists>" << std::endl;
        ss << "</JsonMetaRequest>" << std::endl;
    }
    return ss.str();
}

int CreateSelectObjectMetaRequest::validate() const
{
    int ret = OssObjectRequest::validate();
    if (ret != 0) {
        return ret;
    }
    if (inputFormat_ == nullptr) {
        return ARG_ERROR_CREATE_SELECT_OBJECT_META_NULL_POINT;
    }
    return 0;
}

ParameterCollection CreateSelectObjectMetaRequest::specialParameters() const
{
    ParameterCollection parameters;
    if (inputFormat_) {
        auto type = inputFormat_->Type();
        type.append("/meta");
        parameters["x-oss-process"] = type;
    }
    return parameters;
}
