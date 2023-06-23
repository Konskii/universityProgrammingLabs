//
//  main.cpp
//  control-task
//
//  Created by Артём Скрипкин on 23.06.2023.
//
#include <cstring>
#include "sharedTask.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    if (strcmp(argv[1], "-shared") == 0) {
        performSharedTask();
    } else if (strcmp(argv[1], "-personal") == 0) {

    }
    return 0;
}
