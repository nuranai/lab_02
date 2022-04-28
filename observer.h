#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class IObserver {
public:
    virtual void Update(bool existence, long size) = 0;
};

class FileObserver: IObserver
{
private:
    long lastSize = -1;
public:
    void Update(bool existence, long size);
};

#endif // OBSERVER_H
