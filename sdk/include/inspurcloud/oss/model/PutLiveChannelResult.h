#pragma once
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT PutLiveChannelResult : public OssResult
    {
    public:
        PutLiveChannelResult();
        PutLiveChannelResult(const std::string& data);
        PutLiveChannelResult(const std::shared_ptr<std::iostream>& data);
        PutLiveChannelResult& operator=(const std::string& data);

        const std::string& PublishUrl() const;
        const std::string& PlayUrl() const;
    private:
        std::string publishUrl_;
        std::string playUrl_;
    };
} 
}
