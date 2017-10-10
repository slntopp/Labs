#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

void binary(double num);
void binary_pole(unsigned char num);

int main(){
    char ch;
    cout << "Для выхода введите q, для вывода представления вещественного числа 1, а для long 2..." << endl;    
    while((ch = getchar()) != 'q'){
        if(ch == '1'){
            double user_num;
            cout << "Введите ваше число: ";
            cin >> user_num;
            binary(user_num);
        } else if (ch == '2') {
            long user_num;
            cout << "Введите ваше число: ";
            cin >> user_num;
            binary_pole(user_num);
        } else {
            cout << "Для выхода введите q, для вывода представления вещественного числа 1, а для long 2..." << endl;
        }   
    }

    return 0;
}

void binary(double num){
    union {
        double inner_num;
        unsigned char out[sizeof(double)];
    } bytes;

    bytes.inner_num = num;
    for( int j = sizeof(double) - 1; j >= 0; --j){
        cout << "Двоичное представление байта " << j << ": ";
        for(int i = 128; i; i >>= 1){
            if(i & bytes.out[j]) cout << "1";
            else cout << "0";
            cout << " ";
        }
        cout << endl;
    }
}

void binary_pole(unsigned char num){
    union {
        unsigned char out;
        struct {
            unsigned b0:1;
            unsigned b1:1;
            unsigned b2:1;
            unsigned b3:1;
            unsigned b4:1;
            unsigned b5:1;
            unsigned b6:1;
            unsigned b7:1;
        } byte;
    } bytes;

    bytes.out = num;
    cout << setw(15) << "Номер бита:    " << "7-6-5-4-3-2-1-0" << endl;
    cout << setw(14) << "Значение бита: " << bytes.byte.b7 << " " << bytes.byte.b6 << " " << bytes.byte.b5 << " " << bytes.byte.b4 << " " << bytes.byte.b3 << " " << bytes.byte.b2 << " " << bytes.byte.b1 << " " << bytes.byte.b0 << endl;
}