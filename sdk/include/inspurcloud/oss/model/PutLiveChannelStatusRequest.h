#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>
#include <inspurcloud/oss/http/HttpType.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT PutLiveChannelStatusRequest : public LiveChannelRequest
    {
    public:
        PutLiveChannelStatusRequest(const std::string& bucket, const std::string& channelName);
        PutLiveChannelStatusRequest(const std::string& bucket, const std::string& channelName, 
            LiveChannelStatus status);

        void setStatus(LiveChannelStatus status);

    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        std::string channelName_;
        LiveChannelStatus status_;
    };
} 
}
