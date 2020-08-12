
#include <inspurcloud/oss/model/GetBucketLocationResult.h>
#include <tinyxml2/tinyxml2.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;


GetBucketLocationResult::GetBucketLocationResult() :
    OssResult()
{
}

GetBucketLocationResult::GetBucketLocationResult(const std::string& result):
    GetBucketLocationResult()
{
    *this = result;
}

GetBucketLocationResult::GetBucketLocationResult(const std::shared_ptr<std::iostream>& result):
    GetBucketLocationResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketLocationResult& GetBucketLocationResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("LocationConstraint", root->Name(), 18)) {
            if (root->GetText()) 
                location_ = root->GetText();

		    parseDone_ = true;
		}
    }
    return *this;
}
