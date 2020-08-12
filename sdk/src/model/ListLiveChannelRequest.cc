
#include <inspurcloud/oss/model/ListLiveChannelRequest.h>
#include <sstream>
#include "ModelError.h"
#include "Const.h"

using namespace InspurCloud::OSS;

ListLiveChannelRequest::ListLiveChannelRequest(const std::string &bucket):
    OssBucketRequest(bucket), 
    maxKeys_(100)
{
    
}

ParameterCollection ListLiveChannelRequest::specialParameters() const
{
    ParameterCollection colletion;
    colletion["live"] = "";
    if(!marker_.empty())
    {
        colletion["marker"] = marker_;
    }
    if(!prefix_.empty())
    {
        colletion["prefix"] = prefix_;
    }
    if(0 != maxKeys_)
    {
        colletion["max-keys"] = std::to_string(maxKeys_);
    }
    return colletion;
}

int ListLiveChannelRequest::validate() const
{
    if(0 == maxKeys_ || MaxListLiveChannelKeys < maxKeys_)
    {
        return ARG_ERROR_LIVECHANNEL_BAD_MAXKEY_PARAM;
    }
    return OssBucketRequest::validate();
}

void ListLiveChannelRequest::setMarker(const std::string &marker)
{
    marker_ = marker;
}

void ListLiveChannelRequest::setPrefix(const std::string &prefix)
{
    prefix_ = prefix;
}

void ListLiveChannelRequest::setMaxKeys(uint32_t maxKeys)
{
    maxKeys_ = maxKeys;
}

