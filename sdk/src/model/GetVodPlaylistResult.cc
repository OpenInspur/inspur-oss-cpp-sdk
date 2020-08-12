
#include <inspurcloud/oss/model/GetVodPlaylistResult.h>
#include <tinyxml2/tinyxml2.h>
#include <inspurcloud/oss/model/Bucket.h>
#include <inspurcloud/oss/model/Owner.h>
#include <sstream>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;



GetVodPlaylistResult::GetVodPlaylistResult():
    OssResult()
{
}

GetVodPlaylistResult::GetVodPlaylistResult(const std::string& result):
    GetVodPlaylistResult()
{
    *this = result;
}

GetVodPlaylistResult::GetVodPlaylistResult(const std::shared_ptr<std::iostream>& result):
    GetVodPlaylistResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetVodPlaylistResult& GetVodPlaylistResult::operator =(const std::string& result)
{
    playListContent_ = result;
    parseDone_ = true;
    return *this;
}

const std::string& GetVodPlaylistResult::PlaylistContent() const
{
    return playListContent_;
}
