
#include <inspurcloud/oss/model/GetLiveChannelStatRequest.h>
#include <sstream>
#include "../utils/Utils.h"
#include "ModelError.h"
#include "Const.h"


using namespace InspurCloud::OSS;

GetLiveChannelStatRequest::GetLiveChannelStatRequest(const std::string& bucket, 
    const std::string& channelName):
    LiveChannelRequest(bucket, channelName)
{

}

ParameterCollection GetLiveChannelStatRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["live"] = "";
    collection["comp"] = "stat";
    return collection;
}

int GetLiveChannelStatRequest::validate() const
{
    return LiveChannelRequest::validate();
}
