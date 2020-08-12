#pragma once

#include <inspurcloud/oss/auth/CredentialsProvider.h>

namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT SimpleCredentialsProvider : public CredentialsProvider
    {
    public:
        SimpleCredentialsProvider(const Credentials &credentials);
        SimpleCredentialsProvider(const std::string &accessKeyId,
            const std::string &accessKeySecret, const std::string &securityToken = "");
        ~SimpleCredentialsProvider();

        virtual Credentials getCredentials() override;
    private:
        Credentials credentials_;
    };
}
}
