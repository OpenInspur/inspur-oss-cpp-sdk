#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT SetBucketWebsiteRequest : public OssBucketRequest
    {
    public:
        SetBucketWebsiteRequest(const std::string& bucket);
        void setIndexDocument(const std::string& document)
        { 
            indexDocument_ = document; 
            indexDocumentIsSet_ = true;
        }
        void setErrorDocument(const std::string& document)
        {
            errorDocument_ = document;
            errorDocumentIsSet_ = true;
        }
    protected:
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        std::string indexDocument_;
        bool indexDocumentIsSet_;
        std::string errorDocument_;
        bool errorDocumentIsSet_;
    };
} 
}
