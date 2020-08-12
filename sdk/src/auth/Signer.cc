#include "Signer.h"

using namespace InspurCloud::OSS;

Signer::Signer(Type type, const std::string & name, const std::string & version) :
    type_(type),
    name_(name),
    version_(version)
{
}

Signer::~Signer()
{
}

std::string Signer::name() const
{
    return name_;
}

Signer::Type Signer::type() const
{
    return type_;
}

std::string Signer::version() const
{
    return version_;
}
