#include <iostream>
#include "vector.h"

using namespace std;

int main(){

    Vector<int> iobj(5);
    iobj.Fill(1);
    Vector<double> dobj(5);
    dobj.Fill(2.02);
    cout << iobj << endl;
    cout << dobj << endl;
    Vector<int> siobj(iobj);
    iobj = iobj + siobj;
    cout << iobj << endl;

    return 0;
}