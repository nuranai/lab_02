#include "observer.h"

void FileObserver::Update(bool existence, long size) {
    if (lastSize == -1) lastSize = size;
//    lastSize = size;
    if (existence) {
        if (lastSize != size) {
            std::cout << "File is existung, file has been changed, size: " << size << std::endl;
            lastSize = size;
        }
        else {
            std::cout << "File is existing, size: " << lastSize << std::endl;
        }
    }
    else {
        std::cout << "File is not existing" << std::endl;
    }
//    std::cout << "called" << std::endl;
}
