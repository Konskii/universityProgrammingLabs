//
//  main.cpp
//  lab6
//
//  Created by Артём Скрипкин on 11.12.2021.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    //MARK: - Проверка на корректность введенной строки
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    
    //MARK: - Разбивка строки на слова
    string tempStr = "";
    vector<string> words = {};
    int i = 0;
    
    while (i < str.length()) {

        if (str[i] == ' ') {
            tempStr = "";
            i++;
        }
        
        if (str[i] != ' ') {
            while (str[i] != ' ' && i < str.length()) {
                tempStr += str[i];
                if (str[i] == ' ') {
                    break;
                }
                i++;
            }
            //Работаем с полученным словом:
            if (tempStr != "" && tempStr != " ") {
                words.push_back(tempStr);
            }
        }
    }
    
    //TODO: добавить проверку на наличие слов
    //MARK: - Поиск меньшего слова
    string smallerWord = words[0];
    int smallerIndex = 0;
    for (int counter = 0; counter < words.size(); counter++) {
        if (words[counter].length() < smallerWord.length()) {
            smallerWord = words[counter];
            smallerIndex = counter;
        }
    }
    cout << "Меньшее слово: " << smallerWord << endl;
    
    //MARK: - Вывод больших слов
    cout << "Слова которые больше чем '" << smallerWord << "'" << endl;
    int biggerWordsCount = 0;
    for (int counter = 0; counter < words.size(); counter++) {
        if (counter != smallerIndex &&
            words[counter].length() != smallerWord.length()) {
            cout << words[counter] << endl;
            biggerWordsCount++;
        }
    }
    cout << "Количество больших слов: " << biggerWordsCount << endl;
    
}
