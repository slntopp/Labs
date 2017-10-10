#include <iostream>
#include <cstdio>

using namespace std;

void the_most_cool_array_printer_motherfucker(int, int*, char**);
bool compare(int, char*, char*);
bool second_circle_of_hell(int f, int s, char* first, char* second);

int main(){
    cout << "¬ведите вашу строку:" << endl;
    char **user_string = new char*[16], ch;
    int *length = new int, size = 0;    

    do{
        user_string[size] = new char;
        scanf("%16s", user_string[size++]);
        ch = getchar();
    } while(ch != '\n');
    
    for(int i = 0; i < size; ++i){
        length[i] = 0;
        for(;;++length[i])
            if(user_string[i][length[i]] == '\0' || user_string[i][length[i]] == ' '){
                user_string[i][length[i]] = '\0';
                break;
            }
    }

    for(int i = 0; i < size - 1; ++i){
        for(int j = i + 1; j < size; ++j){
            if(length[i] == length[j]){
                if(compare(length[i], user_string[i], user_string[j])) length[i] = 0, user_string[i][0] = '\0';
            }
        }
    }

    the_most_cool_array_printer_motherfucker(size, length, user_string);

    return 0;
}

void the_most_cool_array_printer_motherfucker(int size, int* length, char** string){
    bool space = true;
    for(int i = 0; i < size; ++i){
        if(string[i][0] == '\0') continue;
        for(int j = 0; j < length[i]; ++j){
            cout << string[i][j];
        }
        cout << " ";
    }
}

bool compare(int length, char* first, char* second){
    bool cycle = true, inc;
    for(int i = 0; i < length; ++i){
        inc = false;
        if(first[i] == second[i]) inc = true;
        cycle = cycle && inc;
        if(!cycle) break;
    }
    if(cycle) return true;
    if(second_circle_of_hell(length, length, first, second)) return true;

    return false;
}

bool second_circle_of_hell(int f, int s, char* first, char* second){
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
    if(!cycle) return false;
    else return true;

    return 0;
}