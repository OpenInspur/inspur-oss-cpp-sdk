#include <inspurcloud/oss/model/UploadObjectRequest.h>
#include <inspurcloud/oss/http/HttpType.h>
#include <inspurcloud/oss/Const.h>
#include <fstream>
#include "../utils/Utils.h"
#include "../utils/FileSystemUtils.h"
#include "ModelError.h"

using namespace InspurCloud::OSS;

UploadObjectRequest::UploadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath, const std::string &checkpointDir, 
    const uint64_t partSize, const uint32_t threadNum): 
    OssResumableBaseRequest(bucket, key, checkpointDir, partSize, threadNum), 
    filePath_(filePath)
{
    objectSize_ = 0;

    time_t lastMtime;
    if (!GetPathLastModifyTime(filePath_, lastMtime)) {
        //if fail, ignore the lastmodified time.
        lastMtime = 0;
    }
    mtime_ = ToGmtTime(lastMtime);

    std::fstream content(filePath_, std::ios::in | std::ios::binary);
    if (content) {
        objectSize_ = GetIOStreamLength(content);
    }
    content.close();
}

UploadObjectRequest::UploadObjectRequest(const std::string &bucket, const std::string &key,
    const std::string &filePath, const std::string &checkpointDir,
    const uint64_t partSize, const uint32_t threadNum, const ObjectMetaData& meta): 
    UploadObjectRequest(bucket, key, filePath, checkpointDir, partSize, threadNum)
{
    metaData_ = meta;
}

UploadObjectRequest::UploadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath, const std::string &checkpointDir, const ObjectMetaData& meta):
    UploadObjectRequest(bucket, key, filePath, checkpointDir, DefaultPartSize, DefaultResumableThreadNum, meta)
{}

UploadObjectRequest::UploadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath, const std::string &checkpointDir) : 
    UploadObjectRequest(bucket, key, filePath, checkpointDir, DefaultPartSize, DefaultResumableThreadNum)
{}

UploadObjectRequest::UploadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath): 
    UploadObjectRequest(bucket, key, filePath, "", DefaultPartSize, DefaultResumableThreadNum)
{}

void UploadObjectRequest::setAcl(CannedAccessControlList& acl)
{
    metaData_.addHeader("x-oss-object-acl", ToAclName(acl));
}

void UploadObjectRequest::setCallback(const std::string& callback, const std::string& callbackVar)
{
    metaData_.removeHeader("x-oss-callback");
    metaData_.removeHeader("x-oss-callback-var");

    if (!callback.empty()) {
        metaData_.addHeader("x-oss-callback", callback);
    }

    if (!callbackVar.empty()) {
        metaData_.addHeader("x-oss-callback-var", callbackVar);
    }
}

void UploadObjectRequest::setTagging(const std::string& value)
{
    metaData_.addHeader("x-oss-tagging", value);
}

int UploadObjectRequest::validate() const 
{
    if(partSize_ < PartSizeLowerLimit){
        return ARG_ERROR_CHECK_PART_SIZE_LOWER;
    }

    if(threadNum_ <= 0){
        return ARG_ERROR_CHECK_THREAD_NUM_LOWER;
    }

    if (filePath_.empty()){
        return ARG_ERROR_UPLOAD_FILE_PATH_EMPTY;
    }
    else if (objectSize_ <= 0){
        std::fstream content(filePath_, std::ios::in | std::ios::binary);
        if (!content.is_open()) {
            return ARG_ERROR_OPEN_UPLOAD_FILE;
        }
    }

    // if directory do not exist, return error
    if (!checkpointDir_.empty()){
        if (!IsDirectoryExist(checkpointDir_)) {
            return ARG_ERROR_CHECK_POINT_DIR_NONEXIST;
        }
    }
    return 0;
}
