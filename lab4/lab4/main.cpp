//
//  main.cpp
//  lab4
//
//  Created by Артём Скрипкин on 06.11.2021.
//

#include <iostream>
using namespace std;
int main() {
    //creating aray
    int n;
    cout << "enter values count: ";
    cin >> n;
    float *array = new float[n];
    
    //filling array
    for (int counter = 0; counter < n; counter ++) {
        cout << "enter a value: ";
        cin >> array[counter];
    }
    
    //finding min value in array and his index
    float *minPointer;
    minPointer = &array[0];
    float sum = 0;
    for (int counter = 0; counter < n; counter ++) {
        sum += array[counter];
        if (array[counter] < *minPointer) {
            minPointer = &array[counter];
        }
    }
    
    //printing min value, his index and adress
    cout << "min value (" << *minPointer << ") in adress: " << minPointer << "\n";
    cout << "среднее арифмитическое всех чисел: " << sum / n << "\n";
    
    //replace min value in his index with arithmetical average of all values
    *minPointer = sum /n;
    cout << "value in adress " << minPointer << " now is: " << *minPointer << "\n";
}

