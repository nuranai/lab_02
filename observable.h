#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <string>
#include "observer.h"
#include <vector>

class Observable
{
private:
    std::vector<FileObserver*> subscribers;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify();
};

class FileMonitor: public Observable {
public:
    void Change();
};

#endif // OBSERVABLE_H
