
#include <inspurcloud/oss/model/GetBucketCorsResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

GetBucketCorsResult::GetBucketCorsResult() :
    OssResult()
{
}

GetBucketCorsResult::GetBucketCorsResult(const std::string& result):
    GetBucketCorsResult()
{
    *this = result;
}

GetBucketCorsResult::GetBucketCorsResult(const std::shared_ptr<std::iostream>& result):
    GetBucketCorsResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketCorsResult& GetBucketCorsResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("CORSConfiguration", root->Name(), 17)) {
            XMLElement *rule_node = root->FirstChildElement("CORSRule");
            for (; rule_node; rule_node = rule_node->NextSiblingElement("CORSRule")) {
                XMLElement *node = rule_node->FirstChildElement();
                CORSRule rule;
                for (; node; node = node->NextSiblingElement()) {

                    if (!strncmp(node->Name(), "AllowedOrigin", 13))
                        if (node->GetText()) rule.addAllowedOrigin(node->GetText());

                    if (!strncmp(node->Name(), "AllowedMethod", 13))
                        if (node->GetText()) rule.addAllowedMethod(node->GetText());

                    if (!strncmp(node->Name(), "AllowedHeader", 13))
                        if (node->GetText()) rule.addAllowedHeader(node->GetText());

                    if (!strncmp(node->Name(), "ExposeHeader", 12))
                        if (node->GetText()) rule.addExposeHeader(node->GetText());

                    if (!strncmp(node->Name(), "MaxAgeSeconds", 13))
                        if (node->GetText()) rule.setMaxAgeSeconds(std::atoi(node->GetText()));
                }
                ruleList_.push_back(rule);
            }
            parseDone_ = true;
        }
    }
    return *this;
}
