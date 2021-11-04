//
//  main.cpp
//  lab3
//
//  Created by Артём Скрипкин on 04.11.2021.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int sum = 0;
    int array[5] ={};
    
    for (int counter = 0; counter <5; counter++) {
        cout << "введите число для добавления в массив\n";
        cin >> array[counter];
    }
    
    for (int counter = 0; counter <5; counter ++) {
        if (counter % 2 != 0 || counter == 0) {
            sum += array[counter];
        }
    }
    cout << "\n\t сумма нечетных чисел равна:" << sum << "\n\n";
}
