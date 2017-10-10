#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    const int M = 7;
    int m;
    cout << "Введите значение порядка: ";
    cin >> m;

    srand(time(0));

    int matrix[M][M], Sum = 0;
    for(int i = 0; i < m; ++i){
        cout << "|";
        for(int j = 0; j < m; ++j){
            matrix[i][j] = -8 + (rand() % 16 );
            if(matrix[i][j] >= 0) cout << " ";
            cout << " " << matrix[i][j];
            Sum += matrix[i][j];
        }
        cout << " |" << endl;
    }

    cout << endl;

    for(int i = 0; i < m; ++i){
        int mid = 0, sum = 0;
        for(int j = 0; j < m; ++j){
            mid += matrix[i][j];
        }
        mid /= m;
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] > mid) sum += matrix[i][j];
        }
        cout << "Среднее значение ряда " << i + 1 << ": " << mid << ", сумма элементов выше среднего: " << sum << endl;
    }

    cout << endl;

    cout << "Сумма всех элементов: " << Sum << endl;

    return 0;
}