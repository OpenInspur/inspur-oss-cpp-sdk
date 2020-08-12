
#include <inspurcloud/oss/model/PutLiveChannelResult.h>
#include <tinyxml2/tinyxml2.h>
#include <inspurcloud/oss/model/Bucket.h>
#include <inspurcloud/oss/model/Owner.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

PutLiveChannelResult::PutLiveChannelResult():
    OssResult()
{
}

PutLiveChannelResult::PutLiveChannelResult(const std::string& result):
    PutLiveChannelResult()
{
    *this = result;
}

PutLiveChannelResult::PutLiveChannelResult(const std::shared_ptr<std::iostream>& result):
    PutLiveChannelResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

PutLiveChannelResult& PutLiveChannelResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("CreateLiveChannelResult", root->Name(), 23)) {
            XMLElement *node;
            
            XMLElement* publishNode = root->FirstChildElement("PublishUrls");
            if(publishNode && (node = publishNode->FirstChildElement("Url"))){
                publishUrl_ = node->GetText();
            }

            XMLElement* playNode = root->FirstChildElement("PlayUrls");
            if(playNode && (node = playNode->FirstChildElement("Url"))){
                playUrl_ = node->GetText();
            }
        }
        parseDone_ = true;
    }
    return *this;
}

const std::string& PutLiveChannelResult::PublishUrl() const
{
    return publishUrl_;
}

const std::string& PutLiveChannelResult::PlayUrl() const
{
    return playUrl_;
}

