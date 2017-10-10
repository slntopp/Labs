#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

#include "addons.cpp"

int main(){

    char ch, **cities, **times;
    int *numbers, *numbers_cpy;
    cities = new char*[1000];
    times = new char*[1000];
    numbers = new int[1000];
    numbers_cpy = new int[1000];
    int len = 0;
    menu();
    while((ch = getchar()) != 'q'){
        if(ch == '1') { len += file_read(cities, times, numbers, numbers_cpy, len); continue; }
        else if(ch == '2') { print(cities, times, numbers, numbers_cpy, len); continue; }
        else if(ch == '3') { file_write(cities, times, numbers, numbers_cpy, len); continue; }
        else if(ch == '4') { sort(numbers_cpy, len); continue; }
        else if(ch == '5') { read(cities, times, numbers, numbers_cpy, len++); continue; }
        else if(ch == '6') { system("cls"); menu(); continue; }
        else if(ch == '7') cout << len << endl;
    }

    return 0;
}