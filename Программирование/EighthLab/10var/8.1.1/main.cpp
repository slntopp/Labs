#include <iostream>
#include <cstdlib>

using namespace std;

#include "atm.h"

int main(){
    ATM atm("#0001"); //Создание объекта с индификационным номером #0001
    atm.PutMoney(500); //Загрузка 500-а рублей в банкомат
    getchar(); //Для удобства проверки работы программы
    atm.GetMoney(5); //Попытка получение 5 рублей из банкомата
    getchar();
    atm.GetMoney(15); //15-ти рублей
    getchar();
    atm.GetMoney(450); //450-ти рублей
    getchar();
    atm.GetMoney(300); //300-а рублей
    getchar();
    atm.GetMoney(300); //300-а рублей
    cout << "Остаток в банкомате: " << atm.toString() << endl;
    return 0;
}