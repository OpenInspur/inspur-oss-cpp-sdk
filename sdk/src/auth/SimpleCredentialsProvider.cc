#include "SimpleCredentialsProvider.h"

using namespace InspurCloud::OSS;

SimpleCredentialsProvider::SimpleCredentialsProvider(const Credentials &credentials):
    CredentialsProvider(),
    credentials_(credentials)
{
}

SimpleCredentialsProvider::SimpleCredentialsProvider(const std::string & accessKeyId, 
    const std::string & accessKeySecret,
    const std::string &securityToken) :
    CredentialsProvider(),
    credentials_(accessKeyId, accessKeySecret, securityToken)
{
}

SimpleCredentialsProvider::~SimpleCredentialsProvider()
{
}

Credentials SimpleCredentialsProvider::getCredentials()
{
    return credentials_;
}
