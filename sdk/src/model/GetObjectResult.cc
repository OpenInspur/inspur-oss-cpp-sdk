
#include <inspurcloud/oss/model/GetObjectResult.h>
#include <inspurcloud/oss/http/HttpType.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

GetObjectResult::GetObjectResult() :
    OssResult()
{
}

GetObjectResult::GetObjectResult(
    const std::string &bucket,
    const std::string &key,
    const std::shared_ptr<std::iostream> &content,
    const HeaderCollection &headers):
    bucket_(bucket),
    key_(key),
    content_(content)
{
    metaData_  = headers;
    requestId_ = metaData_.HttpMetaData()["x-oss-request-id"];
    std::string etag = metaData_.HttpMetaData()[Http::ETAG];
    metaData_.HttpMetaData()[Http::ETAG] = TrimQuotes(etag.c_str());
}

GetObjectResult::GetObjectResult(
    const std::string& bucket, const std::string& key,
    const ObjectMetaData& metaData) :
    bucket_(bucket),
    key_(key)
{
    metaData_ = metaData;
    requestId_ = metaData_.HttpMetaData()["x-oss-request-id"];
}