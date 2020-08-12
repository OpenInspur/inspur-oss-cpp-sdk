#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    /*
    The status comes from the following modules: client, server, httpclient(ex. curl).
    server: [100-600)  
    client: [100000-199999]
    curl  : [200000-299999], 200000 + CURLcode

    it's sucessful only if the status/100 equals to 2.
    */
    const int ERROR_CLIENT_BASE      = 100000;
    const int ERROR_CRC_INCONSISTENT = ERROR_CLIENT_BASE + 1;
    const int ERROR_REQUEST_DISABLE  = ERROR_CLIENT_BASE + 2;

    const int ERROR_CURL_BASE = 200000;

    class INSPURCLOUD_OSS_EXPORT Error
    {
    public:
        Error() = default;
        Error(const std::string& code, const std::string& message):
            status_(0),
            code_(code),
            message_(message)
        {
        }
        ~Error() = default;

        long Status() const {return status_;}
        const std::string& Code()const {return code_;}
        const std::string& Message() const {return message_;}
        const HeaderCollection& Headers() const { return headers_; }
        void setStatus(long status) { status_ = status;}
        void setCode(const std::string& code) { code_ = code;}
        void setMessage(const std::string& message) { message_ = message;}
        void setHeaders(const HeaderCollection& headers) { headers_ = headers; }
    private:
        long status_;
        std::string code_;
        std::string message_;
        HeaderCollection headers_;
    };
}
}
