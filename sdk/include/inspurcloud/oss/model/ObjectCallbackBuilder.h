#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ObjectCallbackBuilder
    {
    public:
        enum Type
        {
            URL = 0,
            JSON
        };
        ObjectCallbackBuilder(const std::string& url, const std::string& body);
        ObjectCallbackBuilder(const std::string& url, const std::string& body,
            const std::string& host, Type type);
        const std::string& CallbackUrl() const { return callbackUrl_; }
        const std::string& CallbackHost() const { return callbackHost_; }
        const std::string& CallbackBody() const { return callbackBody_; }
        Type CallbackBodyType() const { return callbackBodyType_; }
        void setCallbackUrl(const std::string& url) { callbackUrl_ = url; }
        void setCallbackHost(const std::string& host) { callbackHost_ = host; }
        void setCallbackBody(const std::string& body) { callbackBody_ = body; }
        void setCallbackBodyType(Type type) { callbackBodyType_ = type; }
        std::string build();
    private:
        std::string callbackUrl_;
        std::string callbackHost_;
        std::string callbackBody_;
        Type callbackBodyType_;
    };

    class INSPURCLOUD_OSS_EXPORT ObjectCallbackVariableBuilder
    {
    public:
        ObjectCallbackVariableBuilder() {};
        const HeaderCollection& CallbackVariable() const { return callbackVariable_; }
        bool addCallbackVariable(const std::string &key, const std::string& value);
        std::string build();
    private:
        HeaderCollection callbackVariable_;
    };
}
}
