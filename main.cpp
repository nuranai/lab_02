#include <iostream>
#include "observable.h"
#include "observer.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // тестирование методов
    // все файли будут находится в файла проекта
    FileMonitor monitor("filename.txt"); // файл существует с данными
    FileMonitor monitor1("test.txt"); // файл существует и с данными после первой итерации будет удалена подписка
    FileMonitor monitorEmpty("empty.txt"); // файл существует но пустой
    FileMonitor monitorNotExists("notExisting.txt"); // файл не существует
    FileMonitor monitorRename("toRename.txt"); // файл существует но будет переименован

    //объект наблюдатель
    FileObserver observer;
    //свфзывание наблюдателей с источником
    monitor.Attach(&observer);
    monitor1.Attach(&observer);
    monitorEmpty.Attach(&observer);
    monitorNotExists.Attach(&observer);
    monitorRename.Attach(&observer);

    // количество итераций
    int iteration = 1;
    while (true){
        std::cout << "current iteration: " << iteration << std::endl;
        std::cout<< "check for filename.txt:" <<std::endl;
        monitor.checkFile();
        std::cout<< "check for test.txt:" <<std::endl;
        monitor1.checkFile();
        std::cout<< "check for empty.txt" <<std::endl;
        monitorEmpty.checkFile();
        std::cout<< "check for notExisting.txt" <<std::endl;
        monitorNotExists.checkFile();
        std::cout<< "check for notExisting.txt" <<std::endl;
        monitorRename.checkFile();
        // при первой итерации удаялем раблюдателя
        if (iteration == 1) {
            monitor1.Detach(&observer);
        }
        iteration++;
        std::cout << "___________________________________" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
    }
    return 0;
}
