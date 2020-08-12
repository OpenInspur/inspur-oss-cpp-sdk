
#include <inspurcloud/oss/model/GetObjectTaggingResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

GetObjectTaggingResult::GetObjectTaggingResult() :
    OssResult()
{
}

GetObjectTaggingResult::GetObjectTaggingResult(const std::string& result):
    GetObjectTaggingResult()
{
    *this = result;
}

GetObjectTaggingResult::GetObjectTaggingResult(const std::shared_ptr<std::iostream>& result):
    GetObjectTaggingResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetObjectTaggingResult& GetObjectTaggingResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("Tagging", root->Name(), 7)) {
            XMLElement* tagSet_node = root->FirstChildElement("TagSet");
            if (tagSet_node) {
                XMLElement *tag_node = tagSet_node->FirstChildElement("Tag");
                for (; tag_node; tag_node = tag_node->NextSiblingElement("Tag")) {
                    XMLElement *subNode;
                    Tag tag;
                    //Key
                    subNode = tag_node->FirstChildElement("Key");
                    if (subNode && subNode->GetText()) {
                        tag.setKey(subNode->GetText());
                    }
                    //Value
                    subNode = tag_node->FirstChildElement("Value");
                    if (subNode && subNode->GetText()) {
                        tag.setValue(subNode->GetText());
                    }
                    tagging_.addTag(tag);
                }
            }
            //TODO check the result and the parse flag;
            parseDone_ = true;
        }
    }
    return *this;
}

