
#pragma once

#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/client/ClientConfiguration.h>
#include <inspurcloud/oss/auth/CredentialsProvider.h>
#include <inspurcloud/oss/OssFwd.h>
#include <inspurcloud/oss/client/AsyncCallerContext.h>
#include <future>
#include <ctime>

namespace InspurCloud
{
namespace OSS
{
    /*Global Init/Deinit*/
    void INSPURCLOUD_OSS_EXPORT InitializeSdk();
    bool INSPURCLOUD_OSS_EXPORT IsSdkInitialized();
    void INSPURCLOUD_OSS_EXPORT ShutdownSdk();

    /*Log*/
    void INSPURCLOUD_OSS_EXPORT SetLogLevel(LogLevel level);
    void INSPURCLOUD_OSS_EXPORT SetLogCallback(LogCallback callback);

    /*Utils*/
    std::string INSPURCLOUD_OSS_EXPORT ComputeContentMD5(const char *data, size_t size);
    std::string INSPURCLOUD_OSS_EXPORT ComputeContentMD5(std::istream& stream);
    std::string INSPURCLOUD_OSS_EXPORT ComputeContentETag(const char* data, size_t size);
    std::string INSPURCLOUD_OSS_EXPORT ComputeContentETag(std::istream& stream);
    std::string INSPURCLOUD_OSS_EXPORT UrlEncode(const std::string& src);
    std::string INSPURCLOUD_OSS_EXPORT UrlDecode(const std::string& src);
    std::string INSPURCLOUD_OSS_EXPORT Base64Encode(const std::string& src);
    std::string INSPURCLOUD_OSS_EXPORT Base64Encode(const char* src, int len);
    std::string INSPURCLOUD_OSS_EXPORT Base64EncodeUrlSafe(const std::string& src);
    std::string INSPURCLOUD_OSS_EXPORT Base64EncodeUrlSafe(const char* src, int len);
    std::string INSPURCLOUD_OSS_EXPORT ToGmtTime(std::time_t& t);
    std::string INSPURCLOUD_OSS_EXPORT ToUtcTime(std::time_t& t);
    std::time_t INSPURCLOUD_OSS_EXPORT UtcToUnixTime(const std::string& t);
    uint64_t    INSPURCLOUD_OSS_EXPORT ComputeCRC64(uint64_t crc, void* buf, size_t len);
    uint64_t    INSPURCLOUD_OSS_EXPORT CombineCRC64(uint64_t crc1, uint64_t crc2, uintmax_t len2);

    /*Aysnc APIs*/
    class OssClient;
    using ListObjectAsyncHandler = std::function<void(const InspurCloud::OSS::OssClient*, const ListObjectsRequest&, const ListObjectOutcome&, const std::shared_ptr<const AsyncCallerContext>&)>;
    using GetObjectAsyncHandler  = std::function<void(const InspurCloud::OSS::OssClient*, const GetObjectRequest&, const GetObjectOutcome&, const std::shared_ptr<const AsyncCallerContext>&)>;
    using PutObjectAsyncHandler = std::function<void(const InspurCloud::OSS::OssClient*, const PutObjectRequest&, const PutObjectOutcome&, const std::shared_ptr<const AsyncCallerContext>&)>;
    using UploadPartAsyncHandler = std::function<void(const InspurCloud::OSS::OssClient*, const UploadPartRequest&, const PutObjectOutcome&, const std::shared_ptr<const AsyncCallerContext>&)>;
    using UploadPartCopyAsyncHandler = std::function<void(const InspurCloud::OSS::OssClient*, const UploadPartCopyRequest&, const UploadPartCopyOutcome&, const std::shared_ptr<const AsyncCallerContext>&)>;

    /*Callable*/
    using ListObjectOutcomeCallable = std::future<ListObjectOutcome>;
    using GetObjectOutcomeCallable  = std::future<GetObjectOutcome>;
    using PutObjectOutcomeCallable  = std::future<PutObjectOutcome>;
    using UploadPartCopyOutcomeCallable = std::future<UploadPartCopyOutcome>;

    class OssClientImpl;
    class INSPURCLOUD_OSS_EXPORT OssClient
    {
    public:

