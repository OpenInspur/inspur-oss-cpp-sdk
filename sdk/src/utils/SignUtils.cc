#include "SignUtils.h"
#include "Utils.h"
#include <sstream>
#include <map>
#include <set>
#include <inspurcloud/oss/Const.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/http/HttpType.h>

using namespace InspurCloud::OSS;

const static std::set<std::string> ParamtersToSign =
{
    "acl", "location", "bucketInfo", "stat", "referer", "cors", "website", "restore",
    "logging", "symlink", "qos", "uploadId", "uploads", "partNumber",
    "response-content-type", "response-content-language", "response-expires",
    "response-cache-control", "response-content-disposition", "response-content-encoding",
    "append", "position", "lifecycle", "delete", "live", "status", "comp", "vod",
    "startTime", "endTime", "x-oss-process", "security-token", "objectMeta",
    "callback", "callback-var", "tagging", "policy", "requestPayment", "x-oss-traffic-limit", "encryption"
};

SignUtils::SignUtils(const std::string &version):
    signVersion_(version),
    canonicalString_()
{
}

SignUtils::~SignUtils()
{
}

const std::string &SignUtils::CanonicalString() const
{
    return canonicalString_;
}

void SignUtils::build(const std::string &method, 
                      const std::string &resource, 
                      const std::string &date,
                      const HeaderCollection &headers,
                      const ParameterCollection &parameters)
{
    std::stringstream ss;

    /*Version 1*/
    // VERB + "\n" +
    // Content-MD5 + "\n"  +
    // Content-Type + "\n" 
    // Date + "\n"  +
    // CanonicalizedOSSHeaders +
    // CanonicalizedResource) +

    //common headers
    ss << method << "\n";              //��������
    if (headers.find(Http::CONTENT_MD5) != headers.end()) {         //��û��MD5, �еĻ�������ֵ��û��ֻ���뻻��
        ss << headers.at(Http::CONTENT_MD5);
    }
    ss << "\n";
    if (headers.find(Http::CONTENT_TYPE) != headers.end()) {        //��û��CONTENT_TYPE, �еĻ�������ֵ��û��ֻ���뻻��
        ss << headers.at(Http::CONTENT_TYPE);
    }
    ss << "\n";
    //Date or EXPIRES
    ss << date << "\n";				//data�ǿ϶��еģ���ʹ����ʱ��Ȩʱ������������

    //CanonicalizedOSSHeaders, start with x-oss-             //ֻ������x-oss-��ͷ��header������õ�ֵ
    for (const auto &header : headers) {
        std::string lower = Trim(ToLower(header.first.c_str()).c_str());
        if (lower.compare(0, 6, "x-oss-", 6) == 0) {
            std::string value = Trim(header.second.c_str());
            ss << lower << ":" << value << "\n";
        }
    }

    //CanonicalizedResource, the sub resouce in
    ss << resource;
    char separator = '?';
    for (auto const& param : parameters) {
        if (ParamtersToSign.find(param.first) == ParamtersToSign.end()) {
            continue;
        }
		if (param.first == "append" || param.first == "position") {
			continue;		
		}
        ss << separator;
        ss << param.first;
        if (!param.second.empty()) {
            ss << "=" << param.second;
        }
        separator = '&';
    }

    canonicalString_ = ss.str();
}

void SignUtils::build(const std::string &expires,
    const std::string &resource,
    const ParameterCollection &parameters)
{
    std::stringstream ss;
    ss << expires << '\n';
    for(auto const& param : parameters)
    {
        ss << param.first << ":" << param.second << '\n';
    }
    ss << resource;
    canonicalString_ = ss.str();
}
