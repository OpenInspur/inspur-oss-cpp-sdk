
#pragma once
#include <fstream>
#include <mutex>
#include <inspurcloud/oss/OssError.h>
#include <inspurcloud/oss/OssRequest.h>
#include "utils/Utils.h"

namespace InspurCloud
{
namespace OSS
{
    class ResumableBaseWorker
    {
    public:
        ResumableBaseWorker(uint64_t objectSize, uint64_t partSize);
        ResumableBaseWorker(const std::string& filePath, uint64_t partSize);

    protected:
        int validate(OssError& err);
        void determinePartSize();
        virtual const std::string getRecordPath() = 0;
        virtual int loadRecord() = 0;
        virtual int prepare(OssError& err) = 0;
        virtual int validateRecord() = 0;
        
        bool hasRecord_;
        std::string recordPath_;
        std::mutex lock_;
        uint64_t objectSize_;
        uint64_t consumedSize_;
        uint64_t partSize_;
    };
}
}