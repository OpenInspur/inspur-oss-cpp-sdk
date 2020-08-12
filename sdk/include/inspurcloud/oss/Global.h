#pragma once


#if defined(_WIN32)
#   ifdef _MSC_VER
#       pragma warning(disable : 4251)
#   endif // _MSC_VER
#   define InspurCLOUD_DECL_EXPORT __declspec(dllexport)
#   define InspurCLOUD_DECL_IMPORT __declspec(dllimport)
#elif __GNUC__ >= 4
#   define InspurCLOUD_DECL_EXPORT __attribute__((visibility("default")))
#   define InspurCLOUD_DECL_IMPORT __attribute__((visibility("default")))
#endif

#if !defined(InspurCLOUD_DECL_EXPORT)
#   define InspurCLOUD_DECL_EXPORT
#endif

#if !defined(InspurCLOUD_DECL_IMPORT)
#   define InspurCLOUD_DECL_IMPORT
#endif
