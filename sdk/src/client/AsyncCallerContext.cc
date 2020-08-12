#include <inspurcloud/oss/client/AsyncCallerContext.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

AsyncCallerContext::AsyncCallerContext() :
    uuid_(GenerateUuid())
{
}

AsyncCallerContext::AsyncCallerContext(const std::string &uuid) :
    uuid_(uuid)
{
}

AsyncCallerContext::~AsyncCallerContext()
{
}

const std::string &AsyncCallerContext::Uuid()const
{
    return uuid_;
}

void AsyncCallerContext::setUuid(const std::string &uuid)
{
    uuid_ = uuid;
}
