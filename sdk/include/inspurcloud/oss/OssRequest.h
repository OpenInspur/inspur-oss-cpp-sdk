
#pragma once

#include <string>
#include <inspurcloud/oss/ServiceRequest.h>

namespace InspurCloud
{
namespace OSS
{
    class OssClientImpl;
    class  INSPURCLOUD_OSS_EXPORT OssRequest : public ServiceRequest
    {
    public:
        OssRequest();
        virtual ~ OssRequest() = default;
        virtual HeaderCollection Headers() const;
        virtual ParameterCollection Parameters() const;
        virtual std::shared_ptr<std::iostream> Body() const;
    protected:
        OssRequest(const std::string& bucket, const std::string& key);
        friend class OssClientImpl;

        virtual int validate() const;
        const char *validateMessage(int code) const;
        
        virtual std::string payload() const;
        virtual HeaderCollection specialHeaders() const;
        virtual ParameterCollection specialParameters() const;
        
        const std::string& bucket() const;
        const std::string& key()  const;
    protected:
        std::string bucket_;
        std::string key_;
    };

    class INSPURCLOUD_OSS_EXPORT OssBucketRequest : public OssRequest
    {
    public:
        OssBucketRequest(const std::string& bucket):
            OssRequest(bucket, "")
        {}
        void setBucket(const std::string& bucket);
        const std::string& Bucket() const;
    protected:
        virtual int validate() const;
    };

    class INSPURCLOUD_OSS_EXPORT OssObjectRequest : public OssRequest
    {
    public:
        OssObjectRequest(const std::string& bucket, const std::string& key) :
            OssRequest(bucket, key),
            requestPayer_(RequestPayer::NotSet)
        {}
        void setBucket(const std::string& bucket);
        const std::string& Bucket() const;

        void setKey(const std::string& key);
        const std::string& Key() const;

        void setRequestPayer(RequestPayer value);
    protected:
        virtual int validate() const;
        virtual HeaderCollection specialHeaders() const;
        RequestPayer requestPayer_;
    };

    class INSPURCLOUD_OSS_EXPORT OssResumableBaseRequest : public OssRequest
    {
    public:
        OssResumableBaseRequest(const std::string& bucket, const std::string& key,
            const std::string& checkpointDir, const uint64_t partSize, const uint32_t threadNum) :
            OssRequest(bucket, key), 
            partSize_(partSize),
            checkpointDir_(checkpointDir),
            requestPayer_(InspurCloud::OSS::RequestPayer::NotSet),
            trafficLimit_(0)
        {
            threadNum_ = threadNum == 0 ? 1 : threadNum;
        }

        void setBucket(const std::string& bucket);
        const std::string& Bucket() const;

        void setKey(const std::string& key);
        const std::string& Key() const;
        
        void setPartSize(uint64_t partSize);
        uint64_t PartSize() const;

        void setObjectSize(uint64_t objectSize);
        uint64_t ObjectSize() const;
        
        void setThreadNum(uint32_t threadNum);
        uint32_t ThreadNum() const;

        void setCheckpointDir(const std::string& checkpointDir);
        const std::string& CheckpointDir() const;

        void setObjectMtime(const std::string& mtime);
        const std::string& ObjectMtime() const;

        void setRequestPayer(RequestPayer value);
        InspurCloud::OSS::RequestPayer RequestPayer() const;
		
        void setTrafficLimit(uint64_t value);
        uint64_t TrafficLimit() const;

    protected:
        friend class OssClientImpl;
        virtual int validate() const;
        const char *validateMessage(int code) const;

    protected:
        uint64_t partSize_;
        uint64_t objectSize_;
        uint32_t threadNum_;
        std::string checkpointDir_;
        std::string mtime_;
        InspurCloud::OSS::RequestPayer requestPayer_;
        uint64_t trafficLimit_;
    };

    class INSPURCLOUD_OSS_EXPORT LiveChannelRequest : public OssRequest
    {
    public:
        LiveChannelRequest(const std::string &bucket, const std::string &channelName) :
            OssRequest(bucket, channelName),
            channelName_(channelName)
        {}
        void setBucket(const std::string &bucket);
        const std::string& Bucket() const;

        void setChannelName(const std::string &channelName);
        const std::string& ChannelName() const;
    protected:
        virtual int validate() const;
    protected:
        std::string channelName_;
    };
}
}
