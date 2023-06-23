//
//  main.cpp
//  control-task
//
//  Created by Артём Скрипкин on 23.06.2023.
//

#include <iostream>
#include <libc.h>
#include <string.h>
#include <cstdlib>
#include <thread>
using namespace std;

int main() {
    // MARK: - Task 1
    // MARK: Task 1 my personal information
    char myNameAndSecondName[] = "Artem Skripkin";

    char myName[5 + 1];
    strncpy(myName, myNameAndSecondName, 5);
    myName[5] = '\0';

    char mySecondName[8 + 1];
    strncpy(mySecondName, myNameAndSecondName + 6, 8);
    mySecondName[8] = '\0';

    int recordBookNumber = 21010410;

    cout << "----------------------------Task1 - cout----------------------------\n";
    cout << "\tМоя фамилия: " << mySecondName << "\n";
    cout << "\tМое имя: " << myName << "\n";
    cout << "\tНомер зачетной книжки: " << recordBookNumber << "\n";

    cout << "\n----------------------------Task1 - printf---------------------------\n";
    printf("\tМоя фамилия: %s\n\tМое имя: %s\n\tНомер зачетной книжки: %i\n", mySecondName, myName, recordBookNumber);

    // MARK: Task 1 SystemInfo
    char hostName[255];
    gethostname(hostName, sizeof(hostName));

    char* userName = getenv("USER");

    unsigned int threadCount = thread::hardware_concurrency();

    char* homeDirectory = getenv("HOME");

    cout << "\n----------------------------Task1 - system info----------------------\n";
    cout << "\tИмя компьютера: " << hostName << "\n";
    cout << "\tИмя пользователя: " << userName << "\n";
    cout << "\tКоличество ядер: " << threadCount << "\n";
    cout << "\tДомашняя директория: " << homeDirectory << "\n";


    return 0;
}
