
#include <inspurcloud/oss/model/GetBucketEncryptionResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketEncryptionResult::GetBucketEncryptionResult() :
    OssResult()
{
}

GetBucketEncryptionResult::GetBucketEncryptionResult(const std::string& result) :
    GetBucketEncryptionResult()
{
    *this = result;
}

GetBucketEncryptionResult::GetBucketEncryptionResult(const std::shared_ptr<std::iostream>& result) :
    GetBucketEncryptionResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketEncryptionResult& GetBucketEncryptionResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root = doc.RootElement();
        if (root && !std::strncmp("ServerSideEncryptionConfiguration", root->Name(), 24)) {
            XMLElement* rule;
            rule = root->FirstChildElement("Rule");
            if (rule) 
            {
                XMLElement* node;
                node = rule->FirstChildElement("ApplyServerSideEncryptionByDefault");
                if (node) {
                    XMLElement* sub_node;
                    sub_node = node->FirstChildElement("SSEAlgorithm");
                    if (sub_node && sub_node->GetText()) SSEAlgorithm_ = ToSSEAlgorithm(sub_node->GetText());

                    sub_node = node->FirstChildElement("KMSMasterKeyID");
                    if (sub_node && sub_node->GetText()) KMSMasterKeyID_ = sub_node->GetText();
                }
            }
            parseDone_ = true;
        }
    }
    return *this;
}