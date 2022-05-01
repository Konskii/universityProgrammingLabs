//
//  main.cpp
//  lab-2
//
//  Created by Артём Скрипкин on 05.04.2022.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <limits>
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
    
    //MARK: - Задание 2
    fstream dataTypesStream;
    try {
        dataTypesStream.open(
                             "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/dataTypes.txt",
                             ios::out
                             );
    } catch (...) {
        cout << "Ошибка открытия файла dataTypes.txt" << endl;
        return 3;
    }
    
    //Заголовки
    dataTypesStream << setiosflags(ios::left) << setw(25) << "Type:";
    dataTypesStream << setw(15) << "Size:";
    dataTypesStream << setw(25) << "Max value:";
    dataTypesStream << setw(40) << "Min value:" << endl;
    //char
    dataTypesStream << setiosflags(ios::left) << setw(25) << "char";
    dataTypesStream << setw(15) << sizeof(char);
    dataTypesStream << setw(25) << CHAR_MAX;
    dataTypesStream << setw(40) << CHAR_MIN << endl;
    //short int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "short int";
    dataTypesStream << setw(15) << sizeof(short int);
    dataTypesStream << setw(25) << numeric_limits<short int>::max();
    dataTypesStream << setw(40) << numeric_limits<short int>::min() << endl;
    //unsigned short int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "unsigned short int";
    dataTypesStream << setw(15) << sizeof(unsigned short int);
    dataTypesStream << setw(25) << numeric_limits<unsigned short int>::max();
    dataTypesStream << setw(40) << numeric_limits<unsigned short int>::min() << endl;
    //int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "int";
    dataTypesStream << setw(15) << sizeof(int);
    dataTypesStream << setw(25) << numeric_limits<int>::max();
    dataTypesStream << setw(40) << numeric_limits<int>::min() << endl;
    //unsigned int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "unsigned int";
    dataTypesStream << setw(15) << sizeof(unsigned int);
    dataTypesStream << setw(25) << numeric_limits<unsigned int>::max();
    dataTypesStream << setw(40) << numeric_limits<unsigned int>::min() << endl;
    //long int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "long int";
    dataTypesStream << setw(15) << sizeof(long int);
    dataTypesStream << setw(25) << numeric_limits<long int>::max();
    dataTypesStream << setw(40) << numeric_limits<long int>::min() << endl;
    //unsigned long int
    dataTypesStream << setiosflags(ios::left) << setw(25) << "unsigned long int";
    dataTypesStream << setw(15) << sizeof(unsigned long int);
    dataTypesStream << setw(25) << numeric_limits<unsigned long int>::max();
    dataTypesStream << setw(40) << numeric_limits<unsigned long int>::min() << endl;
    //float
    dataTypesStream << setiosflags(ios::left) << setw(25) << "float";
    dataTypesStream << setw(15) << sizeof(float);
    dataTypesStream << setw(25) << numeric_limits<float>::max();
    dataTypesStream << setw(40) << numeric_limits<float>::min() << endl;
    //double
    dataTypesStream << setiosflags(ios::left) << setw(25) << "double";
    dataTypesStream << setw(15) << sizeof(double);
    dataTypesStream << setw(25) << numeric_limits<double>::max();
    dataTypesStream << setw(40) << numeric_limits<double>::min() << endl;
    //long double
    dataTypesStream << setiosflags(ios::left) << setw(25) << "long double";
    dataTypesStream << setw(15) << sizeof(long double);
    dataTypesStream << setw(25) << numeric_limits<long double>::max();
    dataTypesStream << setw(40) << numeric_limits<long double>::min();
    
    dataTypesStream.close();
    return 0;
}
