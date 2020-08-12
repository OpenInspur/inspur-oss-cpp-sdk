
#include <inspurcloud/oss/model/GetBucketStorageCapacityResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

GetBucketStorageCapacityResult::GetBucketStorageCapacityResult() :
    OssResult(),
    storageCapacity_(-1)
{
}

GetBucketStorageCapacityResult::GetBucketStorageCapacityResult(const std::string& result):
    GetBucketStorageCapacityResult()
{
    *this = result;
}

GetBucketStorageCapacityResult::GetBucketStorageCapacityResult(const std::shared_ptr<std::iostream>& result):
    GetBucketStorageCapacityResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketStorageCapacityResult& GetBucketStorageCapacityResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("BucketUserQos", root->Name(), 13)) {
            XMLElement *node = root->FirstChildElement("StorageCapacity");
            if (node && node->GetText()) storageCapacity_ = std::atoll(node->GetText());

            parseDone_ = true;
        }
    }
    return *this;
}
