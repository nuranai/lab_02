#include "observer.h"

// вывод на консоль об обновлении состояния
void FileObserver::Update(bool existence, long size) {
    if (lastSize == -1) lastSize = size; //если это первый вызов обновляем послдений размер
    if (existence) { //если файл существует
        if (lastSize != size) { //если был изменен размер
            std::cout << "File is existung, file has been changed, size: " << size << std::endl;
            lastSize = size; //обновляем размер
        }
        else {
            //существование файла
            std::cout << "File is existing, size: " << lastSize << std::endl;
        }
    }
    // несуществование файла
    else {
        std::cout << "File is not existing" << std::endl;
    }
}
