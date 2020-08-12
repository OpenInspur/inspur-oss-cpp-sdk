
#include <inspurcloud/oss/OssClient.h>
#include "auth/SimpleCredentialsProvider.h"
#include "http/CurlHttpClient.h"
#include "OssClientImpl.h"
#include <fstream>
#include "utils/LogUtils.h"
#include "utils/Crc64.h"

using namespace InspurCloud::OSS;

static bool SdkInitDone = false;

bool InspurCloud::OSS::IsSdkInitialized()
{
    return SdkInitDone;
}

void InspurCloud::OSS::InitializeSdk()
{
    if (IsSdkInitialized())
        return;
    InitLogInner();
    CurlHttpClient::initGlobalState();
    SdkInitDone = true;
}

void InspurCloud::OSS::ShutdownSdk()
{
    if (!IsSdkInitialized())
        return;
    
    CurlHttpClient::cleanupGlobalState();
    DeinitLogInner();
    SdkInitDone = false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void InspurCloud::OSS::SetLogLevel(LogLevel level)
{
    SetLogLevelInner(level);
}

void InspurCloud::OSS::SetLogCallback(LogCallback callback)
{
    SetLogCallbackInner(callback);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

uint64_t InspurCloud::OSS::ComputeCRC64(uint64_t crc, void *buf, size_t len)
{
    return CRC64::CalcCRC(crc, buf, len);
}

uint64_t InspurCloud::OSS::CombineCRC64(uint64_t crc1, uint64_t crc2, uintmax_t len2)
{
    return CRC64::CombineCRC(crc1, crc2, len2);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

OssClient::OssClient(const std::string &endpoint, const std::string & accessKeyId, const std::string & accessKeySecret, const ClientConfiguration & configuration) :
    OssClient(endpoint, accessKeyId, accessKeySecret, "", configuration)
{
}

OssClient::OssClient(const std::string &endpoint, const std::string & accessKeyId, const std::string & accessKeySecret, const std::string & securityToken,
    const ClientConfiguration & configuration) :
    OssClient(endpoint, std::make_shared<SimpleCredentialsProvider>(accessKeyId, accessKeySecret, securityToken), configuration)
{
}

OssClient::OssClient(const std::string &endpoint, const Credentials &credentials, const ClientConfiguration &configuration) :
    OssClient(endpoint, std::make_shared<SimpleCredentialsProvider>(credentials), configuration)
{
}

OssClient::OssClient(const std::string &endpoint, const std::shared_ptr<CredentialsProvider>& credentialsProvider, const ClientConfiguration & configuration) :
    client_(std::make_shared<OssClientImpl>(endpoint, credentialsProvider, configuration))
{
}

OssClient::~OssClient()
{
}

ListBucketsOutcome OssClient::ListBuckets() const
{
    return client_->ListBuckets(ListBucketsRequest());
}

ListBucketsOutcome OssClient::ListBuckets(const ListBucketsRequest &request) const
{
    return client_->ListBuckets(request);
}

CreateBucketOutcome OssClient::CreateBucket(const std::string& bucket, StorageClass storageClass) const
{
	return client_->CreateBucket(CreateBucketRequest(bucket, storageClass));
}

CreateBucketOutcome OssClient::CreateBucket(const std::string& bucket, StorageClass storageClass, CannedAccessControlList acl) const
{
	return client_->CreateBucket(CreateBucketRequest(bucket, storageClass, acl));
}

CreateBucketOutcome OssClient::CreateBucket(const CreateBucketRequest& request) const
{
	return client_->CreateBucket(request);
}

ListObjectOutcome OssClient::ListObjects(const std::string &bucket) const
{
    return client_->ListObjects(ListObjectsRequest(bucket));
}

ListObjectOutcome OssClient::ListObjects(const std::string &bucket, const std::string &prefix) const
{
    ListObjectsRequest request(bucket);
    request.setPrefix(prefix);
    return client_->ListObjects(request);
}

ListObjectOutcome OssClient::ListObjects(const ListObjectsRequest &request) const
{
    return client_->ListObjects(request);
}



GetObjectOutcome OssClient::GetObject(const std::string &bucket, const std::string &key) const
{
    return client_->GetObject(GetObjectRequest(bucket, key));
}

GetObjectOutcome OssClient::GetObject(const std::string &bucket, const std::string &key, const std::shared_ptr<std::iostream> &content) const
{
    GetObjectRequest request(bucket, key);
    request.setResponseStreamFactory([=]() { return content; });
    return client_->GetObject(request);
}

GetObjectOutcome OssClient::GetObject(const std::string &bucket, const std::string &key, const std::string &fileToSave) const
{
    GetObjectRequest request(bucket, key);
    request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(fileToSave, std::ios_base::out | std::ios_base::trunc | std::ios::binary); });
    return client_->GetObject(request);
}

GetObjectOutcome OssClient::GetObject(const GetObjectRequest &request) const
{
    return client_->GetObject(request);
}

PutObjectOutcome OssClient::PutObject(const std::string &bucket, const std::string &key, const std::shared_ptr<std::iostream> &content) const
{
    return client_->PutObject(PutObjectRequest(bucket, key, content));
}

PutObjectOutcome OssClient::PutObject(const std::string &bucket, const std::string &key, const std::string &fileToUpload) const
{
    std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(fileToUpload, std::ios::in|std::ios::binary);
    return client_->PutObject(PutObjectRequest(bucket, key, content));
}

PutObjectOutcome OssClient::PutObject(const std::string &bucket, const std::string &key, const std::shared_ptr<std::iostream> &content, const ObjectMetaData &meta) const
{
    return client_->PutObject(PutObjectRequest(bucket, key, content, meta));
}

PutObjectOutcome OssClient::PutObject(const std::string &bucket, const std::string &key, const std::string &fileToUpload, const ObjectMetaData &meta) const
{
    std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(fileToUpload, std::ios::in | std::ios::binary);
    return client_->PutObject(PutObjectRequest(bucket, key, content, meta));
}

PutObjectOutcome OssClient::PutObject(const PutObjectRequest &request) const
{
    return client_->PutObject(request);
}

VoidOutcome OssClient::DeleteObject(const std::string &bucket, const std::string &key) const
{
    return client_->DeleteObject(DeleteObjectRequest(bucket, key));
}

VoidOutcome OssClient::DeleteObject(const DeleteObjectRequest &request) const
{
    return client_->DeleteObject(request);
}

DeleteObjecstOutcome OssClient::DeleteObjects(const std::string bucket, const DeletedKeyList &keyList) const
{
    DeleteObjectsRequest request(bucket);
    request.setKeyList(keyList);
    return client_->DeleteObjects(request);
}

DeleteObjecstOutcome OssClient::DeleteObjects(const DeleteObjectsRequest &request) const
{
    return client_->DeleteObjects(request);
}
//add by zhangsm start
DeleteObjecstOutcome OssClient::DeleteObjects(DeleteObjectsRequest& request, const std::string prefix) const
{
	ListObjectsRequest List_request(request.Bucket());
	List_request.setPrefix(prefix);
	auto outcome = ListObjects(List_request);
	for (const auto& object : outcome.result().ObjectSummarys()) {
		request.addKey(object.Key());
	}
	return client_->DeleteObjects(request);
}
//add by zhangsm end;

ObjectMetaDataOutcome OssClient::HeadObject(const std::string &bucket, const std::string &key) const
{
    return client_->HeadObject(HeadObjectRequest(bucket, key));
}

ObjectMetaDataOutcome OssClient::HeadObject(const HeadObjectRequest &request) const
{
    return client_->HeadObject(request);
}



AppendObjectOutcome OssClient::AppendObject(const AppendObjectRequest &request) const
{
    return client_->AppendObject(request);
}
AppendObjectOutcome OssClient::AppendObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload, const uint64_t position, const ObjectMetaData& meta) const
{
	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(fileToUpload, std::ios::in | std::ios::binary);
	AppendObjectRequest request(bucket, key, content, meta);
	request.setPosition(position);
	return client_->AppendObject(request);
}
AppendObjectOutcome OssClient::AppendObject(const std::string& bucket, const std::string& key, const std::string& fileToUpload, const uint64_t position ) const
{
	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(fileToUpload, std::ios::in | std::ios::binary);
	AppendObjectRequest request(bucket, key, content );
	request.setPosition(position);
	return client_->AppendObject(request);
}

