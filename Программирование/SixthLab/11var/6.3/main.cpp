#include <iostream>
#include <iomanip>

using namespace std;

void make_null_matrix(int n, double** matrix); //������� ����� ��������� ������� ������
void put_matrix(int n, double** matrix); //����� �������
long int fact(int x); //������� ����������
template <class user_type> //���������� ������� ��������� �������
void fill_matrix(int n, double** matrix, user_type k); //�������, ������� �������� �������� ��� ���������� �������,
//�� ������� ���

int main(){
    int n; double k;
    cout << "������� ������� ������� � k ����� ������: "; //��� ������
    cin >> n >> k;
    if (n <= 1){
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) matrix[i] = new double[n]; //�� ���� ��� ����� ���������� � 6.2
    make_null_matrix(n, matrix); //��������� ��������� ���� ������� ������
    fill_matrix(n, matrix, k); //��������� �������� ��� ��� ����
    put_matrix(n, matrix); //������� �������

    return 0; //�����������
}

long int fact(int x){ //��������� ��� ������ ��������� � 6 ������������?
    long int result = 1;
    if(x == 0) return 1;
    for(long int i = 1; i <= x; ++i) result *= i;
    return result;
}

void make_null_matrix(int n, double** matrix){ //�������� �� ���� ��������� ������� � ������������ �� � ����
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) matrix[i][j] = 0;
}

template <class user_type>
void fill_matrix(int n, double** matrix, user_type k){ //�������� �� ��������� �������� ��� � ������������ �� � ����� ����������� �� ������� �����
    for(int i = 0; i < n; ++i){
        matrix[i][n - i - 1/*��� ��� ����� ��� �������� ���, �������*/] = (n - i) * k / fact(i); //��� ��� ������� ��
    }
}

void put_matrix(int n, double **matrix){ //�������� �� ���� ��������� � ������� ��(�� �����������) � ����� ������� ����� �������
    for(int i = 0; i < n; ++i){ //� � ���� �������� 9 ������ � ����� "|" ������ ����� � ����� ������ �������
        cout << "|";
        for(int j = 0; j < n; ++j) cout << setprecision(3) << setw(9) << matrix[i][j];
            cout << "|" << endl;
    }
}