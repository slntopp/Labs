#include <iostream>
#include "stack.h"

using namespace std;

int main(){

    Stack obj;
    obj.Push("��������", "����", "����������", 18, 1, 1, 9.9);
    cout << "Push" << endl;
    obj.Push("������", "�����", "����������", 17, 0, 0, 227);
    obj.Push("���", "��", "�������", 18, 0, 1, 5.5);

    cout << obj.GetName() << endl;
    obj.Pop();
    cout << obj.GetName() << endl;
    obj.Pop();
    cout << obj.GetName() << endl;
    

    return 0;
}