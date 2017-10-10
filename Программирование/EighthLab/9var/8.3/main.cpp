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
    cout << "¬ведите ваше слово: ";
    cin >> obj;
    if(IsXDigit(obj)) cout << "явл€етс€ шестнадцатиричным числом" << endl;
    else cout << "Ќе €вл€етс€ шестнадцатиричным числом" << endl;

    return 0;
}