#include <iostream>
#include "vector.h"

using namespace std;

int main(){

    double *arr = new double[16];
    for(int i = 0; i < 16; ++i) arr[i] = i % 2 ? 1 : 0;

    Vector obj0(16, arr);
    Vector obj1(obj0);

    obj1 = obj1 * 2;

    cout << "Вектор 0: " << obj0 << endl;
    cout << "Вектор 1: " << obj1 << endl;
    cout << "Результат их скалярного умножения: " << obj0 * obj1 << endl;

    return 0;
}