
#pragma once
#include <sstream>
#include <iostream>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ListPartsRequest: public OssObjectRequest
    {
    public:
        ListPartsRequest(const std::string& bucket, const std::string& key);
        ListPartsRequest(const std::string& bucket, const std::string& key,
            const std::string& uploadId);
        void setUploadId(const std::string& uploadId);
        void setMaxParts(uint32_t maxParts);
        void setPartNumberMarker(uint32_t partNumberMarker);
        void setEncodingType(const std::string& encodingType);
    protected:
        virtual ParameterCollection specialParameters() const;
    private:
        std::string uploadId_;
        uint32_t maxParts_;
        bool maxPartsIsSet_;
        uint32_t partNumberMarker_;
        bool partNumberMarkerIsSet_;
        std::string encodingType_;
        bool encodingTypeIsSet_;
    };
} 
}