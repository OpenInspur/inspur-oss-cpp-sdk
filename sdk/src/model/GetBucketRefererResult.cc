
#include <inspurcloud/oss/model/GetBucketRefererResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketRefererResult::GetBucketRefererResult() :
    OssResult()
{
}

GetBucketRefererResult::GetBucketRefererResult(const std::string& result):
    GetBucketRefererResult()
{
    *this = result;
}

GetBucketRefererResult::GetBucketRefererResult(const std::shared_ptr<std::iostream>& result):
    GetBucketRefererResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketRefererResult& GetBucketRefererResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("RefererConfiguration", root->Name(), 20)) {
            XMLElement *node;
            node = root->FirstChildElement("AllowEmptyReferer");
            if (node && node->GetText()) allowEmptyReferer_ = (std::strncmp(node->GetText(), "true", 4)? false:true);

            node = root->FirstChildElement("RefererList");
            if (node) {
                XMLElement *referer_node = node->FirstChildElement("Referer");
                for (; referer_node; referer_node = referer_node->NextSiblingElement()) {
                    if (referer_node->GetText())
                        refererList_.push_back(referer_node->GetText());
                }
            }
		    parseDone_ = true;
		}
    }
    return *this;
}
