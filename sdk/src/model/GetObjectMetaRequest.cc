
#include <inspurcloud/oss/model/GetObjectMetaRequest.h>
using namespace InspurCloud::OSS;

ParameterCollection GetObjectMetaRequest::specialParameters() const
{
    ParameterCollection parameter;
    parameter["objectMeta"] = "";
    return parameter;
}
