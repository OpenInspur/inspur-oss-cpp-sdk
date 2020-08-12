
#pragma once
#include <inspurcloud/oss/model/MultiCopyObjectRequest.h>
#include <inspurcloud/oss/OssError.h>
#include <inspurcloud/oss/model/Part.h>
#include "ResumableBaseWorker.h"

namespace InspurCloud
{
namespace OSS
{
    struct MultiCopyRecord {
        std::string opType;
        std::string uploadID;
        std::string srcBucket;
        std::string srcKey;
        std::string bucket;
        std::string key;
        std::string mtime;
        uint64_t size;
        uint64_t partSize;
        std::string md5Sum;
    };

    class ResumableCopier : public ResumableBaseWorker
    {
    public:
        ResumableCopier(const MultiCopyObjectRequest &request, const OssClientImpl *client, uint64_t objectSize) 
            :ResumableBaseWorker(objectSize, request.PartSize()), request_(request), client_(client)
        {
        }
	    CopyObjectOutcome Copy();

    protected:
        const std::string getRecordPath();
        int loadRecord();
        int validateRecord();
        int prepare(OssError& err);
        void initRecord(const std::string &uploadID);
        int getPartsToUploadCopy(OssError &err, PartList &partsCopied, PartList &partsToUpload);

        const MultiCopyObjectRequest request_;
        MultiCopyRecord record_;
        const OssClientImpl *client_;
        std::string uploadID_;
    };
}
}
