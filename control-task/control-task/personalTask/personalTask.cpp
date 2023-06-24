//
//  personalTask.cpp
//  control-task
//
//  Created by Артём Скрипкин on 23.06.2023.
//

#include <iostream>
#include "Book.h"
#include <vector>
using namespace std;

void performPersonalTask() {
    Book allBooks[5] = {
        Book("Daniel", "Wolf", 2020),
        Book("Eduard", "The Greates", 2015),
        Book("Mark", "Notebooks", 2013),
        Book("Nepton", "The book of the book", 2014),
        Book("Redklif", "Wolf", 2010)
    };

    cout << "Введитие максимально допустимый год выпуска книги: ";
    int maxYear;
    scanf("%i", &maxYear);

    vector<Book> filteredBooks = {};

    for (int i = 0; i < 5; i++) {
        if (allBooks[i].isProducedBefore(maxYear)) {
            filteredBooks.push_back(allBooks[i]);
        }
    }

    cout << "Результаты фильтрации: \n";
    for (int i = 0; i < filteredBooks.size(); i++) {
        Book book = filteredBooks[i];
        cout << "Автор: " << book.author
             << ", Название: " << book.name
             << ", Год: " << book.yearOfProduce << "\n";
    }
}
