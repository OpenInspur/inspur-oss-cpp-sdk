#pragma once

#include <string>
#include <map>
#include <inspurcloud/oss/Export.h>

namespace InspurCloud
{
namespace OSS
{

    class  INSPURCLOUD_OSS_EXPORT Http
    {
        public:
            enum Method
            {
                Get,
                Head,
                Post,
                Put,
                Delete,
                Connect,
                Options,
                Patch,
                Trace
            };
            enum Scheme
            {
                HTTP,
                HTTPS
            };
            static std::string MethodToString(Method method);
            static std::string SchemeToString(Scheme scheme);

            //HEADERS
            static const char* ACCEPT;
            static const char* ACCEPT_CHARSET;
            static const char* ACCEPT_ENCODING;
            static const char* ACCEPT_LANGUAGE;
            static const char* AUTHORIZATION;
            static const char* CACHE_CONTROL;
            static const char* CONTENT_DISPOSITION;
            static const char* CONTENT_ENCODING;
            static const char* CONTENT_LENGTH;
            static const char* CONTENT_MD5;
            static const char* CONTENT_RANGE;
            static const char* CONTENT_TYPE;
            static const char* DATE;
            static const char* EXPECT;
            static const char* EXPIRES;
            static const char* ETAG;
            static const char* LAST_MODIFIED;
            static const char* RANGE;
            static const char* USER_AGENT;

    };
}
}