StringOutcome OssClient::GeneratePresignedUrl(const GeneratePresignedUrlRequest &request) const
{
    return client_->GeneratePresignedUrl(request);
}

StringOutcome OssClient::GeneratePresignedUrl(const std::string &bucket, const std::string &key) const
{
    return GeneratePresignedUrl(GeneratePresignedUrlRequest(bucket, key));
}

StringOutcome OssClient::GeneratePresignedUrl(const std::string &bucket, const std::string &key, int64_t expires) const
{
    GeneratePresignedUrlRequest request(bucket, key);
    request.setExpires(expires);
    return GeneratePresignedUrl(request);
}

StringOutcome OssClient::GeneratePresignedUrl(const std::string &bucket, const std::string &key, int64_t expires, Http::Method method) const
{
    GeneratePresignedUrlRequest request(bucket, key, method);
    request.setExpires(expires);
    return GeneratePresignedUrl(request);
}

GetObjectOutcome OssClient::GetObjectByUrl(const GetObjectByUrlRequest &request) const
{
    return client_->GetObjectByUrl(request);
}

GetObjectOutcome OssClient::GetObjectByUrl(const std::string &url) const
{
    return client_->GetObjectByUrl(GetObjectByUrlRequest(url));
}

GetObjectOutcome OssClient::GetObjectByUrl(const std::string &url, const std::string &file) const
{
    GetObjectByUrlRequest request(url);
    request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(file, std::ios_base::out | std::ios_base::in | std::ios_base::trunc); });
    return client_->GetObjectByUrl(request);
}

