#include <inspurcloud/oss/auth/Credentials.h>

using namespace InspurCloud::OSS;

Credentials::Credentials(const std::string &accessKeyId,
        const std::string &accessKeySecret,
        const std::string &sessionToken) :
    accessKeyId_(accessKeyId),
    accessKeySecret_(accessKeySecret),
    sessionToken_(sessionToken)
{
}

Credentials::~Credentials()
{
}

const std::string& Credentials::AccessKeyId () const
{
    return accessKeyId_;
}

const std::string& Credentials::AccessKeySecret () const
{
    return accessKeySecret_;
}

const std::string& Credentials::SessionToken () const
{
    return sessionToken_;
}

void Credentials::setAccessKeyId(const std::string &accessKeyId)
{
    accessKeyId_ = accessKeyId;
}

void Credentials::setAccessKeySecret(const std::string &accessKeySecret)
{
    accessKeySecret_ = accessKeySecret;
}

void Credentials::setSessionToken (const std::string &sessionToken)
{
    sessionToken_ = sessionToken;
}

