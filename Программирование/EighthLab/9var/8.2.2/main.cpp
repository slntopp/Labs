#include <iostream>
#include "vector.h"

using namespace std;

int main(){

    int iarray[8];
    double *darray = new double[8];
    for(int i = 0; i < 8; ++i) iarray[i] = i*i, darray[i] = (i*i+1)/(i+3);
    Vector <double> dvector(8);
    Vector <double> dvector2(8, darray);
    Vector <int> ivector(64, iarray);

    cout << ivector[1] << endl;
    ivector = ivector + 5;
    cout << ivector[1] << endl;
    ivector = ivector * 2;
    cout << ivector[1] << endl;

    ivector.Print();

    return 0;
}