#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <inspurcloud/oss/OssResult.h>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT GetVodPlaylistResult: public OssResult
    {
    public:
        GetVodPlaylistResult();
        GetVodPlaylistResult(const std::string& data);
        GetVodPlaylistResult(const std::shared_ptr<std::iostream>& data);
        GetVodPlaylistResult& operator=(const std::string& data);

        const std::string& PlaylistContent() const;

    private:
        std::string playListContent_;
    };
} 
}
