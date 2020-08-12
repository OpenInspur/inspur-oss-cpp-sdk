
#include <inspurcloud/oss/model/GetBucketStatResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketStatResult::GetBucketStatResult() :
    OssResult(),
    storage_(0),
    objectCount_(0),
    multipartUploadCount_(0)
{
}

GetBucketStatResult::GetBucketStatResult(const std::string& result):
    GetBucketStatResult()
{
    *this = result;
}

GetBucketStatResult::GetBucketStatResult(const std::shared_ptr<std::iostream>& result):
    GetBucketStatResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketStatResult& GetBucketStatResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("BucketStat", root->Name(), 10)) {
            XMLElement *node;
            node = root->FirstChildElement("Storage");
            if (node && node->GetText()) storage_ = atoll(node->GetText());

            node = root->FirstChildElement("ObjectCount");
            if (node && node->GetText()) objectCount_ = atoll(node->GetText());

            node = root->FirstChildElement("MultipartUploadCount");
            if (node && node->GetText()) multipartUploadCount_ = atoll(node->GetText());

            parseDone_ = true;
		}
    }
    return *this;
}