PutObjectOutcome OssClient::PutObjectByUrl(const PutObjectByUrlRequest &request) const
{
    return client_->PutObjectByUrl(request);
}

PutObjectOutcome OssClient::PutObjectByUrl(const std::string &url, const std::string &file) const
{
    std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(file, std::ios::in|std::ios::binary);
    return client_->PutObjectByUrl(PutObjectByUrlRequest(url, content));
}

PutObjectOutcome OssClient::PutObjectByUrl(const std::string &url, const std::string &file, const ObjectMetaData &metaData) const
{
    std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(file, std::ios::in | std::ios::binary);
    return client_->PutObjectByUrl(PutObjectByUrlRequest(url, content, metaData));
}

PutObjectOutcome OssClient::PutObjectByUrl(const std::string &url, const std::shared_ptr<std::iostream> &content) const
{
    return client_->PutObjectByUrl(PutObjectByUrlRequest(url, content));
}

PutObjectOutcome OssClient::PutObjectByUrl(const std::string &url, const std::shared_ptr<std::iostream> &content, const ObjectMetaData &metaData) const
{
    return client_->PutObjectByUrl(PutObjectByUrlRequest(url, content, metaData));
}

InitiateMultipartUploadOutcome OssClient::InitiateMultipartUpload(const InitiateMultipartUploadRequest &request)const
{
    return client_->InitiateMultipartUpload(request);
}

PutObjectOutcome OssClient::UploadPart(const UploadPartRequest &request) const
{
    return client_->UploadPart(request);
}

UploadPartCopyOutcome OssClient::UploadPartCopy(const UploadPartCopyRequest &request) const
{
    return client_->UploadPartCopy(request);
}

CompleteMultipartUploadOutcome OssClient::CompleteMultipartUpload(const CompleteMultipartUploadRequest &request) const
{
    return client_->CompleteMultipartUpload(request);
}

