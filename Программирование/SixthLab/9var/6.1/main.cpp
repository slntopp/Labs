#include <iostream>

using namespace std;

int main(){
    int a;
    cout << "Введите А большее одного: ";
    cin >> a;
    if(a <= 1){
        main();
        return 0;
    }
    double result = 0, k = 0;
    for(;;){
        if(result >= a) if(k >= result) break;
        result += (1 / ++k);
    }
    cout << "Сумма равна: " << result << endl << "К равно: " << k << endl;

    return 0;
}