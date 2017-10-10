#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

char ToLower(char in);
char ToLower(char in, bool *isupper);
char ToUpper(char in);
void remove(int pos, int &len, char* in);
void alphout(int len, string *in);
void chainout(int len, string *in);

int main(){
    
    FILE *text = fopen("text.dat", "r");
    char *instring = new char[1000];

    fgets(instring, 1000, text);
    
    int length = 0;
    while(instring[length++] != NULL);
    
    cout << "Âõîäíîé òåêñò(" << length << "ñèìâ.):" << endl;
    puts(instring);

    string *words = new string[500];
    char *pch = strtok(instring, " ,.-—:;()");
    length = 0;
    while(pch != NULL){
        words[length++] = pch;
        pch = strtok(NULL, " ,.-—:;()«»");
    }

    cout << length << endl;

    alphout(length, words);
    chainout(length, words);

    delete[] instring, pch;
    fclose(text);
    return 0;
}

void alphout(int len, string *in){
    cout << endl << "Òîò æå òåêñò â àëôàâèòíîì ïîðÿäêå: " << endl;
    for(int j = 0; j < len; ++j){
        bool key = true;
        for(int i = 0; i < len - j; ++i){
            if(int(ToLower(in[i][0])) > int(ToLower(in[i + 1][0]))){ swap(in[i], in[i + 1]); }
            key = false;
        }
        if(key) break;
    }
    for(int i = 0; i < len; ++i){
        cout << in[i] << " ";
    }
}

void chainout(int len, string *in){
    cout << endl << "Òîò æå òåêñò â öåïî÷êå: " << endl;
    string eq;
    for(int i = 0; i < len - 2; i += 2){
        eq = in[i + 1];
        for(int j = i + 1; j < len; ++j){
            if(in[j][0] == in[i][in[i].length() - 1]){ swap(in[i + 1], in[j]); break; }
        }
        if(eq == in[i + 1]) --i; 
    }    
    for(int i = 0; i < len; ++i) cout << in[i] << " ";
    cout << endl;
}

void remove(int pos, int &len, char* in){
    for(int i = pos; i < len - 1; ++i){
        in[i] = in[i+1];
    }
    --len;
}

char ToLower(char in, bool *isupper){
    char upper[33] = {"ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÚÝÞß"};
    char lower[33] = {"àáâãäe¸æçèéêëìíîïðñòóôõö÷øùüúýþÿ"};
    for(int j = 0; j < 32; ++j){
        if(in == upper[j]) in = lower[j], *isupper = true; 
    }
    return in;
}

char ToLower(char in){
    char upper[33] = {"ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÚÝÞß"};
    char lower[33] = {"àáâãäe¸æçèéêëìíîïðñòóôõö÷øùüúýþÿ"};
    for(int j = 0; j < 32; ++j){
        if(in == upper[j]) in = lower[j]; 
    }
    return in;
}

char ToUpper(char in){
    char upper[33] = {"ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÜÚÝÞß"};
    char lower[33] = {"àáâãäe¸æçèéêëìíîïðñòóôõö÷øùüúýþÿ"};
    for(int i = 0; i < 32; ++i){
        if(in == lower[i]) in = upper[i]; 
    }
    return in;
}