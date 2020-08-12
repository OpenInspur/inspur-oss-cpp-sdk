#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT Credentials
    {
        public:
            Credentials(const std::string& accessKeyId, const std::string& accessKeySecret,
                const std::string& sessionToken="");
            ~Credentials();
            const std::string& AccessKeyId () const;
            const std::string& AccessKeySecret () const;
            const std::string& SessionToken () const;
            void setAccessKeyId(const std::string& accessKeyId);
            void setAccessKeySecret(const std::string& accessKeySecret);
            void setSessionToken (const std::string& sessionToken);
        private:
            std::string accessKeyId_;
            std::string accessKeySecret_;
            std::string sessionToken_;
    };
}
}
