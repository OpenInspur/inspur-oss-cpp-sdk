#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT ListObjectsRequest: public OssBucketRequest
    {
    public:
        ListObjectsRequest(const std::string& bucket):
            OssBucketRequest(bucket),
            delimiterIsSet_(false),
            markerIsSet_(false),
            maxKeysIsSet_(false),
            prefixIsSet_(false),
            encodingTypeIsSet_(false),
            requestPayer_(RequestPayer::NotSet)
        {
        }
        void setDelimiter(const std::string& delimiter) { delimiter_ = delimiter; delimiterIsSet_ = true; }
        void setMarker(const std::string& marker) {marker_ = marker; markerIsSet_ = true;}    
        void setMaxKeys(int maxKeys) {maxKeys_ = maxKeys; maxKeysIsSet_ = true;} 
        void setPrefix(const std::string& prefix) { prefix_ = prefix; prefixIsSet_ = true; }
        void setEncodingType(const std::string& type) { encodingType_ = type; encodingTypeIsSet_ = true; }
        void setRequestPayer(RequestPayer value) { requestPayer_ = value; }

    protected:
        virtual ParameterCollection specialParameters() const;
        virtual HeaderCollection specialHeaders() const;
    private:
        std::string delimiter_;
        bool delimiterIsSet_;
        std::string marker_;
        bool markerIsSet_;
        int maxKeys_;
        bool maxKeysIsSet_;
        std::string prefix_;
        bool prefixIsSet_;
        std::string encodingType_;
        bool encodingTypeIsSet_;
        RequestPayer requestPayer_;
    };
} 
}