        OssClient(const std::string& endpoint, const std::string& accessKeyId, const std::string& accessKeySecret, 
                                const ClientConfiguration& configuration);
        OssClient(const std::string& endpoint, const std::string& accessKeyId, const std::string& accessKeySecret, const std::string& securityToken,
                                const ClientConfiguration& configuration); 
        OssClient(const std::string& endpoint, const Credentials& credentials, const ClientConfiguration& configuration);
        OssClient(const std::string& endpoint, const std::shared_ptr<CredentialsProvider>& credentialsProvider, const ClientConfiguration& configuration);
        ~OssClient();

        /*Service*/
        ListBucketsOutcome ListBuckets() const;
        ListBucketsOutcome ListBuckets(const ListBucketsRequest& request) const;

        /*Bucket*/ 
		CreateBucketOutcome CreateBucket(const std::string& bucket, StorageClass storageClass = StorageClass::Standard) const;
		CreateBucketOutcome CreateBucket(const std::string& bucket, StorageClass storageClass, CannedAccessControlList acl) const;
		CreateBucketOutcome CreateBucket(const CreateBucketRequest& request) const;

        ListObjectOutcome ListObjects(const std::string& bucket) const;
        ListObjectOutcome ListObjects(const std::string& bucket, const std::string& prefix) const;
        ListObjectOutcome ListObjects(const ListObjectsRequest& request) const;

