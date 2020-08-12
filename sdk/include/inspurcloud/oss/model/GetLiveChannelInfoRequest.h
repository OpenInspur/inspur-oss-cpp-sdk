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
    class INSPURCLOUD_OSS_EXPORT GetLiveChannelInfoRequest : public LiveChannelRequest
    {
    public:
        GetLiveChannelInfoRequest(const std::string& bucket, const std::string& channelName);

    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    };
} 
}
