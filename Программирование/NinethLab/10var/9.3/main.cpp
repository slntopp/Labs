#include <iostream>
#include <vector>
#include <algorithm> //��� ������� sort
#include "addons.cpp"

using namespace std;

int main(){

    int len;
    cout << "������� ����� ������� � ��� ��������: ";
    cin >> len;
    vector<int> vect(len); //������� ������ ������� len
    cin >> vect; //��������� ������ ���������� � ����������
    cout << "��������� ������: " << vect << endl;

    sort(vect.begin(), vect.end()); //���������� �� �����������

    cout << "��������������� ������: " << vect << endl;

    return 0;
}