#pragma once
#include "Global.h"

#if defined(InspurCLOUD_SHARED)
#   if defined(InspurCLOUD_OSS_LIBRARY)
#       define INSPURCLOUD_OSS_EXPORT InspurCLOUD_DECL_EXPORT
#   else
#       define INSPURCLOUD_OSS_EXPORT InspurCLOUD_DECL_IMPORT
#   endif
#else
#   define INSPURCLOUD_OSS_EXPORT
#endif