        /*Object*/
        GetObjectOutcome GetObject(const std::string& bucket, const std::string& key) const;
        GetObjectOutcome GetObject(const std::string& bucket, const std::string& key, const std::shared_ptr<std::iostream>& content) const;
        GetObjectOutcome GetObject(const std::string& bucket, const std::string& key, const std::string& fileToSave) const;
        GetObjectOutcome GetObject(const GetObjectRequest& request) const;
        PutObjectOutcome PutObject(const std::string& bucket, const std::string& key, const std::shared_ptr<std::iostream>& content) const;
        PutObjectOutcome PutObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload) const;
        PutObjectOutcome PutObject(const std::string& bucket, const std::string& key, const std::shared_ptr<std::iostream>& content, const ObjectMetaData& meta) const;
        PutObjectOutcome PutObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload, const ObjectMetaData& meta) const;
        PutObjectOutcome PutObject(const PutObjectRequest& request) const;
        VoidOutcome DeleteObject(const std::string& bucket, const std::string& key) const;
        VoidOutcome DeleteObject(const DeleteObjectRequest& request) const;
        DeleteObjecstOutcome DeleteObjects(const std::string bucket, const DeletedKeyList &keyList) const;
        DeleteObjecstOutcome DeleteObjects(const DeleteObjectsRequest& request) const;
		DeleteObjecstOutcome DeleteObjects( DeleteObjectsRequest& request, const std::string prefix) const;
        ObjectMetaDataOutcome HeadObject(const std::string& bucket, const std::string& key) const;
        ObjectMetaDataOutcome HeadObject(const HeadObjectRequest& request) const;
        AppendObjectOutcome AppendObject(const AppendObjectRequest& request) const;
		AppendObjectOutcome AppendObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload, const uint64_t position, const ObjectMetaData& meta) const;
		AppendObjectOutcome AppendObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload, const uint64_t position ) const;

        VoidOutcome SetBucketEncryption(const SetBucketEncryptionRequest& request) const;
        VoidOutcome DeleteBucketEncryption(const DeleteBucketEncryptionRequest& request) const;
        GetBucketEncryptionOutcome GetBucketEncryption(const GetBucketEncryptionRequest& request) const;

        /*MultipartUpload*/
        InitiateMultipartUploadOutcome InitiateMultipartUpload(const InitiateMultipartUploadRequest& request) const;
        PutObjectOutcome UploadPart(const UploadPartRequest& request) const;
        UploadPartCopyOutcome UploadPartCopy(const UploadPartCopyRequest& request) const;
        CompleteMultipartUploadOutcome CompleteMultipartUpload(const CompleteMultipartUploadRequest& request) const;
        VoidOutcome AbortMultipartUpload(const AbortMultipartUploadRequest& request) const;
        ListMultipartUploadsOutcome ListMultipartUploads(const ListMultipartUploadsRequest& request) const;
        ListPartsOutcome ListParts(const ListPartsRequest& request) const;

        /*Generate URL*/
        StringOutcome GeneratePresignedUrl(const GeneratePresignedUrlRequest& request) const;
        StringOutcome GeneratePresignedUrl(const std::string& bucket, const std::string& key) const;
        StringOutcome GeneratePresignedUrl(const std::string& bucket, const std::string& key, int64_t expires) const;
        StringOutcome GeneratePresignedUrl(const std::string& bucket, const std::string& key, int64_t expires, Http::Method method) const;
        GetObjectOutcome GetObjectByUrl(const GetObjectByUrlRequest& request) const;
        GetObjectOutcome GetObjectByUrl(const std::string& url) const;
        GetObjectOutcome GetObjectByUrl(const std::string& url, const std::string& file) const;
        PutObjectOutcome PutObjectByUrl(const PutObjectByUrlRequest& request) const;
        PutObjectOutcome PutObjectByUrl(const std::string& url, const std::string& file) const;
        PutObjectOutcome PutObjectByUrl(const std::string& url, const std::string& file, const ObjectMetaData& metaData) const;
        PutObjectOutcome PutObjectByUrl(const std::string& url, const std::shared_ptr<std::iostream>& content) const;
        PutObjectOutcome PutObjectByUrl(const std::string& url, const std::shared_ptr<std::iostream>& content, const ObjectMetaData& metaData) const;

        /*Generate Post Policy*/

        /*Resumable Operation*/
        PutObjectOutcome ResumableUploadObject(const UploadObjectRequest& request) const;
        CopyObjectOutcome ResumableCopyObject(const MultiCopyObjectRequest& request) const;
        GetObjectOutcome ResumableDownloadObject(const DownloadObjectRequest& request) const;

        /*Live Channel*/
        VoidOutcome PutLiveChannelStatus(const PutLiveChannelStatusRequest& request) const;
        PutLiveChannelOutcome PutLiveChannel(const PutLiveChannelRequest& request) const;
        VoidOutcome PostVodPlaylist(const PostVodPlaylistRequest& request) const;
        GetVodPlaylistOutcome GetVodPlaylist(const GetVodPlaylistRequest& request) const;
        GetLiveChannelStatOutcome GetLiveChannelStat(const GetLiveChannelStatRequest& request) const;
        GetLiveChannelInfoOutcome GetLiveChannelInfo(const GetLiveChannelInfoRequest& request) const;
        GetLiveChannelHistoryOutcome GetLiveChannelHistory(const GetLiveChannelHistoryRequest& request) const;
        ListLiveChannelOutcome ListLiveChannel(const ListLiveChannelRequest& request) const;
        VoidOutcome DeleteLiveChannel(const DeleteLiveChannelRequest& request) const;
        StringOutcome GenerateRTMPSignedUrl(const GenerateRTMPSignedUrlRequest& request) const;
        
        /*Aysnc APIs*/
        void ListObjectsAsync(const ListObjectsRequest& request, const ListObjectAsyncHandler& handler, const std::shared_ptr<const AsyncCallerContext>& context = nullptr) const;
        void GetObjectAsync(const GetObjectRequest& request, const GetObjectAsyncHandler& handler, const std::shared_ptr<const AsyncCallerContext>& context = nullptr) const;
        void PutObjectAsync(const PutObjectRequest& request, const PutObjectAsyncHandler& handler, const std::shared_ptr<const AsyncCallerContext>& context = nullptr) const;
        void UploadPartAsync(const UploadPartRequest& request, const UploadPartAsyncHandler& handler, const std::shared_ptr<const AsyncCallerContext>& context = nullptr) const;
        void UploadPartCopyAsync(const UploadPartCopyRequest& request, const UploadPartCopyAsyncHandler& handler, const std::shared_ptr<const AsyncCallerContext>& context = nullptr) const;

        /*Callable APIs*/
        ListObjectOutcomeCallable ListObjectsCallable(const ListObjectsRequest& request) const;
        GetObjectOutcomeCallable GetObjectCallable(const GetObjectRequest& request) const;
        PutObjectOutcomeCallable PutObjectCallable(const PutObjectRequest& request) const;
        PutObjectOutcomeCallable UploadPartCallable(const UploadPartRequest& request) const;
        UploadPartCopyOutcomeCallable UploadPartCopyCallable(const UploadPartCopyRequest& request) const;

        /*Extended APIs*/
        bool DoesBucketExist(const std::string& bucket) const;
        bool DoesObjectExist(const std::string& bucket, const std::string& key) const;
        CopyObjectOutcome ModifyObjectMeta(const std::string& bucket, const std::string& key, const ObjectMetaData& meta);

        /*Requests control*/
        void DisableRequest();
        void EnableRequest();
    private:
        std::shared_ptr<OssClientImpl> client_;
    };
}
}
