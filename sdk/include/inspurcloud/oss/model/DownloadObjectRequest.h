
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/ObjectMetaData.h>

namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT DownloadObjectRequest : public OssResumableBaseRequest 
    {
    public:
        DownloadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath);
        DownloadObjectRequest(const std::string& bucket, const std::string& key, 
            const std::string& filePath, const std::string& checkpointDir, 
            const uint64_t partSize, const uint32_t threadNum);
        DownloadObjectRequest(const std::string& bucket, const std::string& key,
            const std::string& filePath, const std::string& checkpointDir);

        std::shared_ptr<std::iostream> Content() { return content_; }
        const std::string& FilePath() const { return filePath_; }
        const std::string& TempFilePath() const { return tempFilePath_; }
			
        bool RangeIsSet() const{ return rangeIsSet_; }
        int64_t RangeStart() const { return range_[0]; }
        int64_t RangeEnd() const { return range_[1]; }
        const std::string& ModifiedSinceConstraint() const { return modifiedSince_; }
        const std::string& UnmodifiedSinceConstraint() const { return unmodifiedSince_; }
        const std::vector<std::string>& MatchingETagsConstraint() const { return matchingETags_; }
        const std::vector<std::string>& NonmatchingETagsConstraint() const { return nonmatchingETags_;}
        const std::map<std::string, std::string>& ResponseHeaderParameters() const { return responseHeaderParameters_; }

        void setRange(int64_t start, int64_t end);
        void setModifiedSinceConstraint(const std::string& gmt);
        void setUnmodifiedSinceConstraint(const std::string& gmt);
        void setMatchingETagConstraints(const std::vector<std::string>& match);
        void setNonmatchingETagConstraints(const std::vector<std::string>& match);
        void addResponseHeaders(RequestResponseHeader header, const std::string& value);

    protected:
        virtual int validate() const;

    private:	
        bool rangeIsSet_;
        int64_t range_[2];
        std::string modifiedSince_;
        std::string unmodifiedSince_;
        std::vector<std::string> matchingETags_;
        std::vector<std::string> nonmatchingETags_;
		
        std::string filePath_;
        std::string tempFilePath_;
        std::shared_ptr<std::iostream> content_;

        std::map<std::string, std::string> responseHeaderParameters_;
    };
}
}