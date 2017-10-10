#include <iostream>
#include <fstream> //Для работы с потоком
#include <ostream> //Для fflush()
#include <cstdio>
#include <cmath>

using namespace std;

void sign_sort(int, int*); //Функция сортировки

int main(){
    bool choice;
    cout << "Введите 1 для автоматической генерации чисел и 0 для ввода из файла: ";
    cin >> choice;
    int len = 0, *numbers = new int[16];
    if(choice){
        cout << "Введите количество чисел: ";
        cin >> len;
        for(int i = 0; i < len; ++i) numbers[i] = pow(-1, i) * rand();
    } else {
        ifstream user_file("num.txt"); //Перенаправление потока ввода на файл
        while(!user_file.eof()) user_file >> numbers[len++]; //Запись чисел в массив до конца файла (eof - end of file)
        fflush(stdin); //Очистка буффера ввода(можно не надо)
        user_file.close(); //Закрытие файла
    }

    sign_sort(len, numbers); //Вызов сортировщика

    ofstream out_file("out.txt"); //Перенаправление потока вывода в файл
    for(int i = 0; i < len; ++i){ //Наполнение файла
        out_file << numbers[i] << " ";
    }
    fflush(stdout); //Очистка буффера вывода(можно не надо)
    out_file.close(); //Закрытие файла
    
    delete[] numbers; //Очистка памяти

    return 0;
}

void sign_sort(int n, int* arr){
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[j] > 0){
                int buf = arr[j];
                arr[j] = arr[i];
                arr[i] = buf;
            }
        }
    }
}