#include <inspurcloud/oss/ServiceRequest.h>
#include <sstream>

using namespace InspurCloud::OSS;

ServiceRequest::ServiceRequest() :
    flags_(0),
    path_("/"),
    responseStreamFactory_([] { return std::make_shared<std::stringstream>(); })
{
    transferProgress_.Handler = nullptr;
    transferProgress_.UserData = nullptr;
}

std::string ServiceRequest::Path() const
{
    return path_;
}

int ServiceRequest::Flags() const 
{ 
    return flags_; 
}

const IOStreamFactory& ServiceRequest::ResponseStreamFactory() const 
{ 
    return responseStreamFactory_; 
}

void ServiceRequest::setResponseStreamFactory(const IOStreamFactory& factory) 
{
    responseStreamFactory_ = factory; 
}

const InspurCloud::OSS::TransferProgress & ServiceRequest::TransferProgress() const 
{
    return transferProgress_; 
}

void ServiceRequest::setTransferProgress(const InspurCloud::OSS::TransferProgress &arg) 
{ 
    transferProgress_ = arg; 
}

void ServiceRequest::setPath(const std::string & path)
{
    path_ = path;
}

void ServiceRequest::setFlags(int flags)
{
    flags_ = flags;
}
