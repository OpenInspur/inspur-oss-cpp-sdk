#pragma once

#include <memory>
#include <iostream>
#include <inspurcloud/oss/Global.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/OssError.h>
#include <inspurcloud/oss/ServiceResult.h>
#include <inspurcloud/oss/utils/Outcome.h>
#include <inspurcloud/oss/model/VoidResult.h>
#include <inspurcloud/oss/model/ListBucketsRequest.h>
#include <inspurcloud/oss/model/ListBucketsResult.h>
#include <inspurcloud/oss/model/CreateBucketRequest.h>
#include <inspurcloud/oss/model/SetBucketAclRequest.h>
#include <inspurcloud/oss/model/SetBucketLoggingRequest.h>
#include <inspurcloud/oss/model/SetBucketWebsiteRequest.h>
#include <inspurcloud/oss/model/SetBucketRefererRequest.h>
#include <inspurcloud/oss/model/SetBucketLifecycleRequest.h>
#include <inspurcloud/oss/model/SetBucketCorsRequest.h>
#include <inspurcloud/oss/model/SetBucketStorageCapacityRequest.h>
#include <inspurcloud/oss/model/DeleteBucketRequest.h>
#include <inspurcloud/oss/model/DeleteBucketLoggingRequest.h>
#include <inspurcloud/oss/model/DeleteBucketWebsiteRequest.h>
#include <inspurcloud/oss/model/DeleteBucketLifecycleRequest.h>
#include <inspurcloud/oss/model/DeleteBucketCorsRequest.h>
#include <inspurcloud/oss/model/ListObjectsRequest.h>
#include <inspurcloud/oss/model/ListObjectsResult.h>
#include <inspurcloud/oss/model/GetBucketAclRequest.h>
#include <inspurcloud/oss/model/GetBucketAclResult.h>
#include <inspurcloud/oss/model/GetBucketLocationRequest.h>
#include <inspurcloud/oss/model/GetBucketLocationResult.h>
#include <inspurcloud/oss/model/GetBucketInfoRequest.h>
#include <inspurcloud/oss/model/GetBucketInfoResult.h>
#include <inspurcloud/oss/model/GetBucketLoggingRequest.h>
#include <inspurcloud/oss/model/GetBucketLoggingResult.h>
#include <inspurcloud/oss/model/GetBucketWebsiteRequest.h>
#include <inspurcloud/oss/model/GetBucketWebsiteResult.h>
#include <inspurcloud/oss/model/GetBucketRefererRequest.h>
#include <inspurcloud/oss/model/GetBucketRefererResult.h>
#include <inspurcloud/oss/model/GetBucketLifecycleRequest.h>
#include <inspurcloud/oss/model/GetBucketLifecycleResult.h>
#include <inspurcloud/oss/model/GetBucketStatRequest.h>
#include <inspurcloud/oss/model/GetBucketStatResult.h>
#include <inspurcloud/oss/model/GetBucketCorsRequest.h>
#include <inspurcloud/oss/model/GetBucketCorsResult.h>
#include <inspurcloud/oss/model/GetBucketStorageCapacityRequest.h>
#include <inspurcloud/oss/model/GetBucketStorageCapacityResult.h>
#include <inspurcloud/oss/model/GetObjectRequest.h>
#include <inspurcloud/oss/model/GetObjectResult.h>
#include <inspurcloud/oss/model/PutObjectRequest.h>
#include <inspurcloud/oss/model/PutObjectResult.h>
#include <inspurcloud/oss/model/DeleteObjectRequest.h>
#include <inspurcloud/oss/model/DeleteObjectsRequest.h>
#include <inspurcloud/oss/model/DeleteObjectsResult.h>
#include <inspurcloud/oss/model/HeadObjectRequest.h>
#include <inspurcloud/oss/model/GetObjectMetaRequest.h>
#include <inspurcloud/oss/model/GeneratePresignedUrlRequest.h>
#include <inspurcloud/oss/model/GetObjectByUrlRequest.h>
#include <inspurcloud/oss/model/PutObjectByUrlRequest.h>
#include <inspurcloud/oss/model/GetObjectAclRequest.h>
#include <inspurcloud/oss/model/GetObjectAclResult.h>
#include <inspurcloud/oss/model/AppendObjectRequest.h>
#include <inspurcloud/oss/model/AppendObjectResult.h>
#include <inspurcloud/oss/model/CopyObjectRequest.h>
#include <inspurcloud/oss/model/CopyObjectResult.h>
#include <inspurcloud/oss/model/GetSymlinkRequest.h>
#include <inspurcloud/oss/model/GetSymlinkResult.h>
#include <inspurcloud/oss/model/RestoreObjectRequest.h>
#include <inspurcloud/oss/model/CreateSymlinkRequest.h>
#include <inspurcloud/oss/model/CreateSymlinkResult.h>
#include <inspurcloud/oss/model/SetObjectAclRequest.h>
#include <inspurcloud/oss/model/ProcessObjectRequest.h>
#include <inspurcloud/oss/model/InitiateMultipartUploadRequest.h>
#include <inspurcloud/oss/model/InitiateMultipartUploadResult.h>
#include <inspurcloud/oss/model/UploadPartRequest.h>
#include <inspurcloud/oss/model/UploadPartCopyRequest.h>
#include <inspurcloud/oss/model/UploadPartCopyResult.h>
#include <inspurcloud/oss/model/CompleteMultipartUploadRequest.h>
#include <inspurcloud/oss/model/CompleteMultipartUploadResult.h>
#include <inspurcloud/oss/model/AbortMultipartUploadRequest.h>
#include <inspurcloud/oss/model/ListMultipartUploadsRequest.h>
#include <inspurcloud/oss/model/ListMultipartUploadsResult.h>
#include <inspurcloud/oss/model/ListPartsRequest.h>
#include <inspurcloud/oss/model/ListPartsResult.h>
#include <inspurcloud/oss/model/UploadObjectRequest.h>
#include <inspurcloud/oss/model/MultiCopyObjectRequest.h>
#include <inspurcloud/oss/model/DownloadObjectRequest.h>
#include <inspurcloud/oss/model/PutLiveChannelStatusRequest.h>
#include <inspurcloud/oss/model/PutLiveChannelRequest.h>
#include <inspurcloud/oss/model/PutLiveChannelResult.h>
#include <inspurcloud/oss/model/PostVodPlaylistRequest.h>
#include <inspurcloud/oss/model/GetVodPlaylistRequest.h>
#include <inspurcloud/oss/model/GetVodPlaylistResult.h>
#include <inspurcloud/oss/model/GetLiveChannelStatRequest.h>
#include <inspurcloud/oss/model/GetLiveChannelStatResult.h>
#include <inspurcloud/oss/model/GetLiveChannelInfoRequest.h>
#include <inspurcloud/oss/model/GetLiveChannelInfoResult.h>
#include <inspurcloud/oss/model/GetLiveChannelHistoryRequest.h>
#include <inspurcloud/oss/model/GetLiveChannelHistoryResult.h>
#include <inspurcloud/oss/model/ListLiveChannelRequest.h>
#include <inspurcloud/oss/model/ListLiveChannelResult.h>
#include <inspurcloud/oss/model/DeleteLiveChannelRequest.h>
#include <inspurcloud/oss/model/GenerateRTMPSignedUrlRequest.h>
#include <inspurcloud/oss/model/ObjectCallbackBuilder.h>
#include <inspurcloud/oss/model/SelectObjectRequest.h>
#include <inspurcloud/oss/model/CreateSelectObjectMetaRequest.h>
#include <inspurcloud/oss/model/CreateSelectObjectMetaResult.h>
#include <inspurcloud/oss/model/SetObjectTaggingRequest.h>
#include <inspurcloud/oss/model/SetObjectTaggingResult.h>
#include <inspurcloud/oss/model/GetObjectTaggingRequest.h>
#include <inspurcloud/oss/model/GetObjectTaggingResult.h>
#include <inspurcloud/oss/model/DeleteObjectTaggingRequest.h>
#include <inspurcloud/oss/model/DeleteObjectTaggingResult.h>
#include <inspurcloud/oss/model/SetBucketPolicyRequest.h>
#include <inspurcloud/oss/model/GetBucketPolicyRequest.h>
#include <inspurcloud/oss/model/GetBucketPolicyResult.h>
#include <inspurcloud/oss/model/DeleteBucketPolicyRequest.h>
#include <inspurcloud/oss/model/SetBucketPaymentRequest.h>
#include <inspurcloud/oss/model/GetBucketPaymentRequest.h>
#include <inspurcloud/oss/model/GetBucketPaymentResult.h>
#include <inspurcloud/oss/model/SetBucketEncryptionRequest.h>
#include <inspurcloud/oss/model/DeleteBucketEncryptionRequest.h>
#include <inspurcloud/oss/model/GetBucketEncryptionRequest.h>
#include <inspurcloud/oss/model/GetBucketEncryptionResult.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    using OssOutcome = Outcome<OssError, ServiceResult>;
    using VoidOutcome = Outcome<OssError, VoidResult>;
    using StringOutcome = Outcome<OssError, std::string>;

    using ListBucketsOutcome = Outcome<OssError, ListBucketsResult>;
    using CreateBucketOutcome = Outcome<OssError, Bucket>;
    using ListObjectOutcome = Outcome<OssError, ListObjectsResult>;

    using GetBucketAclOutcome = Outcome<OssError, GetBucketAclResult>;
    using GetBucketLocationOutcome = Outcome<OssError, GetBucketLocationResult>;
    using GetBucketInfoOutcome = Outcome<OssError, GetBucketInfoResult>;
    using GetBucketLoggingOutcome = Outcome<OssError, GetBucketLoggingResult>;
    using GetBucketWebsiteOutcome = Outcome<OssError, GetBucketWebsiteResult>;
    using GetBucketRefererOutcome = Outcome<OssError, GetBucketRefererResult>;
    using GetBucketLifecycleOutcome = Outcome<OssError, GetBucketLifecycleResult>;
    using GetBucketStatOutcome = Outcome<OssError, GetBucketStatResult>;
    using GetBucketCorsOutcome = Outcome<OssError, GetBucketCorsResult>;
    using GetBucketStorageCapacityOutcome = Outcome<OssError, GetBucketStorageCapacityResult>;
    using GetBucketPolicyOutcome = Outcome<OssError, GetBucketPolicyResult>;
    using GetBucketPaymentOutcome = Outcome<OssError, GetBucketPaymentResult>;
    using GetBucketEncryptionOutcome = Outcome<OssError, GetBucketEncryptionResult>;

    using GetObjectOutcome = Outcome<OssError, GetObjectResult>;
    using PutObjectOutcome = Outcome<OssError, PutObjectResult>;
    using DeleteObjecstOutcome = Outcome<OssError, DeleteObjectsResult>;
    using ObjectMetaDataOutcome = Outcome<OssError, ObjectMetaData>;

    using GetObjectAclOutcome = Outcome<OssError, GetObjectAclResult>;
    using AppendObjectOutcome = Outcome<OssError, AppendObjectResult>;
    using CopyObjectOutcome = Outcome<OssError, CopyObjectResult>;
    using GetSymlinkOutcome = Outcome<OssError, GetSymlinkResult>;
    using CreateSymlinkOutcome = Outcome<OssError, CreateSymlinkResult>;
    using CreateSelectObjectMetaOutcome = Outcome<OssError, CreateSelectObjectMetaResult>;
    using SetObjectTaggingOutcome = Outcome<OssError, SetObjectTaggingResult>;
    using GetObjectTaggingOutcome = Outcome<OssError, GetObjectTaggingResult>;
    using DeleteObjectTaggingOutcome = Outcome<OssError, DeleteObjectTaggingResult>;

    /*multipart*/
    using InitiateMultipartUploadOutcome = Outcome<OssError, InitiateMultipartUploadResult>;
    using UploadPartCopyOutcome = Outcome<OssError, UploadPartCopyResult>;
    using CompleteMultipartUploadOutcome = Outcome<OssError, CompleteMultipartUploadResult>;
    using ListMultipartUploadsOutcome = Outcome<OssError, ListMultipartUploadsResult>;
    using ListPartsOutcome = Outcome<OssError, ListPartsResult>;

    /*livechannel*/
    using PutLiveChannelOutcome = Outcome<OssError, PutLiveChannelResult>;
    using GetLiveChannelStatOutcome = Outcome<OssError, GetLiveChannelStatResult>;
    using GetLiveChannelInfoOutcome = Outcome<OssError, GetLiveChannelInfoResult>;
    using GetLiveChannelHistoryOutcome = Outcome<OssError, GetLiveChannelHistoryResult>;
    using ListLiveChannelOutcome = Outcome<OssError, ListLiveChannelResult>;
    using GetVodPlaylistOutcome = Outcome<OssError, GetVodPlaylistResult>;
}
}
