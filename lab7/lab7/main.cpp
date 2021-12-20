//
//  main.cpp
//  lab7
//
//  Created by Артём Скрипкин on 20.12.2021.
//

#include <iostream>
#include <string>
using namespace std;

//MARK: - isCorrect
bool isCorrect(int n1, int n2) {
    if (n2 <= n1) {
        return false;
    }
    return true;
}

//MARK: - isSimple
bool isSimple(int n) {
    if (n > 1) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

//MARK: - isFail
bool isFail(int n, int m) {
    string nString = to_string(n);
    string mString = to_string(m);
    for (int i = 0; i < nString.length(); i++) {
        if (nString[i] == mString[0]) {
            return false;
        }
    }
    return  true;
}

//MARK: - main
int main() {
    int begin, end, m;
    
    //MARK: - Проверка интервала
    while (true) {
        cout << "Введите начало цикла: ";
        cin >> begin;
        cout << "Введите конец цикла: ";
        cin >> end;
        if (isCorrect(begin, end)) {
            break;
        }
        cout << "Введенный интервал некорректен. Попробуйте еще раз." << endl;
    }
    
    int count = 0;
    cout << "Введите число: ";
    cin >> m;
    
    for (int i = begin; i <= end; i++) {
        if (isFail(i, m)) {
            if (isSimple(i)) {
                count++;
            }
        }
    }
    
    cout << "Количество простых чисел, в которых отсутствует '"<< m << "', на интервале ["<< begin << "," << end << "] равно: " << count << endl;
}
