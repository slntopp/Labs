#include <iostream>
#include "money.h"

using namespace std;

int main(){
    
    Money obj;
    Money obj1(10.37);
    Money obj2(obj1);

    cout << "obj: " << obj << endl;
    cout << "obj1: " << obj1 << endl;
    cout << "obj2: " << obj2 << endl;
    cout << "obj + obj1 = " << obj + obj1 << "\t";
    cout << "obj2 - obj1 = " << obj2 - obj1 << "\t";
    cout << "obj1 * 1.5 = " << obj1 * 1.5 << "\t";
    cout << "obj2 / 1.5 = " << obj2 / 1.5 << "\t";

    return 0;
}