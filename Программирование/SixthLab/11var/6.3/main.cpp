#include <iostream>
#include <iomanip>

using namespace std;

void make_null_matrix(int n, double** matrix); //Функция будет заполнять матрицу нулями
void put_matrix(int n, double** matrix); //Вывод матрицы
long int fact(int x); //Функция факториала
template <class user_type> //Объявление шаблона семейства функций
void fill_matrix(int n, double** matrix, user_type k); //Функция, которая заполнит побочную ось требуемыми числами,
//по заданию крч

int main(){
    int n; double k;
    cout << "Введите порядок матрицы и k через пробел: "; //Вот отсюда
    cin >> n >> k;
    if (n <= 1){
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) matrix[i] = new double[n]; //До сюда все можно посмотреть в 6.2
    make_null_matrix(n, matrix); //Заполняем созданную выше матрицу нулями
    fill_matrix(n, matrix, k); //Заполняем побочную ось чем надо
    put_matrix(n, matrix); //Выводим матрицу

    return 0; //Завершаемся
}

long int fact(int x){ //Объяснять как искать факториал к 6 лабораторной?
    long int result = 1;
    if(x == 0) return 1;
    for(long int i = 1; i <= x; ++i) result *= i;
    return result;
}

void make_null_matrix(int n, double** matrix){ //Проходим по всем жлементам матрицы и приравниваем их к нулю
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) matrix[i][j] = 0;
}

template <class user_type>
void fill_matrix(int n, double** matrix, user_type k){ //Проходим по элементам побочной оси и приравниваем их к числу полученному по формуле снизу
    for(int i = 0; i < n; ++i){
        matrix[i][n - i - 1/*Это вот штука для побочной оси, погугли*/] = (n - i) * k / fact(i); //Вот эта формула да
    }
}

void put_matrix(int n, double **matrix){ //Проходим по всем эдементам и выводим их(по возможности) с тремя знаками после запятой
    for(int i = 0; i < n; ++i){ //и в поле размером 9 знаков с такой "|" штукой после и перед каждой строкой
        cout << "|";
        for(int j = 0; j < n; ++j) cout << setprecision(3) << setw(9) << matrix[i][j];
            cout << "|" << endl;
    }
}