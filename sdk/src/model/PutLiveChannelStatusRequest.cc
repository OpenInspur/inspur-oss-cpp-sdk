
#include <inspurcloud/oss/model/PutLiveChannelStatusRequest.h>
#include <sstream>
#include "../utils/Utils.h"
#include "ModelError.h"

using namespace InspurCloud::OSS;

PutLiveChannelStatusRequest::PutLiveChannelStatusRequest(const std::string& bucket, const std::string& channelName)
    :LiveChannelRequest(bucket, channelName),
    status_(LiveChannelStatus::EnabledStatus)
{

}

PutLiveChannelStatusRequest::PutLiveChannelStatusRequest(const std::string& bucket, 
    const std::string& channelName, LiveChannelStatus status)
    :LiveChannelRequest(bucket, channelName),
    status_(status)
{

}

ParameterCollection PutLiveChannelStatusRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["live"] = "";
    collection["status"] = ToLiveChannelStatusName(status_);
    return collection;
}

void PutLiveChannelStatusRequest::setStatus(LiveChannelStatus status)
{
    status_ = status;
}

int PutLiveChannelStatusRequest::validate() const
{
    int ret = LiveChannelRequest::validate();
    
    if (ret)
    {
        return ret;
    }

    if(status_ != LiveChannelStatus::EnabledStatus &&
        status_ != LiveChannelStatus::DisabledStatus)
    {
        return ARG_ERROR_LIVECHANNEL_BAD_STATUS_PARAM;
    }

    return 0;
}
