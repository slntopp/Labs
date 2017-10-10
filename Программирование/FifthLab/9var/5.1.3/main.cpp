#include <iostream>
#include <windows.h>

using namespace std;

void stat_dots(){
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
    Sleep(600);
    cout << ".";
}

void statusbar(int sec){
    cout << "[#";
    Sleep(sec*100);
    cout << "###";
    Sleep(sec*500);
    cout << "########";
    Sleep(100);
    cout << "##";
    Sleep(100);
    cout << "####";
    Sleep(sec*500);
    cout << "###]" << endl;
}

int main(){
    int n;
    cout << "Введите n: ";
    cin >> n;

    double** matrix = new double*[32];
    cout << "Введите значения матрицы: " << endl;
    for(int i = 0; i < 2 * n; ++i){
        matrix[i] = new double[32];
        for(int j = 0; j < 2 * n; ++j){
            cin >> matrix[i][j];
        }
    }

    cout << "Идет перестановка";
    stat_dots();
    cout << endl;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            double tmp = matrix[i][j];
            matrix[i][j] = matrix[i + n][j + n];
            matrix[i + n][j + n] = tmp;
            tmp = matrix[i][j + n];
            matrix[i][j + n] = matrix[i + n][j];
            matrix[i + n][j] = tmp;
        }
    }

    cout << "Подготовка к выводу: ";
    statusbar(10);

    for(int i = 0; i < 2 * n; ++i){
        for(int j = 0; j < 2 * n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}