#include "observable.h"

void Observable::Attach(FileObserver *observer){
    subscribers.push_back(observer);
}

void Observable::Detach(FileObserver *observer){
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
}

void Observable::Notify(){
    for(std::vector<FileObserver*>::const_iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update();
        }
    }
}

void FileMonitor::Change() {
    Notify();
}