VoidOutcome OssClient::AbortMultipartUpload(const AbortMultipartUploadRequest &request) const
{
    return client_->AbortMultipartUpload(request);
}

ListMultipartUploadsOutcome OssClient::ListMultipartUploads(const ListMultipartUploadsRequest &request) const
{
    return client_->ListMultipartUploads(request);
}

ListPartsOutcome OssClient::ListParts(const ListPartsRequest &request) const
{
    return client_->ListParts(request);
}

/*Aysnc APIs*/
void OssClient::ListObjectsAsync(const ListObjectsRequest &request, const ListObjectAsyncHandler &handler, const std::shared_ptr<const AsyncCallerContext>& context) const
{
    auto fn = [this, request, handler, context]()
    {
        handler(this, request, client_->ListObjects(request), context);
    };

    client_->asyncExecute(new Runnable(fn));
}

void OssClient::GetObjectAsync(const GetObjectRequest &request, const GetObjectAsyncHandler &handler, const std::shared_ptr<const AsyncCallerContext>& context) const
{
    auto fn = [this, request, handler, context]()
    {
        handler(this, request, client_->GetObject(request), context);
    };

    client_->asyncExecute(new Runnable(fn));
}

void OssClient::PutObjectAsync(const PutObjectRequest &request, const PutObjectAsyncHandler &handler, const std::shared_ptr<const AsyncCallerContext>& context) const
{
    auto fn = [this, request, handler, context]()
    {
        handler(this, request, client_->PutObject(request), context);
    };

    client_->asyncExecute(new Runnable(fn));
}

void OssClient::UploadPartAsync(const UploadPartRequest &request, const UploadPartAsyncHandler &handler, const std::shared_ptr<const AsyncCallerContext>& context) const
{
    auto fn = [this, request, handler, context]()
    {
        handler(this, request, client_->UploadPart(request), context);
    };

    client_->asyncExecute(new Runnable(fn));
}

void OssClient::UploadPartCopyAsync(const UploadPartCopyRequest &request, const UploadPartCopyAsyncHandler &handler, const std::shared_ptr<const AsyncCallerContext>& context) const
{
    auto fn = [this, request, handler, context]()
    {
        handler(this, request, client_->UploadPartCopy(request), context);
    };

    client_->asyncExecute(new Runnable(fn));
}


/*Callable APIs*/
ListObjectOutcomeCallable OssClient::ListObjectsCallable(const ListObjectsRequest &request) const
{
    auto task = std::make_shared<std::packaged_task<ListObjectOutcome()>>(
        [this, request]()
    {
        return this->ListObjects(request);
    });
    client_->asyncExecute(new Runnable([task]() { (*task)(); }));
    return task->get_future();
}

GetObjectOutcomeCallable OssClient::GetObjectCallable(const GetObjectRequest &request) const
{
    auto task = std::make_shared<std::packaged_task<GetObjectOutcome()>>(
        [this, request]()
    {
        return this->GetObject(request);
    });
    client_->asyncExecute(new Runnable([task]() { (*task)(); }));
    return task->get_future();

}

PutObjectOutcomeCallable OssClient::PutObjectCallable(const PutObjectRequest &request) const
{
    auto task = std::make_shared<std::packaged_task<PutObjectOutcome()>>(
        [this, request]()
    {
        return this->PutObject(request);
    });
    client_->asyncExecute(new Runnable([task]() { (*task)(); }));
    return task->get_future();
}

PutObjectOutcomeCallable OssClient::UploadPartCallable(const UploadPartRequest &request) const
{
    auto task = std::make_shared<std::packaged_task<PutObjectOutcome()>>(
        [this, request]()
    {
        return this->UploadPart(request);
    });
    client_->asyncExecute(new Runnable([task]() { (*task)(); }));
    return task->get_future();
}

