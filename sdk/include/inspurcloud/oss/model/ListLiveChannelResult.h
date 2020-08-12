#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{
    struct LiveChannelInfo
    {
        std::string name;
        std::string description;
        std::string status;
        std::string lastModified;
        std::string publishUrl;
        std::string playUrl;
    };

    using LiveChannelListInfo = std::vector<LiveChannelInfo>;

    class INSPURCLOUD_OSS_EXPORT ListLiveChannelResult: public OssResult
    {
    public:
        ListLiveChannelResult();
        ListLiveChannelResult(const std::string& data);
        ListLiveChannelResult(const std::shared_ptr<std::iostream>& data);
        ListLiveChannelResult& operator=(const std::string& data);

        const std::string& Prefix() const;
        const std::string& Marker() const;
        const std::string& NextMarker() const;
        bool IsTruncated() const;
        const LiveChannelListInfo& LiveChannelList() const;
        uint32_t MaxKeys() const;
    private:
        std::string prefix_;
        std::string marker_;
        std::string nextMarker_;
        LiveChannelListInfo liveChannelList_;
        uint32_t maxKeys_;
        bool     isTruncated_;
        
    };
} 
}
