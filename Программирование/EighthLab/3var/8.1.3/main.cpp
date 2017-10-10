#include <iostream>
#include "ellipse.h"

using namespace std;

int main(){

    Ellipse obj(3,3);
    Ellipse obj1(5, 2);
    Ellipse obj2(5, 2);
    obj2.Resize(1.3);

    cout << obj << endl;
    cout << obj1 << endl;
    cout << obj2 << endl;

    return 0;
}