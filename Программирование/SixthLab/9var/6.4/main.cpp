#include <iostream>
#include "sec.cpp"

using namespace std;

int smm(int a, int b){
    return (a + b) % 127;
}

int main(){
    cout << "Введите порядок матрицы: ";
    int n;
    cin >> n;    

    cout << "Введите элементы матрицы: " << endl;
    char** A = new char*[n];
    for(int i = 0; i < n; ++i){
        A[i] = new char[n];
        for(int j = 0; j < n; ++j){
            cin >> A[i][j];
        }
    }
    cout << "Результирующая матрица:\n\t";
    char* B = new char[n];
    for(int t = 0; t < n; ++t){
        int tmp = 0;
        for(int j = 0; j < n; ++j){
            if(j >= t) tmp = smm(tmp, A[t][j]);
        }
        B[t] = tmp > 37? char(tmp) : 126;
        cout << B[t] << " ";
    }
    cout << endl;
    cout << "Введите порядок матрицы(Четное число больше 2. Если будет введено нечетное, программа автоматически увеличит его на 1): ";
    cin >> n;
    if(n % 2 != 0) ++n;
    double** matrix = new double*[n];
    cout << "Введите значения матрицы:\n";
    for(int i = 0; i < n; ++i){
        matrix[i] = new double[n];
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    swap_main(n, matrix);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}