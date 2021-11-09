//
//  main.cpp
//  lab5
//
//  Created by Артём Скрипкин on 09.11.2021.
//

#include <iostream>
using namespace std;

int main() {
    cout << "enter m: ";
    int m;
    cin >> m;
    cout << endl;
    double a[m][m];
    
    //filling array(creating matrix)
    for(int i=0; i< m; i++) {
        for(int j=0; j<m;j++) {
            a[i][j] = rand()%10+1;
            //printing values as matrix
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //replacing values in matching indexes
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < i; ++j) {
            a[i][j] = 0;
        }
    }
    
    //printing matrix
    for (int i=0; i < m ;i++){
        for (int j=0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
