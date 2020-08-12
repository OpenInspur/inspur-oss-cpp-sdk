#include <inspurcloud/oss/model/Tagging.h>
#include "../utils/Utils.h"
#include <sstream>

using namespace InspurCloud::OSS;

std::string Tagging::toQueryParameters()
{
    std::string sep;
    std::stringstream ss;
    for (const auto& tag : tagSet_)
    {
        if (tag.Key().empty())
            continue;

        if (tag.Value().empty())
            ss << sep << UrlEncode(tag.Key());
        else
            ss << sep << UrlEncode(tag.Key()) << "=" << UrlEncode(tag.Value());

        sep = "&";
    }
    return ss.str();
}
