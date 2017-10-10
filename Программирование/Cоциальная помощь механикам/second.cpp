#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

void Fib(int first, int last, int N);

int main(){
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "¬ведите N: ";
    cin >> N;

    Fib(1, 1, N);
}

void Fib(int first, int last, int N){
    int sum = first + last, second = last;
    for(int i = 0; i <= N; ++i){
        last = first + second;
        first = second;
        second = last;
        sum += last;
    }
    cout << N << "-ый член равен: " << last << endl;
    cout << "—умма членов: " << sum << endl;
}