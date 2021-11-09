//
//  extra.cpp
//  lab5
//
//  Created by Артём Скрипкин on 09.11.2021.
//

#include <iostream>
#include <iomanip>
using namespace std;

void extra() {
    int indexX = 3;
    int indexY = 3;
    int indexZ = 3;
    int ***arr = new int**[indexZ];
    
    //выделение памяти
    for(int i=0; i<indexZ; i++) {
        arr[i] = new int*[indexY];
        for(int j=0; j<indexY;j++) {
            arr[i][j] = new int[indexX];
        }
    }

    //заполнение массива
    for(int z=0;z<indexZ;z++) {
        for(int y=0;y<indexY;y++) {
            for(int x=0;x<indexX;x++) {
                arr[z][y][x] = rand()%10+1;
            }
        }
    }
    
    //вывод значений массива
    for(int z=0;z<indexZ;z++) {
        for(int y=0;y<indexY;y++) {
            for(int x=0;x<indexX;x++) {
                cout << setw(2) << arr[z][y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    //очищение памяти
    for(int i=0; i<indexZ; i++) {
        for(int j=0; j<indexY;j++) {
            delete [] arr [i][j];
        }
    }
    
}
