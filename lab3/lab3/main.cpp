//
//  main.cpp
//  lab3
//
//  Created by Артём Скрипкин on 04.11.2021.
//

#include <iostream>
using namespace std;

int main() {
    //MARK: - [-52; 26]
    int min = -52;
    int max = 26;
    int count = 0;
    int sum = 0;
    
    //counting values count
    for (int minimal = min; minimal <= max; minimal ++) {
        count++;
    }
    int array[count];
    
    //filling array and checking values
    for (int counter = 0; counter < count; counter ++) {
        array[counter] = min;
        if ((counter % 2 != 0 || counter == 0) && array[counter] % 2 != 0) {
            sum += array[counter];
        }
        min++;
    }
    cout << "сумма нечетных значений под нечетными индексами из диапазона [-52; 26] = ";
    cout << sum << "\n";
    
    //MARK: - custom filling
    int newSum = 0;
    int arrayCount;
    
    //asking for maxIndex
    cout << "\nenter values count: ";
    cin >> arrayCount;
    int newArray[arrayCount];
    
    //filling array and checking values
    for (int counter = 0; counter < arrayCount; counter ++) {
        cout << "enter a value: ";
        cin >> newArray[counter];
        if ((counter % 2 != 0 || counter == 0) && newArray[counter] % 2 != 0) {
            newSum += newArray[counter];
        }
    }

    cout << "\nсумма нечетных значений под нечетными индексами = ";
    cout << newSum << "\n\n";
}
