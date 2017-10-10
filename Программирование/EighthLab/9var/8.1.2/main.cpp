#include <iostream>
#include <string>
#include "slovo.h"

using namespace std;

void sort(Slovo obj);
void choicesSort(char*, int);

int main(){

    cout << "Enter your word: ";
    string str;
    cin >> str;
    Slovo obj(str);
    sort(obj);

    obj.Push('ç');
    cout << obj << endl;

    return 0;
}

void sort(Slovo obj){
    char *str = new char[32];
    for(int i = 0; i < obj.length(); ++i) str[i] = obj.getch(i);

    for(int j = 0; j < obj.length(); ++j){
        int key = 0;
        for(int i = 0; i < obj.length() - j; ++i){
            if(int(str[i]) > int(str[i + 1])) swap(str[i], str[i + 1]);
            key = 1;
        }
        if(key == 0) break;
    }

    Slovo obj_one(str);
    cout << obj_one << endl;
}