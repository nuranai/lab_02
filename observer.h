#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class IObserver { // интерфейс observer
public:
    virtual void Update(bool existence, long size) = 0; // абстрактный метод обновления
};

class FileObserver: IObserver // конкретный класс observer
{
private:
    long lastSize = -1; // храним последний размер файла
public:
    void Update(bool existence, long size);
};

#endif // OBSERVER_H
