

#include <inspurcloud/oss/model/AppendObjectResult.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;

AppendObjectResult::AppendObjectResult():
    OssResult(),
    length_(0),
    crc64_(0)
{
}

AppendObjectResult::AppendObjectResult(const HeaderCollection& header):
    AppendObjectResult()
{
   if (header.find("x-oss-next-append-position") == header.end()) {
       parseDone_ = false;
   } else {
       length_ = std::strtoull(header.at("x-oss-next-append-position").c_str(), nullptr, 10);
   }

   if (header.find("x-oss-hash-crc64ecma") == header.end()) {
       parseDone_ = false;
   } else {
       crc64_  = std::strtoull(header.at("x-oss-hash-crc64ecma").c_str(), nullptr, 10);
   }
   parseDone_ = true;
}

