
#include <inspurcloud/oss/model/InitiateMultipartUploadResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

InitiateMultipartUploadResult::InitiateMultipartUploadResult() :
    OssResult()
{
}

InitiateMultipartUploadResult::InitiateMultipartUploadResult(const std::string& result):
    InitiateMultipartUploadResult()
{
    *this = result;
}

InitiateMultipartUploadResult::InitiateMultipartUploadResult(const std::shared_ptr<std::iostream>& result):
    InitiateMultipartUploadResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

InitiateMultipartUploadResult& InitiateMultipartUploadResult::operator =(
    const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("InitiateMultipartUploadResult", root->Name(), 29)) {
            XMLElement *node;

            node = root->FirstChildElement("EncodingType");
            if (node && node->GetText()) encodingType_ = node->GetText();

            //Detect encode type
            bool useUrlDecode = !ToLower(encodingType_.c_str()).compare(0, 3, "url", 3);

            node = root->FirstChildElement("Bucket");
            if (node && node->GetText()) bucket_ = node->GetText();

            node = root->FirstChildElement("Key");
            if (node && node->GetText()) key_ = useUrlDecode ? UrlDecode(node->GetText()) : node->GetText();

            node = root->FirstChildElement("UploadId");
            if (node && node->GetText()) uploadId_ = node->GetText();

            parseDone_ = true;
		}
    }
    return *this;
}
