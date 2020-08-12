
#include <inspurcloud/oss/OssResponse.h>

using namespace InspurCloud::OSS;

OssResponse::OssResponse() :
    payload_()
{
}

OssResponse::OssResponse(const std::string &payload) :
    payload_(payload)
{
}

OssResponse::~OssResponse()
{
}

std::string OssResponse::payload() const
{
    return payload_;
}
