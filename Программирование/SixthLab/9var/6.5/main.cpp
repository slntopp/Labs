#include <iostream>
#include <cstdio>

using namespace std;

int second_circle_of_hell(int, int, char*, char*);

int main(){
    char *first = new char, *second = new char, ch;
    int f = 0, s = 0;
    cout << "Введите по порядку слова: из которого и какое нужно составить." << endl;
    while((ch = getchar()) != ' ') first[f++] = ch;
    while((ch = getchar()) != '\n') second[s++] = ch;
    cout << "Идет обработка..." << endl;
    bool cycle = true, inc = false;
    for(int i = 0; i < s; ++i){
        inc = false;
        for(int j = 0; j <= f; ++j){
            if(second[i] == first[j]){
                inc = true;
                break;
            }
        }
        cycle = cycle && inc;
        if(!cycle) break;
    }

    if(!cycle) cout << "Ничего не выйдет" << endl;
    else{
        cout << "Все гут" << endl;
        cout << "Начинаю проверку на составление без повторяющихся букв..." << endl;
        second_circle_of_hell(f, s, first, second);
    }

    return 0;
}

int second_circle_of_hell(int f, int s, char* first, char* second){
    bool cycle = true, inc = false;
    for(int i = 0; i < s; ++i){
        inc = false;
        for(int j = 0; j <= f; ++j){
            if(second[i] == first[j]){
                first[j] = '.';
                inc = true;
                break;
            }
        }
        cycle = cycle && inc;
        if(!cycle) break;
    }
    if(!cycle) cout << "Ничего не выйдет" << endl;
    else cout << "Все гут" << endl;

    return 0;
}