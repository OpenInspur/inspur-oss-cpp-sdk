#pragma once

#include <string>

namespace InspurCloud
{
namespace OSS
{

    class  Signer
    {
    public:
        enum Type
        {
            HmacSha1,
        };
        virtual ~Signer();

        virtual std::string generate(const std::string &src, const std::string &secret)const = 0;
        std::string name()const;
        Type type() const;
        std::string version()const;
    protected:
        Signer(Type type, const std::string &name, const std::string &version = "1.0");
    private:
        Type type_;
        std::string name_;
        std::string version_;
    };
}
}
