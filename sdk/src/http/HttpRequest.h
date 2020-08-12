#pragma once

#include <inspurcloud/oss/Types.h>
#include <string>
#include "HttpMessage.h"
#include "Url.h"
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{

    class HttpRequest : public HttpMessage
    {
        public:
            HttpRequest(Http::Method method = Http::Method::Get);   //请求行的请求方法默认为Get
            ~HttpRequest();

            Http::Method method() const;
            Url url() const;
            void setMethod(Http::Method method);
            void setUrl(const Url &url);
            
            const IOStreamFactory& ResponseStreamFactory() const { return responseStreamFactory_; }
            void setResponseStreamFactory(const IOStreamFactory& factory) { responseStreamFactory_ = factory; }

            const InspurCloud::OSS::TransferProgress & TransferProgress() const {  return transferProgress_; }
            void setTransferProgress(const InspurCloud::OSS::TransferProgress &arg) { transferProgress_ = arg;}

            void setCheckCrc64(bool enable) { hasCheckCrc64_ = enable; }
            bool hasCheckCrc64() const { return hasCheckCrc64_; }
            void setCrc64Result(uint64_t crc) { crc64Result_ = crc; }
            uint64_t Crc64Result() const { return crc64Result_; }

            void setTransferedBytes(int64_t value) { transferedBytes_ = value; }
            uint64_t TransferedBytes() const { return transferedBytes_;}

        private:
            Http::Method method_;
            Url url_;
            IOStreamFactory responseStreamFactory_;
            InspurCloud::OSS::TransferProgress transferProgress_;
            bool hasCheckCrc64_;
            uint64_t crc64Result_;
            int64_t transferedBytes_;
    };
}
}
