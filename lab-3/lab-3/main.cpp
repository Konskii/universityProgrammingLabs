//
//  main.cpp
//  lab-3
//
//  Created by Артём Скрипкин on 03.05.2022.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // MARK: - Задание 1
    fstream studentStream;
    fstream grantStream;
    try {
        studentStream.open(
                           "/Users/artem/Projects/universityProgrammingLabs/lab-3/STUDENT.txt",
                           iostream::in
                           );
    } catch (...) {
        cout << "Ошибка открытия файла STUDENT.txt" << endl;
        return 1;
    }
    try {
        grantStream.open(
                         "/Users/artem/Projects/universityProgrammingLabs/lab-3/GRANT.txt",
                         iostream::out
                         );
    } catch (...) {
        cout << "Ошибка открытия/создания файла GRANT.txt" << endl;
        return 2;
    }
    
    while (!studentStream.eof()) {
        string LastName;
        string Name;
        int first;
        int second;
        int third;
        studentStream >> LastName;
        studentStream >> Name;
        studentStream >> first >> second >> third;
        if (first + second + third >= 215 ) {
            grantStream << LastName << " " << Name << " " << first << " " << second << " " << third << endl;
        }
    }
    return 0;
}
