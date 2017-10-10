#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;

void MassCenter(Vector &x, Vector &y); //������ ��������� ������ ����

int main(){

    cout << "������� n: ";
    int n; //������ ���������� �����
    cin >> n;
    Vector x(n), y(n); //�������� ���� �������� (���) ������ n
    for(int i = 0; i < n; ++i){
        cout << "������� x" << i << " � �" << i << " ����� ������: "; //������ ����� ���������
        cin >> x[i] >> y[i];
    }

    MassCenter(x, y); //����� ������� ������ ��������� ������ ����

    return 0;
}

void MassCenter(Vector &x, Vector &y){
    double xi = 0, yi = 0, d = 0; //��������� �� ������� � ������� ��� �����, �������; ����������� �� �������
    for(int i = 0; i < x.size(); ++i){
        xi += (i * x[i]); //���������� �������� �� �������
        yi += (i * y[i]);
        d += i; //��. �������
    }
    cout << setprecision(3) << "���������� ������ ����: M(" << xi / d << "," << yi / d << ")" << endl; //����� ��������� � ����������� ����� ����� ������� = 3
}