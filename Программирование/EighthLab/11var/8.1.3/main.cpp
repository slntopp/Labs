#include <iostream>
#include "rhombus.h"

using namespace std;

int main(){

    Rhombus obj;
    cin >> obj;
    cout << "Координаты " << obj.GetName() << ":" << endl;
    cout << obj << endl;

    Rhombus obj1(obj);
    cout << "Координаты " << obj1.GetName() << " симметричного " << obj.GetName() << ":" << endl;
    obj1.OXSymmetry();
    cout << obj1 << endl;

    cout << "Значение длины меньшей диагонали " << obj.GetName() << ": " << obj.GetSD() << endl;

    return 0;
}