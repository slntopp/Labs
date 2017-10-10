#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <ctime>

using namespace std;

int main(){

    int n, m;
    cout << "Введите размер для первого и второго массива через пробел: ";
    cin >> n >> m;
    if(n > 1000 || n <= 0 || m > 1000 || m <= 0){
        cout << "Размер не должен превышать 1000." << endl;
        main();
        return 0;
    }
    srand(time(0));    
    int *first_arr = new int[4];
    for(int i = 0; i < n; ++i){
        first_arr[i] = 1 + rand()%10;
    }
    cout << "Первый массив сгенерирован!" << endl;

    int *result_arr = new int[4];
    for(int i = 0; i < n; ++i){
        result_arr[i] = first_arr[i];
    }
    delete []first_arr;    

    int *second_arr = new int[4];
    for(int i = 0; i < m; ++i){
        second_arr[i] = 1 + rand()%10;
    }
    cout << "Второй массив сгенерирован!" << endl;    
    for(int i = n; i < m + n; ++i){
        result_arr[i] = second_arr[i - n];
    }
    cout << "Общий массив сгенерирован!" << endl;
    delete []second_arr;
    unsigned long result = 0;
    for(int i = 0; i < (m + n - 3); ++i){
        if(i % 2 && result_arr[i] % 2) result += result_arr[i];
    }
    delete []result_arr;

    cout << "Результат: " << endl;
    cout << result << endl;

    return 0;
}