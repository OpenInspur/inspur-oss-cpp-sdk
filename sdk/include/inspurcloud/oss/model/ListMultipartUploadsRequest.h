
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <sstream>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListMultipartUploadsRequest: public OssBucketRequest
    {
    public:
        ListMultipartUploadsRequest(const std::string& bucket);
        void setDelimiter(const std::string& delimiter);
        void setMaxUploads(uint32_t maxUploads);
        void setKeyMarker(const std::string& keyMarker);
        void setPrefix(const std::string& prefix);
        void setUploadIdMarker(const std::string& uploadIdMarker);
        void setEncodingType(const std::string& encodingType);
        void setRequestPayer(RequestPayer value);
    protected:
        virtual ParameterCollection specialParameters() const;
        virtual HeaderCollection specialHeaders() const;
    private:
        std::string delimiter_;
        bool delimiterIsSet_;
        std::string keyMarker_;
        bool keyMarkerIsSet_;
        std::string prefix_;
        bool prefixIsSet_;
        std::string uploadIdMarker_;
        bool uploadIdMarkerIsSet_;
        std::string encodingType_;
        bool encodingTypeIsSet_;
        int maxUploads_;
        bool maxUploadsIsSet_;
        RequestPayer requestPayer_;
    };
} 
}