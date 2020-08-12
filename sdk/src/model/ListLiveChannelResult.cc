
#include <inspurcloud/oss/model/ListLiveChannelResult.h>
#include <tinyxml2/tinyxml2.h>
#include <inspurcloud/oss/model/Bucket.h>
#include <inspurcloud/oss/model/Owner.h>
#include <sstream>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

ListLiveChannelResult::ListLiveChannelResult():
    OssResult(),maxKeys_(0)
{
}

ListLiveChannelResult::ListLiveChannelResult(const std::string& result):
    ListLiveChannelResult()
{
    *this = result;
}

ListLiveChannelResult::ListLiveChannelResult(const std::shared_ptr<std::iostream>& result):
    ListLiveChannelResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

ListLiveChannelResult& ListLiveChannelResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("ListLiveChannelResult", root->Name(), 21)) {
            XMLElement *node;
            node = root->FirstChildElement("Prefix");
            if(node && node->GetText())
            {
                prefix_ = node->GetText();
            }
            
            node = root->FirstChildElement("Marker");
            if(node && node->GetText())
            {
                marker_ = node->GetText();
            }

            node = root->FirstChildElement("MaxKeys");
            if(node && node->GetText())
            {
                maxKeys_ = std::strtoul(node->GetText(), nullptr, 10);
            }

            node = root->FirstChildElement("IsTruncated");
            if(node && node->GetText())
            {
                isTruncated_ = node->BoolText();
            }

            node = root->FirstChildElement("NextMarker");
            if(node && node->GetText())
            {
                nextMarker_ = node->GetText();
            }

            XMLNode *livechannelNode = root->FirstChildElement("LiveChannel");
            for(; livechannelNode; livechannelNode = livechannelNode->NextSiblingElement("LiveChannel"))
            {
                LiveChannelInfo info;
                node = livechannelNode->FirstChildElement("Name");
                if(node && node->GetText())
                {
                    info.name = node->GetText();
                }

                node = livechannelNode->FirstChildElement("Description");
                if(node && node->GetText())
                {
                    info.description = node->GetText();
                }

                node = livechannelNode->FirstChildElement("Status");
                if(node && node->GetText())
                {
                    info.status = node->GetText();
                }

                node = livechannelNode->FirstChildElement("LastModified");
                if(node && node->GetText())
                {
                    info.lastModified = node->GetText();
                }

                XMLNode *publishNode = livechannelNode->FirstChildElement("PublishUrls");
                if(publishNode)
                {
                    node = publishNode->FirstChildElement("Url");
                    if(node && node->GetText())
                    {
                        info.publishUrl = node->GetText();
                    }
                }

                XMLNode *playNode = livechannelNode->FirstChildElement("PlayUrls");
                if(playNode)
                {
                    node = playNode->FirstChildElement("Url");
                    if(node && node->GetText())
                    {
                        info.playUrl = node->GetText();
                    }
                }
                liveChannelList_.push_back(info);
            }
            parseDone_ = true;
        }
    }
    return *this;
}

const std::string& ListLiveChannelResult::Marker() const
{
    return marker_;
}

uint32_t ListLiveChannelResult::MaxKeys() const
{
    return maxKeys_;
}

const std::string& ListLiveChannelResult::Prefix() const
{
    return prefix_;
}

const std::string& ListLiveChannelResult::NextMarker() const
{
    return nextMarker_;
}

bool ListLiveChannelResult::IsTruncated() const
{
    return isTruncated_;
}

const LiveChannelListInfo& ListLiveChannelResult::LiveChannelList() const
{
    return liveChannelList_;
}



