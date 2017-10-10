#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){

    int k;
    cout << "¬ведите k: ";
    cin >> k;
    if(k < 1){
        cout << "k > 0" << endl;
        main();
        return 0;
    }

    char *text = new char, ch;
    bool in = true;
    int i = 0;
    while((ch = getchar()) != '\n'){
        if(ch == '.' || ch == '!' || ch == '?') in = false;
        else if(in) text[i] = ch, ++i;
    }
    text[i] = '\0';

    int l = 0;
    for(int j = 0; j < i; ++j){
        while(text[l+j] != ' ' || text[j+l] != '\0') ++l;
        if(l < k)
            for(int n = j; n < j+l; ++n) cout << text[n];
        cout << endl;
        l = 0;
    }

    return 0;

}