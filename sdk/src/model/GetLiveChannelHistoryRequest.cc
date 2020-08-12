
#include <inspurcloud/oss/model/GetLiveChannelHistoryRequest.h>
#include <sstream>
#include "../utils/Utils.h"
#include "ModelError.h"
#include "Const.h"


using namespace InspurCloud::OSS;

GetLiveChannelHistoryRequest::GetLiveChannelHistoryRequest(const std::string& bucket, 
    const std::string& channelName):
    LiveChannelRequest(bucket, channelName)
{

}

ParameterCollection GetLiveChannelHistoryRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["live"] = "";
    collection["comp"] = "history";
    return collection;
}

int GetLiveChannelHistoryRequest::validate() const
{
    return LiveChannelRequest::validate();
}

