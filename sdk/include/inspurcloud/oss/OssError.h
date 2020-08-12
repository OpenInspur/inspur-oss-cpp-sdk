#pragma once

#include <string>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT OssError
    {
    public:
        OssError() = default;
        OssError(const std::string& code, const std::string& message) :
            code_(code),
            message_(message)
        {
        }
        OssError(const OssError& rhs) :
            code_(rhs.code_),
            message_(rhs.message_),
            requestId_(rhs.requestId_),
            host_(rhs.host_)
        {
        }
        OssError(OssError&& lhs) :
            code_(std::move(lhs.code_)),
            message_(std::move(lhs.message_)),
            requestId_(std::move(lhs.requestId_)),
            host_(std::move(lhs.host_))
        {
        }
        OssError& operator=(OssError&& lhs)
        {
            code_ = std::move(lhs.code_);
            message_ = std::move(lhs.message_);
            requestId_ = std::move(lhs.requestId_);
            host_ = std::move(lhs.host_);
            return *this;
        }
        OssError& operator=(const OssError& rhs)
        {
            code_ = rhs.code_;
            message_ = rhs.message_;
            requestId_ = rhs.requestId_;
            host_ = rhs.host_;
            return *this;
        }

        ~OssError() = default;
        const std::string& Code()const { return code_; }
        const std::string& Message() const { return message_; }
        const std::string& RequestId() const { return requestId_; }
        const std::string& Host() const { return host_; }
        void setCode(const std::string& value) { code_ = value; }
        void setCode(const char *value) { code_ = value; }
        void setMessage(const std::string& value) { message_ = value; }
        void setMessage(const char *value) { message_ = value; }
        void setRequestId(const std::string& value) { requestId_ = value; }
        void setRequestId(const char *value) { requestId_ = value; }
        void setHost(const std::string& value) { host_ = value; }
        void setHost(const char *value) { host_ = value; }
    private:
        std::string code_;
        std::string message_;
        std::string requestId_;
        std::string host_;
    };
}
}
