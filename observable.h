#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <string>
#include "observer.h"
#include <vector>
#include <fileinfo.h>

//Класс отслеживает всех наблюдателей и предоставляет возможность добавлять или удалять наблюдателей.
class Observable // интерфейс наблюателей
{
private:
    std::vector<FileObserver*> subscribers; // отслеживание всех наблюдателей
public:
    void Attach(FileObserver *observer); //добавить наблюдателя
    void Detach(FileObserver *observer); // удалить наблюдателя
    void Notify(bool existence, long size); // оповестить всех наблюдателей
};

class FileMonitor: public Observable {
private:
    FileInfo prevFileState; //храним предыдущее состояние файла
public:
    FileMonitor(std::string _name);
    void checkFile(); //проверяем файл на состояние
    void Change(bool existence, long size); // регистрируем изменения
};

#endif // OBSERVABLE_H
