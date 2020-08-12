#pragma once

#pragma once
#include <inspurcloud/oss/model/DownloadObjectRequest.h>
#include "ResumableBaseWorker.h"

namespace InspurCloud
{
namespace OSS
{
    struct PartRecord {
        int32_t partNumber;
        int64_t offset;
        int64_t size;
        uint64_t crc64;
    };
    typedef std::vector<PartRecord> PartRecordList;
    struct DownloadRecord {
        std::string opType;
        std::string bucket;
        std::string key;
        std::string filePath;
        std::string mtime;
        uint64_t size;
        uint64_t partSize;
        PartRecordList parts;
        std::string md5Sum;
        int64_t rangeStart;
        int64_t rangeEnd;
        //crc64
    };


    class ResumableDownloader : public ResumableBaseWorker
    {
    public:
        ResumableDownloader(const DownloadObjectRequest& request, const OssClientImpl *client, uint64_t objectSize)
            : ResumableBaseWorker(objectSize, request.PartSize()), request_(request),client_(client), contentLength_(objectSize)
        {}

        GetObjectOutcome Download();

    protected:
        const std::string getRecordPath();
        int loadRecord();
        int validateRecord();
        int prepare(OssError& err);
        void initRecord();
        int getPartsToDownload(OssError &err, PartRecordList &partsToDownload);

        static void DownloadPartProcessCallback(size_t increment, int64_t transfered, int64_t total, void *userData);

        const DownloadObjectRequest request_;
        DownloadRecord record_;
        const OssClientImpl *client_;
        uint64_t contentLength_;
    };
}
}
