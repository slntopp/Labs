#include <iostream>
#include <math.h>
 
using namespace std;
 
int main() {
    int x, y, k, l = 0;
    cout << "Введите координаты коня через пробел: ";
    cin >> x >> y;
    if (x > 8 | x < 1 | y > 8 | y < 1) {
        cout << "Заданы координаты превышающие размеры поля." << endl;
        main();
    }
    cout << "Введите координаты поля: ";
    cin >> k >> l;
    if (k > 8 | k < 1 | l > 8 | l < 1) {
        cout << "Заданы координаты превышающие размеры поля." << endl;
        main();
    }
 
    if ((abs(k - x) == 2 && abs(l - y) == 1) || (abs(l - y) == 2 && abs(k - x) == 1)) {
        cout << "Поле достигнуто за шаг." << endl;
    } else if ((abs(l - y) == 2 && (abs(k == x) || abs(k - x == 4)))
        || ((abs(l - y) == 3 || abs(l - y == 1)) && (abs(k - x) == 1 || abs(k - x) == 3))
        || (abs(l - y) == 1 && (abs(k - x) == 1 || abs(k - x) == 3))
        || (abs(l - y) == 0 && abs(k - x) == 4)
        || (abs(l - y) == 4 && abs(k - x) == 0)) {
        cout << "Конь достигнул поле за два шага." << endl;
    } else {
        cout << "Конь не достигнул поле." << endl;
    }

    return 0;
}