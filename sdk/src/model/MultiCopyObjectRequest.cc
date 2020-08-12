
#include <inspurcloud/oss/model/MultiCopyObjectRequest.h>
#include <inspurcloud/oss/Const.h>
#include <sstream>
#include "../utils/FileSystemUtils.h"
#include "../utils/Utils.h"
#include "ModelError.h"

using namespace InspurCloud::OSS;
static const std::string strEmpty = "";

MultiCopyObjectRequest::MultiCopyObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &srcBucket, const std::string &srcKey) :
    MultiCopyObjectRequest(bucket, key, srcBucket, srcKey, "", DefaultPartSize, DefaultResumableThreadNum)
{}

MultiCopyObjectRequest::MultiCopyObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &srcBucket, const std::string &srcKey, const std::string &checkpointDir) :
    MultiCopyObjectRequest(bucket, key, srcBucket, srcKey, checkpointDir, DefaultPartSize, DefaultResumableThreadNum)
{}

MultiCopyObjectRequest::MultiCopyObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &srcBucket, const std::string &srcKey,
    const std::string &checkpointDir, const ObjectMetaData& meta): 
    MultiCopyObjectRequest(bucket, key, srcBucket, srcKey, checkpointDir, DefaultPartSize, DefaultResumableThreadNum, meta)
{}

MultiCopyObjectRequest::MultiCopyObjectRequest(const std::string &bucket, const std::string &key, 
    const std::string &srcBucket, const std::string &srcKey,
    const std::string &checkpointDir, uint64_t partSize, uint32_t threadNum, const ObjectMetaData& meta):
    MultiCopyObjectRequest(bucket, key, srcBucket, srcKey, checkpointDir, partSize, threadNum)
{
    metaData_ = meta;
}

MultiCopyObjectRequest::MultiCopyObjectRequest(const std::string &bucket, const std::string &key, const std::string &srcBucket, const std::string &srcKey,
    const std::string &checkpointDir, uint64_t partSize, uint32_t threadNum) :
    OssResumableBaseRequest(bucket, key, checkpointDir, partSize, threadNum), srcBucket_(srcBucket), srcKey_(srcKey) 
{
    setCopySource(srcBucket, srcKey);
}

void MultiCopyObjectRequest::setCopySource(const std::string& srcBucket, const std::string& srcObject)
{
    std::stringstream ssDesc;
    ssDesc << "/" << srcBucket << "/" << srcObject;
    std::string value = ssDesc.str();
    metaData_.addHeader("x-oss-copy-source", value);
}

void MultiCopyObjectRequest::setSourceIfMatchEtag(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-match", value);
}

const std::string& MultiCopyObjectRequest::SourceIfMatchEtag() const
{
    if (metaData_.HttpMetaData().find("x-oss-copy-source-if-match") != metaData_.HttpMetaData().end()) {
        return metaData_.HttpMetaData().at("x-oss-copy-source-if-match");
    }
    return strEmpty;
}

void MultiCopyObjectRequest::setSourceIfNotMatchEtag(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-none-match", value);
}

const std::string& MultiCopyObjectRequest::SourceIfNotMatchEtag() const
{
    if (metaData_.HttpMetaData().find("x-oss-copy-source-if-none-match") != metaData_.HttpMetaData().end()) {
        return metaData_.HttpMetaData().at("x-oss-copy-source-if-none-match");
    }
    return strEmpty;
}

void MultiCopyObjectRequest::setSourceIfUnModifiedSince(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-unmodified-since", value);
}

const std::string& MultiCopyObjectRequest::SourceIfUnModifiedSince() const
{
    if (metaData_.HttpMetaData().find("x-oss-copy-source-if-unmodified-since") != metaData_.HttpMetaData().end()) {
        return metaData_.HttpMetaData().at("x-oss-copy-source-if-unmodified-since");
    }
    return strEmpty;
}

void MultiCopyObjectRequest::setSourceIfModifiedSince(const std::string& value)
{
    metaData_.addHeader("x-oss-copy-source-if-modified-since", value);
}

const std::string& MultiCopyObjectRequest::SourceIfModifiedSince() const
{
    if (metaData_.HttpMetaData().find("x-oss-copy-source-if-modified-since") != metaData_.HttpMetaData().end()) {
        return metaData_.HttpMetaData().at("x-oss-copy-source-if-modified-since");
    }
    return strEmpty;
}

void MultiCopyObjectRequest::setMetadataDirective(const CopyActionList& action)
{
    metaData_.addHeader("x-oss-metadata-directive", ToCopyActionName(action));
}

void MultiCopyObjectRequest::setAcl(const CannedAccessControlList& acl)
{
    metaData_.addHeader("x-oss-object-acl", ToAclName(acl));
}

int MultiCopyObjectRequest::validate() const 
{
    if (partSize_ < PartSizeLowerLimit) {
        return ARG_ERROR_CHECK_PART_SIZE_LOWER;
	}

    if (threadNum_ <= 0) {
        return ARG_ERROR_CHECK_THREAD_NUM_LOWER;
    }

    // if directory do not exist, return error
    if (!checkpointDir_.empty()) {
        if (!IsDirectoryExist(checkpointDir_)) {
            return ARG_ERROR_CHECK_POINT_DIR_NONEXIST;
        }
    }

    return 0;
}
