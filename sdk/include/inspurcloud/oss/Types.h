#pragma once

#include <cstdint> 
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <functional>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{
    enum StorageClass
    {
        Standard, // Standard bucket
        IA,       // Infrequent Access bucket
        Archive   // Archive bucket
    };

    enum CannedAccessControlList
    {
        Private = 0,
        PublicRead,
        PublicReadWrite,
        Default
    };

    enum CopyActionList
    {
        Copy = 0,
        Replace
    };

    enum EncodingType {
        STRING_ANY,
        URL,
    };

    enum RequestResponseHeader {
        ContentType,
        ContentLanguage,
        Expires,
        CacheControl,
        ContentDisposition,
        ContentEncoding,
    };

    enum RuleStatus
    {
        Enabled,
        Disabled
    };

    enum LogLevel
    {
        LogOff = 0,
        LogFatal,
        LogError,
        LogWarn,
        LogInfo,
        LogDebug,
        LogTrace,
        LogAll,
    };

    enum LiveChannelStatus
    {
        EnabledStatus,
        DisabledStatus,
        IdleStatus,
        LiveStatus,
        UnknownStatus=99
    };


    enum class RequestPayer
    {
        NotSet = 0,
        BucketOwner,
        Requester
    };

    enum class SSEAlgorithm
    {
        NotSet = 0,
        KMS,
        AES256,
        CustomerAES256
    };

    typedef void(*LogCallback)(LogLevel level, const std::string& stream);

    struct  INSPURCLOUD_OSS_EXPORT caseSensitiveLess
    {
        bool operator() (const std::string& lhs, const std::string& rhs) const
        {
            return lhs < rhs;
        }
    };

    struct  INSPURCLOUD_OSS_EXPORT caseInsensitiveLess
    {
        bool operator() (const std::string& lhs, const std::string& rhs) const
        {
            auto first1 = lhs.begin(), last1 = lhs.end();
            auto first2 = rhs.begin(), last2 = rhs.end();
            while (first1 != last1) {
                if (first2 == last2)
                    return false;
                auto first1_ch = ::tolower(*first1);
                auto first2_ch = ::tolower(*first2);
                if (first1_ch != first2_ch) {
                    return (first1_ch < first2_ch);
                }
                ++first1; ++first2;
            }
            return (first2 != last2);
        }
    };

    using TransferProgressHandler = std::function<void(size_t increment, int64_t transferred, int64_t total, void *userData)>;
    struct  INSPURCLOUD_OSS_EXPORT TransferProgress
    {
        TransferProgressHandler Handler;
        void *UserData;
    };

    using RefererList = std::vector<std::string>;
    using MetaData = std::map<std::string, std::string, caseInsensitiveLess>;
    using HeaderCollection = std::map<std::string, std::string, caseInsensitiveLess>;
    using ParameterCollection = std::map<std::string, std::string, caseSensitiveLess>;
    using IOStreamFactory = std::function< std::shared_ptr<std::iostream>(void)>;

}
}
