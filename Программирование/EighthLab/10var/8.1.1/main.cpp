#include <iostream>
#include <cstdlib>

using namespace std;

#include "atm.h"

int main(){
    ATM atm("#0001"); //�������� ������� � ��������������� ������� #0001
    atm.PutMoney(500); //�������� 500-� ������ � ��������
    getchar(); //��� �������� �������� ������ ���������
    atm.GetMoney(5); //������� ��������� 5 ������ �� ���������
    getchar();
    atm.GetMoney(15); //15-�� ������
    getchar();
    atm.GetMoney(450); //450-�� ������
    getchar();
    atm.GetMoney(300); //300-� ������
    getchar();
    atm.GetMoney(300); //300-� ������
    cout << "������� � ���������: " << atm.toString() << endl;
    return 0;
}