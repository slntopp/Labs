#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int p;
    cout << "Введите p: ";
    cin >> p;

    int m_arr[1024];
    for(int i = 0; i < p; ++i){
        m_arr[i] = -100 + rand()%200;
    }
    int up = 0;
    for(int k = 0; k < p; ++k){
        up += m_arr[k];
    }
    cout << "Простое скользящее среднее массива ";/* << endl << "[";
    for(int i = 0; i < p - 1; ++i){
        cout << m_arr[i] << ",";
    }
    cout << m_arr[p - 1]<< "]" << endl;*/
    double res = (up + 0.0) / (2 * p + 1);
    cout << "равно: " << res << endl;

    return 0;
}