#include <iostream>
#include "vector.h"

using namespace std;

int main(){

    double *a = new double;
    a[0] = 666;
    Vector vect(1, a);

    int i = 0;

    cout << vect[i++] << " ";
    try {
        cout << vect[i] << endl;
    } catch(const VectException& e){
        cout << e.what();
        cout << vect[--i] << endl;
    }

    return 0;
}