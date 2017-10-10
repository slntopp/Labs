#include <iostream>

using namespace std;

namespace matrix {
    void get_matrix(int n, double **matrix){
        for(int i = 0, j = 0;; j++){
            if(j == n) j = 0, i++;
            if(i == n) break;
            cin >> matrix[i][j];
        }
    }
    void put_matrix(int n, double **matrix){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};