#include <inspurcloud/oss/model/DeleteLiveChannelRequest.h>
#include "../utils/Utils.h"
#include "ModelError.h"

using namespace InspurCloud::OSS;

DeleteLiveChannelRequest::DeleteLiveChannelRequest(const std::string &bucket,
    const std::string &channelName)
    :LiveChannelRequest(bucket, channelName)
{

}

ParameterCollection DeleteLiveChannelRequest::specialParameters() const
{
    ParameterCollection collection;
    collection["live"] = "";
    return collection;
}

int DeleteLiveChannelRequest::validate() const
{
    return LiveChannelRequest::validate();
}
