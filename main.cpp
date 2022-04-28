#include <iostream>
#include "observable.h"
#include "observer.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    FileMonitor monitor("filename.txt");
    FileObserver observer;
    monitor.Attach(&observer);

    while (true){
        monitor.checkFile();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    return 0;
}
