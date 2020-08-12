
#include <inspurcloud/oss/model/GetBucketWebsiteResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketWebsiteResult::GetBucketWebsiteResult() :
    OssResult()
{
}

GetBucketWebsiteResult::GetBucketWebsiteResult(const std::string& result):
    GetBucketWebsiteResult()
{
    *this = result;
}

GetBucketWebsiteResult::GetBucketWebsiteResult(const std::shared_ptr<std::iostream>& result):
    GetBucketWebsiteResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketWebsiteResult& GetBucketWebsiteResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("WebsiteConfiguration", root->Name(), 20)) {
            XMLElement *node;
            node = root->FirstChildElement("IndexDocument");
            if (node) node = node->FirstChildElement("Suffix");
            if (node && node->GetText()) indexDocument_ = node->GetText();

            node = root->FirstChildElement("ErrorDocument");
            if (node) node = node->FirstChildElement("Key");
            if (node && node->GetText()) errorDocument_ = node->GetText();
		    parseDone_ = true;
		}
    }
    return *this;
}
