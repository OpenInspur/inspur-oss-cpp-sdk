#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <string>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GenerateRTMPSignedUrlRequest: public LiveChannelRequest
    {
    public:
        GenerateRTMPSignedUrlRequest(const std::string& bucket, 
            const std::string& channelName, const std::string& playlist, 
            uint64_t expires);

        void setExpires(uint64_t expires);
        void setPlayList(const std::string &playList);
        const std::string& PlayList() const;
        uint64_t Expires() const;
        virtual ParameterCollection Parameters() const;
    private:
        std::string playList_;
        uint64_t expires_;
    };
} 
}
