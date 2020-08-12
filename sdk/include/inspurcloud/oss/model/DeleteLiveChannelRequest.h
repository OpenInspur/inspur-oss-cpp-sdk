#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT DeleteLiveChannelRequest : public LiveChannelRequest
    {
    public:
        DeleteLiveChannelRequest(const std::string& bucket, const std::string& channelName);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    };
} 
}
