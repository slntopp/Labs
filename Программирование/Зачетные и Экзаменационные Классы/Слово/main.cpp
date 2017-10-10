#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#include "word.h"

int main(){

    Word obj1;
    Word obj("Heil");
    Word obj2(obj);


    cin >> obj1; // >> Hitler!
    cout << obj1 << endl;
    cout << obj1.length() << endl;

    cout << obj + obj1 << endl;

    obj.Push('!');
    cout << obj << endl;
    obj.Push("Hitler!");
    cout << obj << endl;

    return 0;
}