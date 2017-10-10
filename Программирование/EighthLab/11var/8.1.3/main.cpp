#include <iostream>
#include "rhombus.h"

using namespace std;

int main(){

    Rhombus obj;
    cin >> obj;
    cout << "���������� " << obj.GetName() << ":" << endl;
    cout << obj << endl;

    Rhombus obj1(obj);
    cout << "���������� " << obj1.GetName() << " ������������� " << obj.GetName() << ":" << endl;
    obj1.OXSymmetry();
    cout << obj1 << endl;

    cout << "�������� ����� ������� ��������� " << obj.GetName() << ": " << obj.GetSD() << endl;

    return 0;
}