#include <iostream>
#include "matrix.h"
#include "main2.cpp"

using namespace matrix; //����������� ����������� ������������� ���� ���������� � matrix.h
using namespace std;

int main(){
    int n;
    cout << "������� ������� �������: ";
    cin >> n;
    if (n <= 1){ //�������� �������� ������� �������
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    cout << "������� �������� ��������� �������:\n";
    double** matrix = new double*[n]; //���������� ������� ���������� �� ��������� �� double �������� n
    for (int i = 0; i < n; i++) //���������� ������� ���� double ��� ������� �� ���������� ����������� �������
    {
        matrix[i] = new double[n];
    }
    get_matrix(n, matrix); //����� ������� �� matrix.h ��� ��������� �������� �������
    cout << "���� ���������..." << endl;
    actions(n, matrix); //����� ������� �� ������� ������������ �����, ��� ���������� �������� ���������
    // put_matrix(n, matrix); //����� ����� ���� ����� �������, �� ������������ �������� put_matrix() �� matrix.h 
    
    delete[] matrix; //������������ ������ �� ��������� ������ ������������ � ��.

    return 0;
}