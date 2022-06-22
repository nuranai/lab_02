#ifndef FILEINFO_H
#define FILEINFO_H

#include <string>
#include <sys/stat.h>

class FileInfo
{
public:
    std::string name; // имя файла
    long size; // размер
    bool existence; // существование файла
    FileInfo(std::string fileName);
};

#endif // FILEINFO_H
