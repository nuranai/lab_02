#include "observable.h"
#include <sys/stat.h>

void Observable::Attach(FileObserver *observer){
    subscribers.push_back(observer);
}

void Observable::Detach(FileObserver *observer){
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
}

void Observable::Notify(bool existence, long size){
    for(std::vector<FileObserver*>::const_iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update(existence, size);
        }
    }
}

FileMonitor::FileMonitor(std::string _name) : prevFileState(_name) { }

void FileMonitor::checkFile() {
    FileInfo newFileState(prevFileState.name);
//    if (prevFileState.)
//    FileInfo newFileState()
    Change(newFileState.existence, newFileState.size);
    prevFileState = newFileState;
}

void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
