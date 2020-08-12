
#pragma once
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/InputFormat.h>


namespace InspurCloud
{
namespace OSS
{

    class INSPURCLOUD_OSS_EXPORT CreateSelectObjectMetaRequest : public OssObjectRequest
    {
    public:
        CreateSelectObjectMetaRequest(const std::string& bucket, const std::string& key);

        void setOverWriteIfExists(bool overWriteIfExist);
        void setInputFormat(InputFormat& inputFormat);
   
    protected:
        virtual int validate() const;
        virtual std::string payload() const;
        virtual ParameterCollection specialParameters() const;

    private:
        InputFormat *inputFormat_;
        bool overWriteIfExists_;
    };
}
}