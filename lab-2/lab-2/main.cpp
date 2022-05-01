//
//  main.cpp
//  lab-2
//
//  Created by Артём Скрипкин on 05.04.2022.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
    // MARK: - Задание 1
    fstream dataStream;
    fstream positiveStream;
    try {
        dataStream.open(
                        "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/data.txt",
                        ios::in
                        );
    } catch(...) {
        cout << "Ошибка открытия файла data.txt" << endl;
        return 1;
    }
    try {
        positiveStream.open(
                            "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/positive.txt",
                            ios::out
                            );
    } catch (...) {
        cout << "Ошибка открытия файла positive.txt" << endl;
        return 2;
    }
    int a;
    while (!dataStream.eof()) {
        dataStream >> a;
        if (a > 0) {
            positiveStream << a;
        }
        positiveStream << "\n";
    }
    
    positiveStream.open(
                        "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/positive.txt",
                        ios::out
                        );
    dataStream.close();
    positiveStream.close();
    return 0;
}
