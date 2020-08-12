
#include <inspurcloud/oss/model/ProcessObjectRequest.h>
#include <sstream>
using namespace InspurCloud::OSS;

ProcessObjectRequest::ProcessObjectRequest(const std::string &bucket, const std::string &key):
    ProcessObjectRequest(bucket, key, "")
{
}

ProcessObjectRequest::ProcessObjectRequest(const std::string &bucket, const std::string &key, const std::string &process) :
    OssObjectRequest(bucket, key),
    process_(process)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}


void ProcessObjectRequest::setProcess(const std::string &process)
{
    process_ = process;
}

ParameterCollection ProcessObjectRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["x-oss-process"];
    return parameters;
}

std::string  ProcessObjectRequest::payload() const
{
    std::stringstream ss;
    ss << "x-oss-process=" << process_;
    return ss.str();
}


