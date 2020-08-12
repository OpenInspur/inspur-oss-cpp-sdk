

#include <inspurcloud/oss/model/DownloadObjectRequest.h>
#include <inspurcloud/oss/Const.h>
#include <sstream>
#include <fstream>
#include "../model/ModelError.h"
#include "../utils/FileSystemUtils.h"

using namespace InspurCloud::OSS;

DownloadObjectRequest::DownloadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath, const std::string &checkpointDir,
    const uint64_t partSize, const uint32_t threadNum):
    OssResumableBaseRequest(bucket, key, checkpointDir, partSize, threadNum), 
    rangeIsSet_(false),
    filePath_(filePath)
{
    tempFilePath_ = filePath + ".temp";
}

DownloadObjectRequest::DownloadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath, const std::string &checkpointDir) : 
    DownloadObjectRequest(bucket, key, filePath, checkpointDir, DefaultPartSize, DefaultResumableThreadNum)
{}

DownloadObjectRequest::DownloadObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &filePath) :
    DownloadObjectRequest(bucket, key, filePath, "", DefaultPartSize, DefaultResumableThreadNum)
{}

void DownloadObjectRequest::setRange(int64_t start, int64_t end)
{
    range_[0] = start;
    range_[1] = end;
    rangeIsSet_ = true;
}

void DownloadObjectRequest::setModifiedSinceConstraint(const std::string &value)
{
    modifiedSince_ = value;
}

void DownloadObjectRequest::setUnmodifiedSinceConstraint(const std::string &value)
{
    unmodifiedSince_ = value;
}

void DownloadObjectRequest::setMatchingETagConstraints(const std::vector<std::string> &values)
{
    matchingETags_ = values;
}

void DownloadObjectRequest::setNonmatchingETagConstraints(const std::vector<std::string> &values)
{
    nonmatchingETags_ = values;
}

void DownloadObjectRequest::addResponseHeaders(RequestResponseHeader header, const std::string &value)
{
    static const char *ResponseHeader[] = {
        "response-content-type", "response-content-language",
        "response-expires", "response-cache-control",
        "response-content-disposition", "response-content-encoding" };
    responseHeaderParameters_[ResponseHeader[header - RequestResponseHeader::ContentType]] = value;
}

int DownloadObjectRequest::validate() const
{
    if (partSize_ < PartSizeLowerLimit) {
        return ARG_ERROR_CHECK_PART_SIZE_LOWER;
    }

    if (threadNum_ <= 0) {
        return ARG_ERROR_CHECK_THREAD_NUM_LOWER;
    }

    if (rangeIsSet_ && (range_[0] < 0 || range_[1] < -1 || (range_[1] > -1 && range_[1] < range_[0]))) {
        return ARG_ERROR_INVALID_RANGE;
    }

    if (filePath_.empty()) {
        return ARG_ERROR_UPLOAD_FILE_PATH_EMPTY;
    }
    else {
        std::fstream tmpfs(tempFilePath_, std::ios::out | std::ios::app);
        if (!tmpfs.is_open()) {
            return ARG_ERROR_OPEN_DOWNLOAD_TEMP_FILE;
        }
    }

    // if directory do not exist, return error
    if (!checkpointDir_.empty()) {
        if (!IsDirectoryExist(checkpointDir_)) {
            return ARG_ERROR_CHECK_POINT_DIR_NONEXIST;
        }
    }
    return 0;
}
