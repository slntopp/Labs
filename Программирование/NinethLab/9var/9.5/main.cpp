#include <iostream>
#include "matrix.h" 

using namespace std;

void Show(int n, Matrix<int> **arr);

int main(){

    Matrix <int>m0(3, 3);
    Matrix <int>m1(3, 3);
    Matrix <int>m2(3, 3);

    m0.Set(1), m1.Set(1);
    m2 = m0 + m1;
    Matrix<int> **m_arr = new Matrix<int>*[3];
    m_arr[0] = &m0, m_arr[1] = &m1, m_arr[2] = &m2;

    Show(3, m_arr);

    return 0;
}

void Show(int n, Matrix<int> **arr){
    for(int i = 0; i < n; ++i){
        cout << *arr[i] << endl;
    }
}