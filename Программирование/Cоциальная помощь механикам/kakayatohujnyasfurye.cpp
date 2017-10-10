#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>

using namespace std;

const double PI = M_PI;

struct complex {
    char mult[8];
    float num[2];
};

void put_matrix(int, complex**);
complex newcomplex(int, int);

int main(){
    int n1, n2;
    cout << "Введите натуральные N1 и N2(N1 < N2): ";
    cin >> n1 >> n2;
    if(n1 < 1 || n2 < 1 || n1 == n2 || n1 > n2){
        cout << "Введенные данные не соответсвуют условию!" << endl;
        return main();
    }
    int n = n1 + rand()%(n2 - n1);

    cout << "Порядок матрицы: " << n << endl;

    complex** matrix = new complex*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new complex[n];
        for(int j = 0; j < n; ++j){
            matrix[i][j] = newcomplex(i*j, n);
        }
    }

    put_matrix(n, matrix);

    return 0;
}

void put_matrix(int n, complex **matrix){
        for(int i = 0; i < n; ++i){
            cout << "|";
            for(int j = 0; j < n; ++j){
                if(matrix[i][j].num[0] != 0) cout << setw(5) << setprecision(1) << matrix[i][j].num[0];
                else cout << "     ";
                if(matrix[i][j].num[1] == 0) cout << "     ";
                else if(matrix[i][j].num[1] == 1) cout << "i    ";
                else if(matrix[i][j].num[1] == -1) cout << "-i   ";
                else if(matrix[i][j].num[1] > 0) cout << "+i" << setprecision(1) << matrix[i][j].num[1];
                else if(matrix[i][j].num[1] < 0) cout << "-i" << setprecision(1) << abs(matrix[i][j].num[1]);
            }
            cout << "    |" << endl;
            if(i < n - 1){
                cout << "|";
                for(int k = 0; k < n; ++k){
                    cout << "          ";
                }
                cout << "    |" << endl;
            }
        }
}

complex newcomplex(int k, int n){
    complex res;
    float c = cos(2 * PI * k / n), s = sin(2 * PI * k / n);
    res.num[0] = ((c > 0.1 && c < 0.9) || (c < -0.1 && c > -0.9)) ? c : (c > 0.9 || (c > -0.1 && c < 0) ? abs(ceil(c)) : floor(c));
    res.num[1] = ((s > 0.1 && s < 0.9) || (s < -0.1 && s > -0.9)) ? s : (s > 0.9 || (s > -0.1 && s < 0) ? abs(ceil(s)) : floor(s));
     
    return res;
}