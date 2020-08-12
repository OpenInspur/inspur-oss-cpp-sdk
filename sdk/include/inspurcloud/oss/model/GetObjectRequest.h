#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>
#include <vector>
#include <map>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT GetObjectRequest: public OssObjectRequest
    {
    public:
        GetObjectRequest(const std::string& bucket, const std::string& key);
        GetObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& process);
        GetObjectRequest(const std::string &bucket, const std::string &key, 
            const std::string &modifiedSince, const std::string &unmodifiedSince, 
            const std::vector<std::string> &matchingETags, const std::vector<std::string> &nonmatchingETags, 
            const std::map<std::string, std::string> &responseHeaderParameters_);
        void setRange(int64_t start, int64_t end);
        void setModifiedSinceConstraint(const std::string& gmt);
        void setUnmodifiedSinceConstraint(const std::string& gmt);
        void setMatchingETagConstraints(const std::vector<std::string>& match);
        void addMatchingETagConstraint(const std::string& match);
        void setNonmatchingETagConstraints(const std::vector<std::string>& match);
        void addNonmatchingETagConstraint(const std::string& match);
        void setProcess(const std::string& process);
        void addResponseHeaders(RequestResponseHeader header, const std::string& value);
        void setTrafficLimit(uint64_t value);
        void setCustomerSSEKey(const std::string &value);

    protected:
        virtual HeaderCollection specialHeaders() const ;
        virtual ParameterCollection specialParameters() const;
        virtual int validate() const;
    private:
        int64_t range_[2];
        bool rangeIsSet_;
        std::string modifiedSince_;
        std::string unmodifiedSince_;
        std::vector<std::string> matchingETags_;
        std::vector<std::string> nonmatchingETags_;
        std::string process_;
        std::map<std::string, std::string> responseHeaderParameters_;
        uint64_t trafficLimit_;
        std::string CustomerSSEKey_;
    };
} 
}
