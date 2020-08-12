#pragma once
#include <inspurcloud/oss/OssResult.h>
#include <memory>
#include <iostream>
#include <list>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT DeleteObjectsResult : public OssResult
    {
    public:
        DeleteObjectsResult();
        DeleteObjectsResult(const std::string& data);
        DeleteObjectsResult(const std::shared_ptr<std::iostream>& data);
        DeleteObjectsResult& operator=(const std::string& data);
        bool Quiet() const;
        const std::list<std::string>& keyList() const;
    private:
        bool quiet_;
        std::list<std::string> keyList_;
    };
} 
}
