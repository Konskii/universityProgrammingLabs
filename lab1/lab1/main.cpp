//
//  main.cpp
//  lab1
//
//  Created by Артём Скрипкин on 09.03.2022.
//

#include <iostream>
#include <string.h>
#include "Student.h"
using namespace std;

int main() {
    Student students[10] = {
        Student{.name =  "Name1", .secondName = "SecondName1", .score = 299},
        Student{.name =  "Name2", .secondName = "SecondName2", .score = 199},
        Student{.name =  "Name3", .secondName = "SecondName3", .score = 229},
        Student{.name =  "Name4", .secondName = "SecondName4", .score = 99},
        Student{.name =  "Name5", .secondName = "SecondName5", .score = 259},
        Student{.name =  "Name6", .secondName = "SecondName6", .score = 149},
        Student{.name =  "Name7", .secondName = "SecondName7", .score = 49},
        Student{.name =  "Name8", .secondName = "SecondName8", .score = 140},
        Student{.name =  "Name9", .secondName = "SecondName9", .score = 299},
        Student{.name =  "Name10", .secondName = "SecondName10", .score = 299},
    };
    //Task1: Вывести на экран результаты поиска: студента с максимальной суммой баллов; студента с указанной фамилией.
    cout << "Введите фамилию для поиска: ";
    string searchSecondName;
    bool isFind = false;
    Student bufferStudent = students[0];
    int maxScoreStudentsCount = 0;
    cin >> searchSecondName;
    
    for (int i = 0; i < 10; i++) {
        Student student = students[i];
        if (student.score > bufferStudent.score) {
            bufferStudent = student;
            maxScoreStudentsCount = 1;
        }
        if (student.score == bufferStudent.score) {
            maxScoreStudentsCount++;
        }
        if (student.secondName == searchSecondName) {
            cout << "Студент с фамилей '" << searchSecondName << "' найден" << endl;
            cout << "Его имя: " << student.name << endl;
            cout << "Количество баллов: " << student.score << endl;
            isFind = true;
        }
    }
    if (!isFind) {
        cout << "Студент с фамилей '" << searchSecondName << "' не найден." << endl;
    }
    if (maxScoreStudentsCount == 1) {
        cout << "Студент с максимальным количеством баллов найден" << endl;
        cout << "Его имя: " << bufferStudent.name << endl;
        cout << "Его фамилия: " << bufferStudent.secondName << endl;
        cout << "Количество баллов: " << bufferStudent.score << endl;
    } else {
        Student maxScoreStudents[maxScoreStudentsCount];
        int a = 0;
        for (int i = 0; i < 10; i++) {
            Student student = students[i];
            if (student.score == bufferStudent.score) {
                maxScoreStudents[a] = student;
                a++;
            }
        }
        
        cout << "Найдено несколько студней с максимальным количеством баллов: " << endl << endl;
        cout << maxScoreStudentsCount << " студня" << endl;
        for (int i = 0; i < maxScoreStudentsCount; i++) {
            Student student = maxScoreStudents[i];
            cout << "Студент №" << i+1 << endl;
            cout << "Его имя: " << student.name << endl;
            cout << "Его фамилия: " << student.secondName << endl;
            cout << "Количество баллов: " << student.score << endl << endl;
        }
    }
    
}
