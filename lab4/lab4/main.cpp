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
    int *array = new int[n];
    
    //filling array
    for (int counter = 0; counter < n; counter ++) {
        cout << "enter a value: ";
        cin >> array[counter];
    }
    
    //finding min value in array and his index
    int min = array[0];
    int indexOfMin = 0;
    float sum = 0;
    for (int counter = 0; counter < n; counter ++) {
        sum += array[counter];
        if (array[counter] < min) {
            min = array[counter];
            indexOfMin = counter;
        }
    }
    
    //printing min value and his index
    cout << "min value (" << min << ") in array has index " << indexOfMin << "\n";
    cout << "среднее арифмитическое всех чисел: " << sum / n << "\n";
    
    //replace min value in his index with arithmetical average of all values
    array[indexOfMin] = sum / n;
    cout << "value in index " << indexOfMin << " now is: " << array[indexOfMin] << "\n";
}

