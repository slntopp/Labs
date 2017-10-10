#include <iostream>
#include "stack.h"

using namespace std;

int main(){

    Stack obj;
    obj.Push("Тестовый", "Тест", "Коммитович", 18, 1, 1, 9.9);
    cout << "Push" << endl;
    obj.Push("Мастер", "Ветка", "Гитхабовна", 17, 0, 0, 227);
    obj.Push("Сам", "Ню", "Профайл", 18, 0, 1, 5.5);

    cout << obj.GetName() << endl;
    obj.Pop();
    cout << obj.GetName() << endl;
    obj.Pop();
    cout << obj.GetName() << endl;
    

    return 0;
}