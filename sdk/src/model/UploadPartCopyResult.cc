
#include <inspurcloud/oss/model/UploadPartCopyResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

static const std::string EMPTY;

UploadPartCopyResult::UploadPartCopyResult() :
    OssResult()
{
}

UploadPartCopyResult::UploadPartCopyResult(
    const std::string& result):
    UploadPartCopyResult()
{
    *this = result;
    
}

UploadPartCopyResult::UploadPartCopyResult(
    const std::shared_ptr<std::iostream>& result,
    const HeaderCollection &header):
    UploadPartCopyResult()
{
    headers = header;
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
    if (header.find("x-oss-request-id") != header.end()) {
        requestId_ = header.at("x-oss-request-id");
    }
}

UploadPartCopyResult& UploadPartCopyResult::operator =(
    const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("CopyPartResult", root->Name(), 14)) {
            XMLElement *node;

            node = root->FirstChildElement("LastModified");
            if (node && node->GetText()) {
                lastModified_ = node->GetText();
            }

            node = root->FirstChildElement("ETag");
            if (node && node->GetText()) {
                eTag_ = TrimQuotes(node->GetText());
            }
            parseDone_ = true;
		}
    }
    return *this;
}

const std::string& UploadPartCopyResult::LastModified() const
{
    return lastModified_;
}
const std::string& UploadPartCopyResult::ETag() const
{
    return eTag_;
}
