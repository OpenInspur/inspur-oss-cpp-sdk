
#pragma once

#include <string>
#include <map>
#include <ctime>
#include <iostream>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class SignUtils
    {
    public: 
        SignUtils(const std::string &version);
        ~SignUtils();
        void build(const std::string &method,
                   const std::string &resource,
                   const std::string &date,
                   const HeaderCollection &headers,
                   const ParameterCollection &parameters);
        void build(const std::string &expires,
                    const std::string &resource,
                    const ParameterCollection &parameters);
        const std::string &CanonicalString() const;
    private:
        std::string signVersion_;
        std::string canonicalString_;
    };
}
}

