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
    class INSPURCLOUD_OSS_EXPORT PostVodPlaylistRequest : public LiveChannelRequest
    {
    public:
        PostVodPlaylistRequest(const std::string& bucket, const std::string& channelName, 
            const std::string& playList, uint64_t startTime, uint64_t endTime);

        void setPlayList(const std::string& playList);
        void setStartTime(uint64_t startTime);
        void setEndTime(uint64_t endTime);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        std::string playList_;
        uint64_t startTime_;
        uint64_t endTime_;
    };
} 
}
