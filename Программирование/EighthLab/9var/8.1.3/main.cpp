#include <iostream>
#include <cstdio>
#include "classes.h"

using namespace std;

int main(){

    Square obj(3, 2, 4), obj1(-3, -5, 7);
    cout << obj << endl << obj1 << endl;

    obj.MoveToY();
    obj1.MoveToY();
    
    cout << "------------------------------\nИсходные квадраты после перемещения к оси OY: " << endl << obj << endl << obj1 << endl;

    getchar();

    return 0;
}