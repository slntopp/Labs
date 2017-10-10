#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){

    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    int *m_arr = new int;
    srand(time(0));
    for(int i = 0; i < n; ++i){
        m_arr[i] = rand()%
    }

    return 0;
}