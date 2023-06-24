//
//  Book.hpp
//  control-task
//
//  Created by Артём Скрипкин on 23.06.2023.
//

#ifndef Book_hpp
#define Book_hpp

#include <string>

using namespace std;

struct Book {
    string author;
    string name;
    int yearOfProduce;

    Book(string author, string name, int year) {
        this->author = author;
        this->name = name;
        this->yearOfProduce = year;
    }

    bool isProducedBefore(int year) {
        return yearOfProduce < year;
    }
};

#endif /* Book_hpp */
