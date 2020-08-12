#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListLiveChannelRequest: public OssBucketRequest
    {
    public:
        ListLiveChannelRequest(const std::string &bucket);

        void setMarker(const std::string& marker);   
        void setMaxKeys(uint32_t maxKeys);
        void setPrefix(const std::string& prefix);    
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        std::string prefix_;
        std::string marker_;
        uint32_t maxKeys_;
    };
} 
}
