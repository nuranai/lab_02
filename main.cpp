#include <iostream>
#include "observable.h"
#include "observer.h"

using namespace std;

int main()
{
    FileMonitor monitor;
    FileObserver observer;
    monitor.Attach(&observer);

    monitor.Change();
    return 0;
}
