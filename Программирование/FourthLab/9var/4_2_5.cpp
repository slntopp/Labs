#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main(){

    setlocale(LC_ALL, "");

    int count, i = 0;
    char* in_array = new char;
    char ch;
    cout << "Введите количество вашу строку и количество слов в вашей строке через точку с запятой(;):\n";
    while((ch = getchar()) != ';') in_array[i] = ch, ++i;
    cin >> count;

    for(int j = 0; j < i; ++j){
        
    }

    delete in_array;

    return 0;
}