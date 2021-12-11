//
//  main.cpp
//  lab4
//
//  Created by Артём Скрипкин on 06.11.2021.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    //creating aray
    int n;
    cout << "enter values count: ";
    cin >> n;
    float *array = new float[n];
    float sum = 0;
    
    //filling array
    for (float *ptr = &array[0]; ptr <= &array[n]; ptr ++) {
        cout << "enter a value: ";
        cin >> *ptr;
        sum += *ptr;
    }
    cout << endl;
    
    //finding min value
    float *minPointer = &array[0];
    for (float *ptr = &array[0]; ptr <= &array[n]; ptr ++) {
        if (*ptr < *minPointer) {
            minPointer = ptr;
        }
        if (fmod(*ptr, float(2)) == 0) {
            cout << "адресс четного числа(" << *ptr << "): " << ptr << endl;
        }
    }
    cout << endl;
    
    //printing min value and his adress
    cout << "min value (" << *minPointer << ") in adress: " << minPointer << endl;
    cout << "среднее арифмитическое всех чисел: " << sum / n << endl;
    
    //replace min value in his adress with arithmetical average of all values
    *minPointer = sum /n;
    cout << "value in adress " << minPointer << " now is: " << *minPointer << endl << endl;
}

