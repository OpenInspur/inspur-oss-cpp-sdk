#pragma once
#include <string>
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT ObjectMetaData
    {
    public:
        ObjectMetaData() = default;
        ObjectMetaData(const HeaderCollection& data);
        ObjectMetaData& operator=(const HeaderCollection& data);
        const std::string& LastModified() const;
        const std::string& ExpirationTime() const;
        int64_t ContentLength() const ;
        const std::string& ContentType() const;
        const std::string& ContentEncoding() const;
        const std::string& CacheControl() const;
        const std::string& ContentDisposition() const;
        const std::string& ETag() const;
        const std::string& ContentMd5() const;
        const std::string& ObjectType() const;
        uint64_t CRC64() const;
        void setExpirationTime(const std::string& value);
        void setContentLength(int64_t value);
        void setContentType(const std::string& value);
        void setContentEncoding(const std::string& value);
        void setCacheControl(const std::string& value);
        void setContentDisposition(const std::string& value);
        void setETag(const std::string& value);
        void setContentMd5(const std::string& value);
        void setCrc64(uint64_t value);
        void addHeader(const std::string& key, const std::string& value);
        bool hasHeader(const std::string& key) const;
        void removeHeader(const std::string& key);
        MetaData& HttpMetaData();
        const MetaData& HttpMetaData() const;
        void addUserHeader(const std::string& key, const std::string& value);
        bool hasUserHeader(const std::string& key) const;
        void removeUserHeader(const std::string& key);
        MetaData& UserMetaData();
        const MetaData& UserMetaData() const;
        HeaderCollection toHeaderCollection() const;
    private:
        MetaData userMetaData_;
        MetaData metaData_;
    };
}
}
