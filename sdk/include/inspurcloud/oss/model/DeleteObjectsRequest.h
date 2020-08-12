#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <list>

namespace InspurCloud
{
namespace OSS
{
    using DeletedKeyList = std::list<std::string>;
    class INSPURCLOUD_OSS_EXPORT DeleteObjectsRequest : public OssBucketRequest
    {
    public:
        DeleteObjectsRequest(const std::string& bucket);
        bool Quiet() const;
        const std::string& EncodingType() const;
        const DeletedKeyList& KeyList() const;
        void setQuiet(bool quiet);
        void setEncodingType(const std::string& value);
        void addKey(const std::string& key);
        void setKeyList(const DeletedKeyList& keyList);
        void clearKeyList();
        void setRequestPayer(RequestPayer value);
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual HeaderCollection specialHeaders() const;
    private:
        bool quiet_;
        std::string encodingType_;
        DeletedKeyList keyList_;
        RequestPayer requestPayer_;
    };
} 
}
