
#include <inspurcloud/oss/model/CreateSymlinkResult.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

CreateSymlinkResult::CreateSymlinkResult():
    OssResult()
{
}

CreateSymlinkResult::CreateSymlinkResult(const std::string& etag):
    OssResult(),
    etag_(TrimQuotes(etag.c_str()))
{
}

