
#include <inspurcloud/oss/model/CreateSymlinkRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

CreateSymlinkRequest::CreateSymlinkRequest(const std::string &bucket, const std::string &key):
    OssObjectRequest(bucket, key)
{
}

CreateSymlinkRequest::CreateSymlinkRequest(const std::string &bucket, const std::string &key,
    const ObjectMetaData &metaData):
    OssObjectRequest(bucket, key),
    metaData_(metaData)     
{
}

void CreateSymlinkRequest::SetSymlinkTarget(const std::string& value)
{
    metaData_.addHeader("x-oss-symlink-target", value);
}

void CreateSymlinkRequest::setTagging(const std::string& value)
{
    metaData_.addHeader("x-oss-tagging", value);
}

HeaderCollection CreateSymlinkRequest::specialHeaders() const
{
	auto headers = metaData_.toHeaderCollection();
    auto baseHeaders = OssObjectRequest::specialHeaders();
    headers.insert(baseHeaders.begin(), baseHeaders.end());
    return headers;
}


ParameterCollection CreateSymlinkRequest::specialParameters() const
{
    ParameterCollection paramters;
    paramters["symlink"] = "";
    return paramters;
}


