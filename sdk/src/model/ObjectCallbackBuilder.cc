
#include <inspurcloud/oss/model/ObjectCallbackBuilder.h>
#include <sstream>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

ObjectCallbackBuilder::ObjectCallbackBuilder(const std::string &url, const std::string &body):
    ObjectCallbackBuilder(url, body, "", Type::URL)
{
}

ObjectCallbackBuilder::ObjectCallbackBuilder(const std::string &url, const std::string &body,
    const std::string &host, Type type):
    callbackUrl_(url),
    callbackHost_(host),
    callbackBody_(body),
    callbackBodyType_(type)
{
}

std::string ObjectCallbackBuilder::build()
{
    if (callbackUrl_.empty() || callbackBody_.empty())
    {
        return "";
    }

    std::stringstream ss;
    ss << "{";
    ss << "\"callbackUrl\":\"" << callbackUrl_ << "\"";
    if (!callbackHost_.empty())
    {
        ss << ",\"callbackHost\":\"" << callbackHost_ << "\"";
    }
    ss << ",\"callbackBody\":\"" << callbackBody_ << "\"";

    if (callbackBodyType_ == Type::JSON)
    {
        ss << ",\"callbackBodyType\":\"" << "application/json" << "\"";
    }

    ss << "}";

    return Base64Encode(ss.str());
}


bool ObjectCallbackVariableBuilder::addCallbackVariable(const std::string &key, const std::string &value)
{
    if (!!key.compare(0, 2 , "x:", 2))
    {
        return false;
    }
    callbackVariable_[key] = value;
    return true;
}

std::string ObjectCallbackVariableBuilder::build()
{
    if (callbackVariable_.size() == 0)
    {
        return "";
    }

    std::stringstream ss;
    ss << "{";
    int i = 0;
    for (auto const& var : callbackVariable_) {
        if (i > 0) {
            ss << ",";
        }
        ss << "\"" << var.first << "\":\"" << var.second << "\"";
        i++;
    }
    ss << "}";
    return Base64Encode(ss.str());
}
