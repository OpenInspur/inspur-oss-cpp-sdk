
#include <inspurcloud/oss/model/GenerateRTMPSignedUrlRequest.h>
#include <sstream>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

GenerateRTMPSignedUrlRequest::GenerateRTMPSignedUrlRequest(
    const std::string& bucket, 
    const std::string& channelName, const std::string& playlist,
    uint64_t expires):
    LiveChannelRequest(bucket, channelName),
    playList_(playlist),
    expires_(expires)
{

}

ParameterCollection GenerateRTMPSignedUrlRequest::Parameters() const
{
    ParameterCollection collection;
    if(!playList_.empty())
    {
        collection["playlistName"] = playList_;
    }
    return collection;
}

void GenerateRTMPSignedUrlRequest::setPlayList(const std::string &playList)
{
    playList_ = playList;
}

void GenerateRTMPSignedUrlRequest::setExpires(uint64_t expires)
{
    expires_ = expires;
}

const std::string& GenerateRTMPSignedUrlRequest::PlayList() const
{
    return playList_;
}

uint64_t GenerateRTMPSignedUrlRequest::Expires() const
{
    return expires_;
}

