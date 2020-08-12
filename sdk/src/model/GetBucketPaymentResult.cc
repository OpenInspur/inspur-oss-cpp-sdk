
#include <inspurcloud/oss/model/GetBucketPaymentResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;
using namespace tinyxml2;

GetBucketPaymentResult::GetBucketPaymentResult() :
    OssResult()
{
}

GetBucketPaymentResult::GetBucketPaymentResult(const std::string& result) :
    GetBucketPaymentResult()
{
    *this = result;
}

GetBucketPaymentResult::GetBucketPaymentResult(const std::shared_ptr<std::iostream>& result) :
    GetBucketPaymentResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketPaymentResult& GetBucketPaymentResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root = doc.RootElement();
        if (root && !std::strncmp("RequestPaymentConfiguration", root->Name(), 27)) {
            XMLElement* node;
            node = root->FirstChildElement("Payer");
            if (node && node->GetText()) payer_ = ToRequestPayer(node->GetText());
            parseDone_ = true;
        }
    }
    return *this;
}
