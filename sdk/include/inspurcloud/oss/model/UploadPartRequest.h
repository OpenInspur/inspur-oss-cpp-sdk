
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <sstream>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT UploadPartRequest: public OssObjectRequest
    {
    public:
        UploadPartRequest(const std::string& bucket, const std::string& key,
            const std::shared_ptr<std::iostream>& content);
        UploadPartRequest(const std::string &bucket, const std::string& key,
            int partNumber, const std::string& uploadId,
            const std::shared_ptr<std::iostream>& content);
        virtual std::shared_ptr<std::iostream> Body() const;
        void setPartNumber(int partNumber);
        void setUploadId(const std::string& uploadId);
        void setConetent(const std::shared_ptr<std::iostream>& content);
        void setContentLength(uint64_t length);
        void setTrafficLimit(uint64_t value);
        void setCustomerSSEKey(const std::string &value);

    protected:
        virtual HeaderCollection specialHeaders() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        int partNumber_;
        std::string uploadId_;
        std::shared_ptr<std::iostream> content_;
        uint64_t contentLength_;
        bool contentLengthIsSet_;
        uint64_t trafficLimit_;
        std::string CustomerSSEKey_;
    };
} 
}
