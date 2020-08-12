
#include <inspurcloud/oss/model/GetLiveChannelInfoRequest.h>
#include <sstream>
#include "../utils/Utils.h"
#include "ModelError.h"
#include "Const.h"


using namespace InspurCloud::OSS;

GetLiveChannelInfoRequest::GetLiveChannelInfoRequest(const std::string& bucket, 
    const std::string& channelName):
    LiveChannelRequest(bucket, channelName)
{

}

ParameterCollection GetLiveChannelInfoRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["live"] = "";
    return collection;
}

int GetLiveChannelInfoRequest::validate() const
{
    return LiveChannelRequest::validate();
}

