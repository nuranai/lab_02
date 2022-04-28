#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <string>
#include "observer.h"
#include <vector>
#include <fileinfo.h>

class Observable
{
private:
    std::vector<FileObserver*> subscribers;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify(bool existence, long size);
};

class FileMonitor: public Observable {
private:
    FileInfo prevFileState;
public:
    FileMonitor(std::string _name);
    void checkFile();
    void Change(bool existence, long size);
};

#endif // OBSERVABLE_H
