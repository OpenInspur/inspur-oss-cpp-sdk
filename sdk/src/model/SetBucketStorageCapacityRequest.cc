#include <inspurcloud/oss/model/SetBucketStorageCapacityRequest.h>
#include "../utils/Utils.h"
#include "ModelError.h"
#include <sstream>

using namespace InspurCloud::OSS;

SetBucketStorageCapacityRequest::SetBucketStorageCapacityRequest(const std::string &bucket, int64_t storageCapacity) :
    OssBucketRequest(bucket),
    storageCapacity_(storageCapacity)
{
    setFlags(Flags() | REQUEST_FLAG_CONTENTMD5);
}

ParameterCollection SetBucketStorageCapacityRequest::specialParameters() const
{
    ParameterCollection parameters;
    parameters["qos"] = "";
    return parameters;
}

std::string SetBucketStorageCapacityRequest::payload() const
{
    std::stringstream ss;
    ss << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
    ss << "<BucketUserQos>" << std::endl;
    ss << "  <StorageCapacity>" << std::to_string(storageCapacity_) << "</StorageCapacity>" << std::endl;
    ss << "</BucketUserQos>" << std::endl;
    return ss.str();
}

int SetBucketStorageCapacityRequest::validate() const
{
    int ret;
    if ((ret = OssBucketRequest::validate()) != 0) {
        return ret;
    }

    if (storageCapacity_ < 0)
        return ARG_ERROR_STORAGECAPACITY_INVALID;

    return 0;
}


