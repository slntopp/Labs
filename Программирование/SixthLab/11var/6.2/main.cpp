#include <iostream>
#include "matrix.h"
#include "main2.cpp"

using namespace matrix; //Подключение обственного простраснства имен введенного в matrix.h
using namespace std;

int main(){
    int n;
    cout << "Введите порядок матрицы: ";
    cin >> n;
    if (n <= 1){ //Проверка величины порядка матрицы
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    cout << "Введите значения элементов матрицы:\n";
    double** matrix = new double*[n]; //Объявление массива указателей на указатели на double размером n
    for (int i = 0; i < n; i++) //Объявление массива типа double для каждого из указателей предыдущего массива
    {
        matrix[i] = new double[n];
    }
    get_matrix(n, matrix); //Вызов функции из matrix.h для получения значений матрицы
    cout << "Идет обработка..." << endl;
    actions(n, matrix); //Вызов функции из второго программного файла, для выполнения треуемых подсчетов
    // put_matrix(n, matrix); //Здесь может быть вывод матрицы, он предусмотрен функцией put_matrix() из matrix.h 
    
    delete[] matrix; //Освобождение памяти во избежание ошибок переполнения и тп.

    return 0;
}