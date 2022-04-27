#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class IObserver {
public:
    virtual void Update() = 0;
};

class FileObserver: IObserver
{
public:
    void Update();
};

#endif // OBSERVER_H
