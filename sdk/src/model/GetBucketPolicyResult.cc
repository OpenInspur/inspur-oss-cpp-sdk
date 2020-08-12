
#include <inspurcloud/oss/model/GetBucketPolicyResult.h>
using namespace InspurCloud::OSS;

GetBucketPolicyResult::GetBucketPolicyResult() :
    OssResult()
{
}

GetBucketPolicyResult::GetBucketPolicyResult(const std::string& result):
    GetBucketPolicyResult()
{
    *this = result;
}

GetBucketPolicyResult::GetBucketPolicyResult(const std::shared_ptr<std::iostream>& result):
    GetBucketPolicyResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

GetBucketPolicyResult& GetBucketPolicyResult::operator =(const std::string& result)
{
    policy_ = result;
    parseDone_ = true;
    return *this;
}
