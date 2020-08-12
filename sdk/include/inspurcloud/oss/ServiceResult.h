#pragma once

#include <string>
#include <memory>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{
    class  ServiceResult
    {
    public:
        ServiceResult() {}
        virtual ~ServiceResult() {};

        inline const std::string& RequestId() const {return requestId_;}
        inline const std::shared_ptr<std::iostream>& payload() const {return payload_;}
        inline const HeaderCollection& headerCollection() const {return headerCollection_;}
        inline int responseCode() const {return responseCode_;}

        void setRequestId(const std::string& requestId) {requestId_ = requestId;}
        void setPlayload(const std::shared_ptr<std::iostream>& payload) {payload_ = payload;}
        void setHeaderCollection(const HeaderCollection& values) { headerCollection_ = values;}
        void setResponseCode(const int code) { responseCode_ = code;} 
    private:
        std::string requestId_;
        std::shared_ptr<std::iostream> payload_;
        HeaderCollection headerCollection_;
        int responseCode_;
    };
}
}
