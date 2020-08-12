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
    class INSPURCLOUD_OSS_EXPORT GetVodPlaylistRequest : public LiveChannelRequest
    {
    public:
        GetVodPlaylistRequest(const std::string& bucket, 
            const std::string& channelName);

        GetVodPlaylistRequest(const std::string& bucket, 
            const std::string& channelName, uint64_t startTime, 
            uint64_t endTime);

        void setStartTime(uint64_t startTime);
        void setEndTime(uint64_t endTime);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        uint64_t startTime_;
        uint64_t endTime_;
    };
} 
}
