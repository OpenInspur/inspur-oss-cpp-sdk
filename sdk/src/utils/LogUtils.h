
#pragma once
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    void InitLogInner();
    void DeinitLogInner();

    LogLevel    GetLogLevelInner();
    LogCallback GetLogCallbackInner();
    void SetLogLevelInner(LogLevel level);
    void SetLogCallbackInner(LogCallback callback);

    void FormattedLog(LogLevel logLevel, const char* tag, const char* formatStr, ...);

#ifdef DISABLE_OSS_LOGGING

    #define OSS_LOG(level, tag, ...) 

#else

    #define OSS_LOG(level, tag, ...) \
    { \
        if ( InspurCloud::OSS::GetLogCallbackInner() && InspurCloud::OSS::GetLogLevelInner() >= level ) \
        { \
            FormattedLog(level, tag, __VA_ARGS__); \
        } \
    }

#endif // DISABLE_OSS_LOGGING
}
}

