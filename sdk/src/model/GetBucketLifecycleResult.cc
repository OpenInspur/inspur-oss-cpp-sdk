
#include <inspurcloud/oss/model/GetBucketLifecycleResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketLifecycleResult::GetBucketLifecycleResult() :
    OssResult()
{
}

GetBucketLifecycleResult::GetBucketLifecycleResult(const std::string& result):
    GetBucketLifecycleResult()
{
    *this = result;
}

GetBucketLifecycleResult::GetBucketLifecycleResult(const std::shared_ptr<std::iostream>& result):
    GetBucketLifecycleResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketLifecycleResult& GetBucketLifecycleResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("LifecycleConfiguration", root->Name(), 22)) {
            XMLElement *rule_node = root->FirstChildElement("Rule");
            for (; rule_node; rule_node = rule_node->NextSiblingElement("Rule")) {
                LifecycleRule rule;
                XMLElement *node;
                node = rule_node->FirstChildElement("ID");
                if (node && node->GetText()) rule.setID(node->GetText());

                node = rule_node->FirstChildElement("Prefix");
                if (node && node->GetText()) rule.setPrefix(node->GetText());

                node = rule_node->FirstChildElement("Status");
                if (node && node->GetText()) rule.setStatus(ToRuleStatusType(node->GetText()));

                node = rule_node->FirstChildElement("Expiration");
                if (node) {
                    XMLElement *subNode;
                    //Days
                    subNode = node->FirstChildElement("Days");
                    if (subNode && subNode->GetText()) {
                        rule.Expiration().setDays(std::stoi(subNode->GetText(), nullptr, 10));
                    }
                    //CreatedBeforeDate
                    subNode = node->FirstChildElement("CreatedBeforeDate");
                    if (subNode && subNode->GetText()) {
                        rule.Expiration().setCreatedBeforeDate(subNode->GetText());
                    }
                }

                node = rule_node->FirstChildElement("Transition");
                for (; node; node = node->NextSiblingElement("Transition")) {
                    LifeCycleTransition transiton;
                    XMLElement *subNode;
                    //Days
                    subNode = node->FirstChildElement("Days");
                    if (subNode && subNode->GetText()) {
                        transiton.Expiration().setDays(std::stoi(subNode->GetText(), nullptr, 10));
                    }
                    //CreatedBeforeDate
                    subNode = node->FirstChildElement("CreatedBeforeDate");
                    if (subNode && subNode->GetText()) {
                        transiton.Expiration().setCreatedBeforeDate(subNode->GetText());
                    }
                    //StorageClass
                    subNode = node->FirstChildElement("StorageClass");
                    if (subNode && subNode->GetText()) {
                        transiton.setStorageClass(ToStorageClassType(subNode->GetText()));
                    }
                    rule.addTransition(transiton);
                }

                node = rule_node->FirstChildElement("AbortMultipartUpload");
                if (node) {
                    XMLElement *subNode;
                    //Days
                    subNode = node->FirstChildElement("Days");
                    if (subNode && subNode->GetText()) {
                        rule.AbortMultipartUpload().setDays(std::stoi(subNode->GetText(), nullptr, 10));
                    }
                    //CreatedBeforeDate
                    subNode = node->FirstChildElement("CreatedBeforeDate");
                    if (subNode && subNode->GetText()) {
                        rule.AbortMultipartUpload().setCreatedBeforeDate(subNode->GetText());
                    }
                }

                node = rule_node->FirstChildElement("Tag");
                for (; node; node = node->NextSiblingElement("Tag")) {
                    Tag tag;
                    XMLElement *subNode;
                    //Key
                    subNode = node->FirstChildElement("Key");
                    if (subNode && subNode->GetText()) {
                        tag.setKey(subNode->GetText());
                    }
                    //Value
                    subNode = node->FirstChildElement("Value");
                    if (subNode && subNode->GetText()) {
                        tag.setValue(subNode->GetText());
                    }
                    rule.addTag(tag);
                }

                lifecycleRuleList_.emplace_back(std::move(rule));
            }
		    parseDone_ = true;
		}
    }
    return *this;
}
