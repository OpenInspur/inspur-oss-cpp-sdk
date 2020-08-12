

#include <inspurcloud/oss/model/CopyObjectResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;
using namespace tinyxml2;

CopyObjectResult::CopyObjectResult() :
    OssResult()
{
}

CopyObjectResult::CopyObjectResult(const std::string& data):
    CopyObjectResult()
{
    *this = data;
}

CopyObjectResult::CopyObjectResult(const std::shared_ptr<std::iostream>& data):
    CopyObjectResult()
{
    std::istreambuf_iterator<char> isb(*data.get()), end;
    std::string str(isb, end);
    *this = str;
}

CopyObjectResult& CopyObjectResult::operator =(const std::string& data)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(data.c_str(), data.size())) == XML_SUCCESS) {
        XMLElement* root = doc.RootElement();
        if (root && !std::strncmp("CopyObjectResult", root->Name(), strlen("CopyObjectResult"))) {
            XMLElement *node;
            node = root->FirstChildElement("LastModified");
            if (node && node->GetText()) {
                lastModified_ = node->GetText();
            }

            node = root->FirstChildElement("ETag");
            if (node && node->GetText()) {
                etag_ = TrimQuotes(node->GetText());
            }

            //TODO check the result and the parse flag;
            parseDone_ = true;
        }
    }
    return *this;
}

