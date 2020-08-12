#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT AsyncCallerContext
    {
    public:
        AsyncCallerContext();
        explicit AsyncCallerContext(const std::string &uuid);
        virtual ~AsyncCallerContext();
        
        const std::string &Uuid()const;
        void setUuid(const std::string &uuid);
    private:
        std::string uuid_;
    };
}
}
