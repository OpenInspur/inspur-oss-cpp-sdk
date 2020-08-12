#pragma once
#include <inspurcloud/oss/Export.h>
#include <string>
#include <list>

namespace InspurCloud
{
namespace OSS
{
    using CORSAllowedList = std::list<std::string>;
    class INSPURCLOUD_OSS_EXPORT CORSRule
    {
    public:
        static const int UNSET_AGE_SEC = -1;
    public:
        CORSRule() : maxAgeSeconds_(UNSET_AGE_SEC) {}
        const CORSAllowedList& AllowedOrigins() const { return allowedOrigins_; }
        const CORSAllowedList& AllowedMethods() const { return allowedMethods_; }
        const CORSAllowedList& AllowedHeaders() const { return allowedHeaders_; }
        const CORSAllowedList& ExposeHeaders() const { return exposeHeaders_; }
        int MaxAgeSeconds() const { return maxAgeSeconds_; }
        void addAllowedOrigin(const std::string& origin) { allowedOrigins_.push_back(origin); }
        void addAllowedMethod(const std::string& method) { allowedMethods_.push_back(method); }
        void addAllowedHeader(const std::string& header) { allowedHeaders_.push_back(header); }
        void addExposeHeader(const std::string& header) { exposeHeaders_.push_back(header); }
        void setMaxAgeSeconds(int value) { maxAgeSeconds_ = value; }
        void clear()
        {
            allowedOrigins_.clear();
            allowedMethods_.clear();
            allowedHeaders_.clear();
            exposeHeaders_.clear();
            maxAgeSeconds_ = UNSET_AGE_SEC;
        }
    private:
        CORSAllowedList allowedOrigins_;
        CORSAllowedList allowedMethods_;
        CORSAllowedList allowedHeaders_;
        CORSAllowedList exposeHeaders_;
        int maxAgeSeconds_;
    };

    using CORSRuleList = std::list<CORSRule>;
} 
}
