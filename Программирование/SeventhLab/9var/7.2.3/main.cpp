//Больше 10000 чисел не рекомендуется - виснет на стадии очистки

#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include <malloc.h>
#include <ctime>

using namespace std;

void mkfile();
void deletesame(int*, int*);
void move(int, int, int*);
void sort(int, int*);

int main(){
    int choice;
    cout << "Введите 0 для использования существующего файла и 1 для генерации собственного: ";
    cin >> choice;
    if(choice){
        mkfile();
    }

    int *numbers = (int*)malloc(0), len = 0; //Создан массив нулевой длины
    ifstream user_file("in.txt"); //Перенаправление потока ввода на файл
    while(!user_file.eof()){
        numbers = (int*)realloc(numbers, (len+1)*sizeof(int)); //Так как массив по итогу может быть большой-большой память выделяем динамически
        user_file >> numbers[len++]; //Запись чисел в массив до конца файла (eof - end of file)
    }
    fflush(stdin); //Очистка буффера ввода(можно не надо)
    user_file.close(); //Закрытие файла

    deletesame(&len, numbers); //Вызов функции очистки от трижды повторяющихся чисел(ахтунг говнокод)
    sort(len, numbers); //Сортировка по возрастанию

    ofstream outfile("out.txt");
    for(int i = len - 1; i >= 0; --i){
        if(numbers[i] <= 0 || numbers[i] > 9999) continue;
        outfile << numbers[i] << " ";
    }
    outfile.close();


    return 0;
}

void mkfile(){
    long int n;
    cout << "Введите количество чисел(от n = 10^9):";
    cin >> n;
    ofstream infile("in.txt");
    srand(time(0));
    for(long int i = 0; i < n; ++i){ //Заполнение рандомными числами
        infile << rand()%10000 << " ";
    }
    infile.close();
}

void deletesame(int* len, int* arr){
    cout << "Удаление одинаковых чисел..." << endl;
    bool rep = false;
    for(int i = 0; i < *len - 1; ++i){
        for(int j = i + 1; j < *len; ++j){
            if(arr[i] == arr[j] && rep){
                move(j, *len, arr);
                --*len;
            } else if(arr[i] == arr[j] && !rep) rep = true;
        }
    }
}

void move(int pos, int len, int* arr){ //Смещение массива с конца до заданной позиции
    for(int i = pos; i < len - 1; ++i){
        arr[i] = arr[i + 1];
    }
}

void sort(int len, int* arr){ //Дефолт сортировка выбором
    cout << "Начинаю сортировку..." << endl;
    int buf;
    for(int i = 0; i < len - 1; ++i){
        for(int j = i + 1; j < len; ++j){
            if(arr[i] > arr[j]){
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
        }
    }
}