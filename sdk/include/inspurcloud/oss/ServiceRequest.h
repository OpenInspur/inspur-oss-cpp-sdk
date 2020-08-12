#pragma once

#include <memory>
#include <iostream>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    const int REQUEST_FLAG_CONTENTMD5    = (1 << 0);
    const int REQUEST_FLAG_PARAM_IN_PATH = (1 << 1);
    const int REQUEST_FLAG_CHECK_CRC64   = (1 << 2);
    const int REQUEST_FLAG_SAVE_CLIENT_CRC64 = (1 << 3);

    class INSPURCLOUD_OSS_EXPORT ServiceRequest
    {
    public:
        virtual ~ServiceRequest() = default;

        std::string Path() const;
        virtual HeaderCollection Headers() const = 0;
        virtual ParameterCollection Parameters() const = 0;
        virtual std::shared_ptr<std::iostream> Body() const = 0;

        int Flags() const;
        void setFlags(int flags);

        const IOStreamFactory& ResponseStreamFactory() const;
        void setResponseStreamFactory(const IOStreamFactory& factory);
        
        const InspurCloud::OSS::TransferProgress& TransferProgress() const;
        void setTransferProgress(const InspurCloud::OSS::TransferProgress& arg);
    protected:
        ServiceRequest();
        void setPath(const std::string &path);
    private:
        int flags_;
        std::string path_;
        IOStreamFactory responseStreamFactory_;
        InspurCloud::OSS::TransferProgress transferProgress_;
    };
}
}
