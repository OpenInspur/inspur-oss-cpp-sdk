#pragma once

#include <inspurcloud/oss/Export.h>
#include <string>
#include <vector>

namespace InspurCloud
{
namespace OSS
{
    using CommonPrefixeList = std::vector<std::string>;

    class OssClientImpl;
    class INSPURCLOUD_OSS_EXPORT OssResult
    {
    public:
        OssResult():parseDone_(false) {}
        virtual ~OssResult() {};
        const std::string& RequestId() const {return requestId_;}
    protected:
        friend class OssClientImpl;
        bool ParseDone() { return parseDone_; };
        bool parseDone_;
        std::string requestId_;
    };
}
}
