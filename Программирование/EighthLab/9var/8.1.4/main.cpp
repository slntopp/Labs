#include <iostream>
#include "triangle.h"
#include <cstdio>

using namespace std;

int main(){

    Point a(1,1), b(3,3), c(5, 1);
    Triangle obj(a, b, c);
    cout << obj << " - Центр: " << obj.GetCenter() << " - Расстояние до O(0,0): " << obj.GetDistance() << endl;
    
    obj = obj.MoveX(1);
    cout << obj << " - Центр: " << obj.GetCenter() << " - Расстояние до O(0,0): " << obj.GetDistance() << endl;
    obj = obj.MoveY(1);
    cout << obj << " - Центр: " << obj.GetCenter() << " - Расстояние до O(0,0): " << obj.GetDistance() << endl;
    
    cout << "В полярных координатах: " << endl;
    char dots[3] = {'A', 'B', 'C'};
    PolePrint(obj, dots);

    Triangle obj1(a, b, c), obj2(obj);
    if(obj == obj1) cout << "Первый и второй треугольники совпадают" << endl;
    else cout << "Первый и второй треугольники не совпадают" << endl;

    if(obj2 == obj) cout << "Первый и второй треугольники совпадают" << endl;
    else cout << "Первый и второй треугольники не совпадают" << endl;

    return 0;
}