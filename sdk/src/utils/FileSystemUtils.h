#include <string>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    bool CreateDirectory(const std::string &folder);
    bool RemoveDirectory(const std::string &folder);
    bool RemoveFile(const std::string &filepath);
    bool RenameFile(const std::string &from, const std::string &to);
    bool GetPathLastModifyTime(const std::string &path, time_t &t);
    bool IsDirectoryExist(std::string folder);
}
}
