#include <iostream>
#include "observable.h"
#include "observer.h"
#include <chrono>
#include <thread>

int main()
{
    int prog;
    std::cout << "to test program press 1, to run program press 2, to exit press any other number:" << std::endl;
    std::cin >> prog;

    switch (prog) {
    case 1:
    {
        // блок тестирования программы
        // все файлы находятся внутри папки проекта
        FileMonitor monitor("filename.txt"); // файл существует с данными
        FileMonitor monitor1("test.txt"); // файл существует и с данными после первой итерации будет удалена подписка
        FileMonitor monitorEmpty("empty.txt"); // файл существует но пустой
        FileMonitor monitorNotExists("notExisting.txt"); // файл не существует
        FileMonitor monitorDelete("toDelete.txt"); // файл существует с данными, будет удален
        FileMonitor monitorRename("toRename.txt"); // файл существует но будет переименован

        //объект наблюдатель
        FileObserver observer;
        FileObserver emptyObserver;
        FileObserver notExistsObserver;
        FileObserver deleteObserver;
        FileObserver renameObserver;

        //свфзывание наблюдателей с источникaми
        monitor.Attach(&observer);
        monitor1.Attach(&observer);
        monitorEmpty.Attach(&emptyObserver);
        monitorNotExists.Attach(&notExistsObserver);
        monitorDelete.Attach(&deleteObserver);
        monitorRename.Attach(&renameObserver);

        // проверка первого файла
        std::cout<< "check for filename.txt:" <<std::endl;
        monitor.checkFile();
        // проверка на его изменение
        std::cout << "please enter changes in filename.txt" << std::endl;
        system("pause");
        std::cout<< "check for filename.txt:" <<std::endl;
        monitor.checkFile();

        // проверка двух файлов
        std::cout<< "check for test.txt:" <<std::endl;
        monitor1.checkFile();
        // удаляем наблюдателя
        monitor1.Detach(&observer);
        std::cout << "observer was removed in monitor1" << std::endl;

        std::cout<< "check for test.txt:" <<std::endl;
        monitor1.checkFile();

        // проверка существующего пустого файла
        std::cout<< "check for empty.txt" <<std::endl;
        monitorEmpty.checkFile();
        std::cout << "please enter cahnges in empty.txt" << std::endl;
        system("pause");
        monitorEmpty.checkFile();

        //проверка не существующего файла
        std::cout<< "check for notExisting.txt" <<std::endl;
        monitorNotExists.checkFile();
        std::cout << "please create file notExisting.txt" << std::endl;
        system("pause");
        std::cout<< "check for notExisting.txt" <<std::endl;
        monitorNotExists.checkFile();

        // проверка файла на удаление
        std::cout << "check for toDelete.txt" << std::endl;
        monitorDelete.checkFile();
        std::cout << "please delete file toDelete.txt" << std::endl;
        system("pause");
        monitorDelete.checkFile();

        // проверка на изменение названия файла
        std::cout << "check for toRename.txt" << std::endl;
        monitorRename.checkFile();
        std::cout << "please rename file toRename.txt" <<std::endl;
        system("pause");
        std::cout << "check for toRename.txt" << std::endl;
        monitorRename.checkFile();

        std::cout << "test finished" << std::endl;
        break;
    }
    case 2:
    {
    std::string filePath;
    // пользователь с помощью коммандной строки вводит путь до файла
        std::cout << "Please enter full file path:" << std::endl;
        std::cin >> filePath;
        // объект для отслеживания файла
        FileMonitor userMonitor(filePath);

        FileObserver userObserver;

        userMonitor.Attach(&userObserver);

        int iteration = 1;
        // бесконечный цикл для отслеживания состояния файла
        while (true){
            std::cout << "current iteration: " << iteration << std::endl;
            iteration++;
            userMonitor.checkFile();
            std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
        }

        break;
    }
    deafult: {
        break;
    }
    }



    // количество итераций
    return 0;
}
