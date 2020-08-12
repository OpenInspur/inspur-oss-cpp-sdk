
#include <inspurcloud/oss/model/PostVodPlaylistRequest.h>
#include <sstream>
#include "../utils/Utils.h"
#include "ModelError.h"
#include "Const.h"


using namespace InspurCloud::OSS;

PostVodPlaylistRequest::PostVodPlaylistRequest(const std::string& bucket, 
    const std::string& channelName, const std::string& playlist,
    uint64_t startTime, uint64_t endTime)
    :LiveChannelRequest(bucket, channelName), 
    playList_(playlist),
    startTime_(startTime), 
    endTime_(endTime)
{
    key_.append("/").append(playList_);
}

int PostVodPlaylistRequest::validate() const
{
    int ret = LiveChannelRequest::validate();

    if(ret)
    {
        return ret;
    }

    if(!IsValidPlayListName(playList_))
    {
        return ARG_ERROR_LIVECHANNEL_BAD_PALYLIST_PARAM;
    }
    if(endTime_ <= startTime_ || endTime_ > (startTime_ + SecondsOfDay))
    {
        return ARG_ERROR_LIVECHANNEL_BAD_TIME_PARAM;
    }
    return 0;
}

ParameterCollection PostVodPlaylistRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["vod"] = "";
    collection["endTime"] = std::to_string(endTime_);
    collection["startTime"] = std::to_string(startTime_);
    return collection;
}

void PostVodPlaylistRequest::setPlayList(const std::string &playList)
{
    playList_ = playList;
}

void PostVodPlaylistRequest::setStartTime(uint64_t startTime)
{
    startTime_ = startTime;
}

void PostVodPlaylistRequest::setEndTime(uint64_t endTime)
{
    endTime_ = endTime;
}

