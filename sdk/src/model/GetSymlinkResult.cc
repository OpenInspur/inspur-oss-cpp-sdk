
#include <inspurcloud/oss/model/GetSymlinkResult.h>
using namespace InspurCloud::OSS;

GetSymlinkResult::GetSymlinkResult():
    OssResult()
{
}

GetSymlinkResult::GetSymlinkResult(const std::string& symlink,
    const std::string& etag) :
    OssResult(),
    symlink_(symlink),
    etag_(etag)
{
}

