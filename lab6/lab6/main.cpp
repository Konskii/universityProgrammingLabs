//
//  main.cpp
//  lab6
//
//  Created by Артём Скрипкин on 11.12.2021.
//

#include <iostream>
using namespace std;

int main() {
    string a;
    //checking string entered by user
    while(true) {
        cout << "Введите строку:";
        getline(cin, a);
        if (cin.fail() || a.length() > 80) {
            cin.clear();
            cout << "Введеная вами строка некоректна, попробуйте еще раз." << endl << endl;
        } else {
            break;
        }
    }
    
    //counting words
    int wordsCount = 0;
    for (char *ptr = &a[0]; ptr < &a[a.length()]; ++ptr){
        if (isalpha(*ptr)) {
            while (*ptr != ' ') {
                ptr++;
            }
            if (*ptr == ' ') {
                wordsCount ++;
            }
        }
    }
    cout << "Количество слов: " << wordsCount << endl;
    
    //marking array of words
    string *arrayOfWords = new string[wordsCount];
    int i = 0;
    string tempString;
    for (char *str = &a[0]; str < &a[a.length()]; str++) {
        string tempString;
        while (isalpha(*str)) {
            tempString += *str;
            str++;
        }
        arrayOfWords[i] = tempString;
        i++;
    }
    
    //finding smaller word
    string smallerWord = arrayOfWords[0];
    for (string *str = &arrayOfWords[0]; str < &arrayOfWords[wordsCount]; str ++) {
        if (str->length() < smallerWord.length()) {
            smallerWord = *str;
        }
    }
    
    cout << "меньшее слово: " << smallerWord << endl;
    cout << "слова большие меньшего слова:" << endl;
    
    int biggerWordsCount = 0;
    for (string *str = &arrayOfWords[0]; str < &arrayOfWords[wordsCount]; str ++) {
        if (str->length() > smallerWord.length()) {
            cout << "\t" << *str << endl;
            biggerWordsCount++;
        }
    }
    
    cout << "количество слов которые больше меньшего слова: " << biggerWordsCount << endl;
    
}
