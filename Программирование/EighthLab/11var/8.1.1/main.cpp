#include <iostream>
#include "goods.h"

using namespace std;

int main(){

    Goods obj;
    Goods obj1("2007", 010107, 0, 0, 0000001);

    obj1.Add(3);
    obj1.SetPrice(2.22);
    cout << obj1.Price() << endl;
    Goods obj2(obj1);
    cout << obj2.toString() << endl;

    return 0;
}