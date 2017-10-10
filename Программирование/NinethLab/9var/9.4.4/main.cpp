#include <iostream>
#include "list.h"

using namespace std;

int main(){

    List <>obj;
    List <>obj1;

    for(int j = 0; j < 3; ++j)
        for(int i = 0; i < 7; ++i) obj.Push(i);
    
    for(int i = 0; i < 6; ++i) obj1.Push(i);


    cout << "Исходный список: " << obj << endl;
    cout << "\nКакой-то другой список: " << obj1 << endl;

    RmSubList(obj, obj1);

    cout << "\nРезультат удаления из первого списка всех вхождений второго: " << obj << endl;
    

    return 0;
}