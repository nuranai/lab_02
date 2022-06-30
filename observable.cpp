#include "observable.h"
#include <sys/stat.h>

// метод подписки объекта на оповещателя
void Observable::Attach(FileObserver *observer){
    // добавление наблюдателя
    subscribers.push_back(observer);
}

// метод удаления подписки обхекта для оповещателя
void Observable::Detach(FileObserver *observer){
    // удаление
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), observer), subscribers.end());
}

// метод оповещения
// наблюдатели обновлятся независимо, с учето текущего состояния
void Observable::Notify(bool existence, long size){
    for(std::vector<FileObserver*>::const_iterator iter = subscribers.begin(); iter != subscribers.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update(existence, size);
        }
    }
}

FileMonitor::FileMonitor(std::string _name) : prevFileState(_name) { }

void FileMonitor::checkFile() {
    FileInfo newFileState(prevFileState.name); // получаем новое состояние файла
    Change(newFileState.existence, newFileState.size); // регистрируем изменения
    prevFileState = newFileState; // обновляем состояние файла
}

void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
