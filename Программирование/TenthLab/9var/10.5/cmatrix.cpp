#include <iostream>
#include "cmd.h"
#include <cmath>
#include <ctime>

using namespace std;

int main(){

    const char *symbols = "q w e r t y u i o p asdfghjkl zxcvbnm < > ? ! @ # $ % ^ & ~ 123 456 789 0 יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏";
    int range = strlen(symbols);

    SetColor(LightGreen, Black);

    srand(time(0));

    for(int i = 0;i < 100000000; ++i){
        if(rand() % 15 == 2){
            SetColor(LightBlue, Black);
            cout << symbols[rand() % range];
            SetColor(LightGreen, Black);
        }
        if(rand() % 15 == 3){
            SetColor(LightMagenta, Black);
            cout << symbols[rand() % range];
            SetColor(LightGreen, Black);
        }
        cout << symbols[rand() % range];
        if(i % 100 == 0) Sleep(25);
    }

    SetColor(White, Black);

    return 0;
}