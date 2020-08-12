#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetLiveChannelInfoResult : public OssResult
    {
    public:
        GetLiveChannelInfoResult();
        GetLiveChannelInfoResult(const std::string& data);
        GetLiveChannelInfoResult(const std::shared_ptr<std::iostream>& data);
        GetLiveChannelInfoResult& operator=(const std::string& data);

        const std::string& Description() const;
        LiveChannelStatus Status() const;

        const std::string& Type() const;
        uint64_t FragDuration() const;
        uint64_t FragCount() const;
        const std::string& PlaylistName() const;
    private:
        std::string channelType_;
        LiveChannelStatus status_;
        std::string description_;
        std::string playListName_;
        uint64_t fragDuration_;
        uint64_t fragCount_;
    };
} 
}

