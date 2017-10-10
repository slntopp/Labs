#include <iostream>
#include "slovo.h"
#include <string>
#include <cctype>

using namespace std;

istream& operator>> (istream& in, Slovo &obj){
    string str;
    getline(cin, str);
    obj.Set(str);
    return in;
}

bool IsXDigit(const Slovo &obj){
    bool result = true;
    for(int i = 0; i < obj.length(); ++i){
        result = result && isxdigit(obj.getch(i));
    }
    return result;
}

int main(){

    Slovo obj;
    cout << "������� ���� �����: ";
    cin >> obj;
    if(IsXDigit(obj)) cout << "�������� ����������������� ������" << endl;
    else cout << "�� �������� ����������������� ������" << endl;

    return 0;
}