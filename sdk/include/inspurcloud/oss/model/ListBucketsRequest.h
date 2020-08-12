#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListBucketsRequest: public OssRequest
    {
    public:
        ListBucketsRequest():
            OssRequest(),
            prefixIsSet_(false),
            markerIsSet_(false),
            maxKeysIsSet_(false)
        {
        }
        ListBucketsRequest(const std::string& prefix, const std::string& marker, int maxKeys = 100):
            OssRequest(),
            prefix_(prefix), prefixIsSet_(true),
            marker_(marker), markerIsSet_(true),
            maxKeys_(maxKeys),maxKeysIsSet_(true)
        {
        }
        void setPrefix(const std::string& prefix) {prefix_ = prefix; prefixIsSet_ = true;}    
        void setMarker(const std::string& marker) {marker_ = marker; markerIsSet_ = true;}    
        void setMaxKeys(int maxKeys) {maxKeys_ = maxKeys; maxKeysIsSet_ = true;} 
    protected:
        virtual ParameterCollection specialParameters() const 
        {
            ParameterCollection params;
            if (prefixIsSet_) params["prefix"] = prefix_;
            if (markerIsSet_) params["marker"] = marker_;
            if (maxKeysIsSet_) params["max-keys"] = std::to_string(maxKeys_);
            return params;
        }
    private:
        std::string prefix_;
        bool prefixIsSet_;
        std::string marker_;
        bool markerIsSet_;
        int maxKeys_;
        bool maxKeysIsSet_;
    };
} 
}
