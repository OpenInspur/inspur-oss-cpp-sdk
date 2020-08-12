#pragma once
#include <string>
#include <vector>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <inspurcloud/oss/ServiceRequest.h>

using std::vector;

namespace InspurCloud
{
namespace OSS
{
    struct LiveRecord
    {
        std::string startTime;
        std::string endTime;
        std::string remoteAddr;
    };

    using LiveRecordVec = vector<LiveRecord>;

    class INSPURCLOUD_OSS_EXPORT GetLiveChannelHistoryResult : public OssResult
    {
    public:
        GetLiveChannelHistoryResult();
        GetLiveChannelHistoryResult(const std::string& data);
        GetLiveChannelHistoryResult(const std::shared_ptr<std::iostream>& data);
        GetLiveChannelHistoryResult& operator=(const std::string& data);

        const LiveRecordVec& LiveRecordList() const;
    private:
        LiveRecordVec recordList_;
    };
} 
}

