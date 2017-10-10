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

int main(){
    int n;
    cout << "Введите порядок матрицы: ";
    cin >> n;

    cout << "Введите значения матрицы:" << endl;
    char** matrix = new char*[32];
    for(int i = 0; i < n; ++i){
        matrix[i] = new char[32];
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }

    cout << "Идет сверка";
    stat_dots();
    cout << endl;

    int* count = new int;
    for(int j = 0; j < n; ++j){
        count[j] = 0;
        for(int i = 0; i < n; ++i){
            for(int i1 = i; i < n; ++i){
                if(matrix[i][j] != matrix[i1][j]) ++count[j];
            }
        }
    }
    cout << "Победитель определен, торжественный вывод в stdin его имени уже через 3 секунды!" << endl;
    Sleep(3000);
    int result = count[0];
    for(int j = 1; j < n; ++j) if(count[j] >= result) result = count[j];
    cout << "Ииии самый разнообразный столбец сегодня под номером ";
    Sleep(2000);
    cout << result + 1 << "!" << endl;

    return 0;
}