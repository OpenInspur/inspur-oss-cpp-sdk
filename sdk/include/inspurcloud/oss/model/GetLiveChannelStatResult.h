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
    class INSPURCLOUD_OSS_EXPORT GetLiveChannelStatResult : public OssResult
    {
    public:
        GetLiveChannelStatResult();
        GetLiveChannelStatResult(const std::string& data);
        GetLiveChannelStatResult(const std::shared_ptr<std::iostream>& data);
        GetLiveChannelStatResult& operator=(const std::string& data);

        LiveChannelStatus Status() const;
        const std::string& ConnectedTime() const;
        const std::string& RemoteAddr() const;
        uint32_t Width() const;
        uint32_t Height() const;
        uint64_t FrameRate() const;
        uint64_t VideoBandWidth() const;
        const std::string& VideoCodec() const;
        uint64_t SampleRate() const;
        uint64_t AudioBandWidth() const;
        const std::string& AudioCodec() const;
    private:
        std::string connectedTime_;
        LiveChannelStatus status_;
        std::string remoteAddr_;
        uint32_t width_;
        uint32_t height_;
        uint64_t frameRate_;
        uint64_t videoBandWidth_;
        std::string videoCodec_;
        uint64_t sampleRate_;
        uint64_t audioBandWidth_;
        std::string audioCodec_;
    };
} 
}

