#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/Owner.h>

namespace InspurCloud
{
namespace OSS
{
    class ListBucketsResult;
    class INSPURCLOUD_OSS_EXPORT Bucket
    {
    public:
        Bucket() = default;
        const std::string& Location() const { return location_; }
        const std::string& Name() const { return name_; }
        const std::string& CreationDate() const { return creationDate_; }
        const std::string& IntranetEndpoint() const { return intranetEndpoint_; }
        const std::string& ExtranetEndpoint() const { return extranetEndpoint_; }
        InspurCloud::OSS::StorageClass StorageClass() const { return storageClass_; }
        const InspurCloud::OSS::Owner& Owner() const { return owner_; }
    private:
        friend class ListBucketsResult;
        std::string location_;
        std::string name_;
        std::string creationDate_;
        std::string intranetEndpoint_;
        std::string extranetEndpoint_;
        InspurCloud::OSS::StorageClass storageClass_;
        InspurCloud::OSS::Owner owner_;
    };
}
}
