//
//  main.cpp
//  lab1
//
//  Created by Артём Скрипкин on 09.03.2022.
//

#include <iostream>
#include "Date.h"
#include "Student.h"
#include <ctime>
#include "Tour.h"
using namespace std;

int calculateAge(Date birthDate) {
    time_t t = time(0);
    tm* now = localtime(&t);
    Date currentDate = {
        .day = now->tm_mday,
        .month = now->tm_mon+1,
        .year = now->tm_year + 1900
    };
    
    int age = currentDate.year - birthDate.year;
    if (currentDate.month > birthDate.month) {
        age--;
    } else if (currentDate.month == birthDate.month) {
        if (currentDate.day > birthDate.day) {
            age--;
        }
    }
    return age;
}

int main() {
    string manGender = "Мужчина";
    string girlGender = "Женщина";
    Date goodDate = Date{.day = 11, .month = 3, .year = 2006};
    Date badDate = Date{.day = 1, .month = 6, .year = 1992};
    
    Student students[10] = {
        Student{.name =  "Name1",
                .secondName = "SecondName1",
                .score = 299,
                .gender = manGender,
                .birthDate = goodDate
        },
        Student{.name =  "Name2",
                .secondName = "SecondName2",
                .score = 199,
                .gender = manGender,
                .birthDate = badDate
        },
        Student{.name =  "Name3",
                .secondName = "SecondName3",
                .score = 229,
                .gender = girlGender,
                .birthDate = goodDate
        },
        Student{.name =  "Name4",
                .secondName = "SecondName4",
                .score = 99,
                .gender = girlGender,
                .birthDate = goodDate
        },
        Student{.name =  "Name5",
                .secondName = "SecondName5",
                .score = 259,
                .gender = girlGender,
                .birthDate = badDate
        },
        Student{.name =  "Name6",
                .secondName = "SecondName6",
                .score = 149,
                .gender = manGender, .birthDate = badDate
        },
        Student{.name =  "Name7",
                .secondName = "SecondName7",
                .score = 49,
                .gender = girlGender,
                .birthDate = badDate
        },
        Student{.name =  "Name8",
                .secondName = "SecondName8",
                .score = 140,
                .gender = girlGender,
                .birthDate = badDate
        },
        Student{.name =  "Name9",
                .secondName = "SecondName9",
                .score = 299,
                .gender = manGender,
                .birthDate = goodDate
        },
        Student{.name =  "Name10",
                .secondName = "SecondName10",
                .score = 299,
                .gender = girlGender,
                .birthDate = badDate
        }
    };
    //Task1: Вывести на экран результаты поиска: студента с максимальной суммой баллов; студента с указанной фамилией.
    cout << "-------------Task1" << endl;
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
    
    //Task2: Задан массив структур «Студент» (фамилия; имя; пол; вложенная структура дата рождения в формате день:месяц:год). Вы- вести фамилии студентов, подлежащих призыву.
    cout << "-------------Task2" << endl;
    cout << "Студенты, подлежащие призыву:" << endl;
    bool isFindStudents = false;
    for (int i = 0; i < 10; i++) {
        Student student = students[i];
        if ((calculateAge(student.birthDate) >= 18) && student.gender == manGender) {
            cout << student.secondName << endl;
            isFindStudents = true;
        }
    }
    if (!isFindStudents) {
        cout << "Нет студентов подлежащих призыву." << endl;
    }
    cout << endl;
    //Task3(вариант 13): Задан массив структур «Тур» (наименование тура; страна; продолжительность; стоимость; количество свободных путе- вок). Вывести на экран список туров, имеющихся в наличии.
    cout << "-------------Task3" << endl;
    Tour tours[10] = {
        Tour{.name = "Tour1", .country = "Country", .duration = 5.5, .avalaibleCount = 0},
        Tour{.name = "Tour2", .country = "Country", .duration = 12.5, .avalaibleCount = 0},
        Tour{.name = "Tour3", .country = "Country", .duration = 124, .avalaibleCount = 0},
        Tour{.name = "Tour4", .country = "Country", .duration = 214, .avalaibleCount = 10},
        Tour{.name = "Tour5", .country = "Country", .duration = 1245, .avalaibleCount = 0},
        Tour{.name = "Tour6", .country = "Country", .duration = 10, .avalaibleCount = 0},
        Tour{.name = "Tour7", .country = "Country", .duration = 11, .avalaibleCount = 15},
        Tour{.name = "Tour8", .country = "Country", .duration = 5, .avalaibleCount = 0},
        Tour{.name = "Tour9", .country = "Country", .duration = 51, .avalaibleCount = 0},
        Tour{.name = "Tour10", .country = "Country", .duration = 55, .avalaibleCount = 1},
    };
    
    int avalaibleToursCount = 0;
    for (int i = 0; i < 10; i++) {
        Tour tour = tours[i];
        if (tour.avalaibleCount > 0) {
            avalaibleToursCount++;
        }
    }
    Tour avalaibleTours[avalaibleToursCount];
    int a = 0;
    for (int i = 0; i < 10; i++) {
        Tour tour = tours[i];
        if (tour.avalaibleCount > 0) {
            avalaibleTours[a] = tour;
            a++;
        }
    }
    if (avalaibleToursCount == 0) {
        cout << "Нет доступных туров" << endl;
    } else {
        cout << "Доступные туры:" << endl;
        for (int i = 0; i < avalaibleToursCount; i++) {
            Tour tour = avalaibleTours[i];
            cout << "Название тура:"  << tour.name << endl;
            cout << "Страна тура:"  << tour.country << endl;
            cout << "Длительность тура:"  << tour.duration << endl;
            cout << "Количество доступных путевок:"  << tour.avalaibleCount << endl;
            cout << "Стоимость тура:"  << tour.cost << endl << endl;;
        }
    }
    
}
