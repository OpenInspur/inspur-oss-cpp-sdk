
#include <inspurcloud/oss/model/GetLiveChannelHistoryResult.h>
#include <inspurcloud/oss/model/Owner.h>
#include <tinyxml2/tinyxml2.h>
#include <sstream>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

GetLiveChannelHistoryResult::GetLiveChannelHistoryResult() :
    OssResult()
{
    
}

GetLiveChannelHistoryResult::GetLiveChannelHistoryResult(const std::string& result):
    GetLiveChannelHistoryResult()
{
    *this = result;
}

GetLiveChannelHistoryResult::GetLiveChannelHistoryResult(const std::shared_ptr<std::iostream>& result):
    GetLiveChannelHistoryResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetLiveChannelHistoryResult& GetLiveChannelHistoryResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("LiveChannelHistory", root->Name(), 18)) {
            XMLElement *node;
            XMLElement *recordNode = root->FirstChildElement("LiveRecord");
            for(; recordNode; recordNode = recordNode->NextSiblingElement("LiveRecord"))
            {
                LiveRecord rec;
                node = recordNode->FirstChildElement("StartTime");
                if(node && node->GetText())
                {
                    rec.startTime = node->GetText();
                }
                node = recordNode->FirstChildElement("EndTime");
                if(node && node->GetText())
                {
                    rec.endTime = node->GetText();
                }
                node = recordNode->FirstChildElement("RemoteAddr");
                if(node && node->GetText())
                {
                    rec.remoteAddr = node->GetText();
                }
                recordList_.push_back(rec);
            }
            parseDone_ = true;
        }
    }
    return *this;
}

const LiveRecordVec& GetLiveChannelHistoryResult::LiveRecordList() const
{
    return recordList_;
}
