#pragma once
#include "Credentials.h"

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CredentialsProvider
    {
    public:
        CredentialsProvider() = default;
        virtual ~CredentialsProvider() = default;
        virtual Credentials getCredentials() = 0;
    private:

    };
}
}
