#include <iostream>
#include <cstdio>

using namespace std;

int first(); //Функция для вызова алгоритма решения первой задачи
int second(); //Функция для вызова алгоритма решения второй задачи

template <class user_type>
void put_matrix(int n, user_type **matrix); //Шаблон семейства функций для вывода матрицы

template <class user_type>
void swap(int, user_type**); //Шаблон семейства функции для выполнения перемещения квадратов матрицы

int main(){
    char ch;
    for(;;){ //Бесконечный цикл для пользовательского интерфейса
        cout << "Введите f для первого пункта задачи, s для второго, q для выхода..." << endl;
        cin >> ch;
        if(ch == 'f'){
            first();
            continue;
        }
        else if (ch == 's'){
            second();
            continue;
        }
        else if (ch == 'q') break;
        else continue;
    }

    return 0;
}

int first(){
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    char** main_arr = new char*[n];
    cout << "Введите значения элементов массива: " << endl;
    for(int i = 0; i < n; ++i){ //Коментарии по созданию и наполнению матрицы в предыдущих задачах
        main_arr[i] = new char;
        for(int j = 0; j < n; ++j)
            cin >> main_arr[i][j];
    }

    cout << endl;
    cout << "Ваш массив: | ";
    for(int j = 0; j < n; ++j){
        char tmp = main_arr[n - j - 1][j]; //Создание буфферной переменной для хранения текущего подходящего по заданию значения, сразу инициализируется
        for(int i = n - j - 1; i < n; ++i){ //значением элемента в текущем столбце на побочной диагонали
            if(main_arr[i][j] >= tmp && main_arr[i][j] % 3 == 0) tmp = main_arr[i][j]; //Проверка на кратность трем и "максимальность" значения
        }
        if(!(tmp % 3)) tmp = char(126); //В случае если ни одно значение не подойдет, проверяем, чтобы первое записанное значение было кратно трем
        cout << tmp << " "; //оно ведь по умолчанию будет максимально, и в обратном случае записываем в него 126(по усл.) & выводим
    }
    cout << "|" << endl;

    return 0;
}

int second(){
    cout << "Введите n(четное натуральное число): ";
    int n;
    cin >> n;
    if(n < 2 || n % 2 != 0){ //Проверяем величину и четность порядка матрицы
        cout << "Ошибочные данные!" << endl; //В случае неправильных данных возвращаем пользователя в меню
        return 0;
    }

    cout << "Введите значения элементов матрицы:" << endl;   
    int** matrix = new int*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new int[n];
        for(int j = 0; j < n; ++j) cin >> matrix[i][j];
    }
    swap(n / 2, matrix); //Вызываем функцию перемещения элементов, посылаем половину размера матрицы для удобства
    cout << endl;
    put_matrix(n, matrix); //Выводим матрицу соответсвующей функцией

    return 0;
}

template <class user_type>
void swap(int n, user_type** matrix){ //Функция перемещения элементов
    int tmp; //Создаем буфферную переменную
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            tmp = matrix[i][j]; //Записываем в нее значение текущего элемента
            matrix[i][j] = matrix[i + n][j]; //Записываем в него значение элемента лежащего на n ниже него(по условию)
            matrix[i + n][j] = tmp; //Записываем значение бефферной переменной в элемент лежащий на n нижего текущего
            tmp = matrix[i][j + n]; //По аналогии, только смещаемся вправо на n
            matrix[i][j + n] = matrix[i + n][j + n];
            matrix[i + n][j + n] = tmp;
        }
    }
}

template <class user_type>
void put_matrix(int n, user_type** matrix){
    for(int i = 0; i < n; ++i){
        cout << "| "; //Проходим по всей матрицы и выводим почленно, вставляя палки и перенос строки в нужных местах(критерий завершение цикла проходящего по строке)
        for(int j = 0; j < n; ++j) cout << matrix[i][j] << " ";
        cout << "|" << endl;
    }
}