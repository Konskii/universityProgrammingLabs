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
    
    //MARK: - Задание 3(вариант 13)
    fstream input1Stream;
    fstream input2Stream;
    fstream output1Stream;
    fstream output2Stream;
    try {
        input1Stream.open(
                          "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/input1.txt",
                          iostream::in
                          );
    } catch (...) {
        cout << "Не удалось открыть файл input1.txt" << endl;
        return 4;
    }
    try {
        input2Stream.open(
                          "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/input2.txt",
                          iostream::in
                          );
    } catch (...) {
        cout << "Не удалось открыть файл input2.txt" << endl;
        return 5;
    }
    try {
        output1Stream.open(
                          "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/output1.txt",
                          iostream::out
                          );
    } catch (...) {
        
        cout << "Не удалось открыть файл output1.txt" << endl;
        return 6;
    }
    try {
        output2Stream.open(
                          "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/output2.txt",
                          iostream::out
                          );
    } catch (...) {
        cout << "Не удалось открыть файл output2.txt" << endl;
        return 7;
    }
    
    int input1NumbersCount = 0;
    int input2NumbersCount = 0;
    while (!input1Stream.eof()) {
        int i;
        input1Stream >> i;
        if (!input1Stream.eof()) {
            input1NumbersCount++;
        }
    }
    while (!input2Stream.eof()) {
        int i;
        input2Stream >> i;
        if (!input2Stream.eof()) {
            input2NumbersCount++;
        }
    }
    
    int *input1Numbers = new int[input1NumbersCount];
    input1Stream.close();
    input1Stream.open(
                      "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/input1.txt",
                      iostream::in
                      );
    for (int i = 0; i < input1NumbersCount; i++) {
        int a;
        input1Stream >> a;
        input1Numbers[i] = a;
    }
    
    int *input2Numbers = new int[input2NumbersCount];
    input2Stream.close();
    input2Stream.open(
                      "/Users/artem/Projects/universityProgrammingLabs/lab-2/Temp/individualTask/input2.txt",
                      iostream::in
                      );
    for (int i = 0; i < input2NumbersCount; i++) {
        int a;
        input2Stream >> a;
        input2Numbers[i] = a;
    }
    
    int output1NumbersCount = 0;
    for (int *ptr = &input1Numbers[0]; ptr < &input1Numbers[input1NumbersCount]; ptr++) {
        bool isSame = false;
        for (int *ptr2 = &input2Numbers[0]; ptr2 < &input2Numbers[input2NumbersCount]; ptr2++) {
            if (*ptr2 == *ptr) {
                isSame = true;
            }
        }
        if (!isSame) {
            output1Stream << *ptr << endl;
            output1NumbersCount++;
        }
    }
    output1Stream << "Количество чисел: " << output1NumbersCount;
    output1Stream.close();
    
    int output2NumbersCount = 0;
    for (int *ptr = &input2Numbers[0]; ptr < &input2Numbers[input2NumbersCount]; ptr++) {
        bool isSame = false;
        for (int *ptr2 = &input1Numbers[0]; ptr2 < &input1Numbers[input1NumbersCount]; ptr2++) {
            if (*ptr2 == *ptr) {
                isSame = true;
            }
        }
        if (!isSame) {
            output2Stream << *ptr << endl;
            output2NumbersCount++;
        }
    }
    output2Stream << "Количество чисел: " << output2NumbersCount;
    output2Stream.close();
    
    return 0;
}
