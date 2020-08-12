
#pragma once
#include <inspurcloud/oss/OssResult.h>
#include <memory>
#include <iostream>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT CreateSelectObjectMetaResult : public OssResult
    {
    public:
        CreateSelectObjectMetaResult();
        CreateSelectObjectMetaResult(
            const std::string& bucket,
            const std::string& key,
            const std::string& requestId,
            const std::shared_ptr<std::iostream>& data);
        CreateSelectObjectMetaResult& operator=(const std::shared_ptr<std::iostream>& data);

        const std::string& Bucket() const { return bucket_; }
        const std::string& Key()  const { return key_; }
        uint64_t Offset() const { return offset_; }
        uint64_t TotalScanned() const { return totalScanned_; }
        uint32_t Status() const { return status_; }
        uint32_t SplitsCount() const { return splitsCount_; }
        uint64_t RowsCount() const { return rowsCount_; }
        uint32_t ColsCount() const { return colsCount_; }
        const std::string& ErrorMessage() const { return errorMessage_; }

    private:
        std::string bucket_;
        std::string key_;
        uint64_t offset_;
        uint64_t totalScanned_;
        uint32_t status_;
        uint32_t splitsCount_;
        uint64_t rowsCount_;
        uint32_t colsCount_;
        std::string errorMessage_;
    };

}
}
