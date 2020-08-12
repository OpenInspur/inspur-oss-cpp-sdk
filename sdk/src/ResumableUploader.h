#pragma once
#include <inspurcloud/oss/model/UploadObjectRequest.h>
#include <inspurcloud/oss/model/Part.h>
#include <inspurcloud/oss/OssError.h>
#include "ResumableBaseWorker.h"

namespace InspurCloud
{
namespace OSS
{
    struct UploadRecord{
        std::string opType;
        std::string uploadID;
        std::string filePath;
        std::string bucket;
        std::string key;
        std::string mtime;
        uint64_t size;
        uint64_t partSize;
        std::string md5Sum;
    };

    class ResumableUploader : public ResumableBaseWorker
    {
    public:
        ResumableUploader(const UploadObjectRequest& request, const OssClientImpl *client): 
            ResumableBaseWorker(request.FilePath(), request.PartSize()), 
            request_(request), 
            client_(client)
        {}
	
        PutObjectOutcome Upload();
        
    private:
        int getPartsToUpload(OssError &err, PartList &partsUploaded, PartList &partsToUpload);
        const std::string getRecordPath();
        int loadRecord();
        int validateRecord();
        int prepare(OssError& err);
        void initRecord(const std::string &uploadID);
		
        const UploadObjectRequest& request_;
        UploadRecord record_;
        const OssClientImpl *client_;
        std::string uploadID_;
        static void UploadPartProcessCallback(size_t increment, int64_t transfered, int64_t total, void *userData);
    };
} 
}
