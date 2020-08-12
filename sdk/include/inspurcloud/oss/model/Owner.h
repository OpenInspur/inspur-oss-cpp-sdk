#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT Owner
    {
    public:
        Owner() = default;
        Owner(const std::string& id, const std::string& name) :
            id_(id),
            displayName_(name)
        {}
        Owner(const Owner& rhs) :
            id_(rhs.id_),
            displayName_(rhs.displayName_)
        {}
        Owner(Owner&& lhs) :
            id_(std::move(lhs.id_)),
            displayName_(std::move(lhs.displayName_))
        {}
        Owner& operator=(const Owner& rhs)
        {
            id_ = rhs.id_;
            displayName_ = rhs.displayName_;
            return *this;
        }
        Owner& operator=(Owner&& lhs)
        {
            id_ = std::move(lhs.id_);
            displayName_ = std::move(lhs.displayName_);
            return *this;
        }
        const std::string& Id() const { return id_; }
        const std::string& DisplayName() const { return displayName_; };
    private:
        std::string id_;
        std::string displayName_;
    };
} 
}
