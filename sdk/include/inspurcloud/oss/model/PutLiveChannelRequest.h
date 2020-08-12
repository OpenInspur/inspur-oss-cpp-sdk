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
    class INSPURCLOUD_OSS_EXPORT PutLiveChannelRequest : public LiveChannelRequest
    {
    public:
        PutLiveChannelRequest(const std::string& bucket, const std::string& channelName, 
            const std::string& type);

        void setChannelType(const std::string& type);
        void setStatus(LiveChannelStatus status);
        void setDescripition(const std::string& description);
        void setPlayListName(const std::string& playListName);
        void setRoleName(const std::string& roleName);
        void setDestBucket(const std::string& destBucket);
        void setNotifyTopic(const std::string& notifyTopic);
        void setFragDuration(uint64_t fragDuration);
        void setFragCount(uint64_t fragCount);
        void setInterval(uint64_t interval);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual std::string payload() const;
        virtual int validate() const;
    private:
        std::string channelType_;
        std::string description_;
        std::string playListName_;
        std::string roleName_;
        std::string destBucket_;
        std::string notifyTopic_;
        LiveChannelStatus status_;
        uint64_t fragDuration_;
        uint64_t fragCount_;
        uint64_t interval_;
        bool snapshot_;
    };
} 
}