UploadPartCopyOutcomeCallable OssClient::UploadPartCopyCallable(const UploadPartCopyRequest &request) const
{
    auto task = std::make_shared<std::packaged_task<UploadPartCopyOutcome()>>(
        [this, request]()
    {
        return this->UploadPartCopy(request);
    });
    client_->asyncExecute(new Runnable([task]() { (*task)(); }));
    return task->get_future();
}

/*Extended APIs*/
bool OssClient::DoesBucketExist(const std::string &bucket) const
{
    return client_->GetBucketAcl(GetBucketAclRequest(bucket)).isSuccess();
}

bool OssClient::DoesObjectExist(const std::string &bucket, const std::string &key) const
{
    return client_->GetObjectMeta(GetObjectMetaRequest(bucket, key)).isSuccess();
}

CopyObjectOutcome OssClient::ModifyObjectMeta(const std::string& bucket, const std::string& key, const ObjectMetaData& meta)
{
    CopyObjectRequest copyRequest(bucket, key, meta);
    copyRequest.setCopySource(bucket, key);
    copyRequest.setMetadataDirective(CopyActionList::Replace);
    return client_->CopyObject(copyRequest);
}

VoidOutcome OssClient::PutLiveChannelStatus(const PutLiveChannelStatusRequest &request) const
{
    return client_->PutLiveChannelStatus(request);
}

PutLiveChannelOutcome OssClient::PutLiveChannel(const PutLiveChannelRequest &request) const
{
    return client_->PutLiveChannel(request);
}

VoidOutcome OssClient::PostVodPlaylist(const PostVodPlaylistRequest &request) const
{
    return client_->PostVodPlaylist(request);
}

GetVodPlaylistOutcome OssClient::GetVodPlaylist(const GetVodPlaylistRequest &request) const
{
    return client_->GetVodPlaylist(request);
}

GetLiveChannelStatOutcome OssClient::GetLiveChannelStat(const GetLiveChannelStatRequest &request) const
{
    return client_->GetLiveChannelStat(request);
}

GetLiveChannelInfoOutcome OssClient::GetLiveChannelInfo(const GetLiveChannelInfoRequest &request) const
{
    return client_->GetLiveChannelInfo(request);
}

GetLiveChannelHistoryOutcome OssClient::GetLiveChannelHistory(const GetLiveChannelHistoryRequest &request) const
{
    return client_->GetLiveChannelHistory(request);
}

ListLiveChannelOutcome OssClient::ListLiveChannel(const ListLiveChannelRequest &request) const
{
    return client_->ListLiveChannel(request);
}

VoidOutcome OssClient::DeleteLiveChannel(const DeleteLiveChannelRequest &request) const
{
    return client_->DeleteLiveChannel(request);
}

StringOutcome OssClient::GenerateRTMPSignedUrl(const GenerateRTMPSignedUrlRequest &request) const
{
    return client_->GenerateRTMPSignedUrl(request);
}

void OssClient::DisableRequest()
{
    client_->DisableRequest();
}

void OssClient::EnableRequest()
{
    client_->EnableRequest();
}

PutObjectOutcome OssClient::ResumableUploadObject(const UploadObjectRequest &request) const
{
    return client_->ResumableUploadObject(request);
}

CopyObjectOutcome OssClient::ResumableCopyObject(const MultiCopyObjectRequest &request) const 
{
    return client_->ResumableCopyObject(request);
}

GetObjectOutcome OssClient::ResumableDownloadObject(const DownloadObjectRequest &request) const 
{
    return client_->ResumableDownloadObject(request);
}

VoidOutcome OssClient::SetBucketEncryption(const SetBucketEncryptionRequest& request) const
{
    return client_->SetBucketEncryption(request);
}

VoidOutcome OssClient::DeleteBucketEncryption(const DeleteBucketEncryptionRequest& request) const
{
    return client_->DeleteBucketEncryption(request);
}

GetBucketEncryptionOutcome OssClient::GetBucketEncryption(const GetBucketEncryptionRequest& request) const
{
    return client_->GetBucketEncryption(request);
}
