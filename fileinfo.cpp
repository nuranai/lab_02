#include "fileinfo.h"

FileInfo::FileInfo(std::string fileName)
{
    name = fileName;
    struct stat stat_buf;
    existence = stat(fileName.c_str(), &stat_buf) == 0;
    size = stat_buf.st_size;
}
