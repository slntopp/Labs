#include <iostream>
#include <cstdio>

using namespace std;

int first(); //������� ��� ������ ��������� ������� ������ ������
int second(); //������� ��� ������ ��������� ������� ������ ������

template <class user_type>
void put_matrix(int n, user_type **matrix); //������ ��������� ������� ��� ������ �������

template <class user_type>
void swap(int, user_type**); //������ ��������� ������� ��� ���������� ����������� ��������� �������

int main(){
    char ch;
    for(;;){ //����������� ���� ��� ����������������� ����������
        cout << "������� f ��� ������� ������ ������, s ��� �������, q ��� ������..." << endl;
        cin >> ch;
        if(ch == 'f'){
            first();
            continue;
        }
        else if (ch == 's'){
            second();
            continue;
        }
        else if (ch == 'q') break;
        else continue;
    }

    return 0;
}

int first(){
    int n;
    cout << "������� ������ �������: ";
    cin >> n;
    char** main_arr = new char*[n];
    cout << "������� �������� ��������� �������: " << endl;
    for(int i = 0; i < n; ++i){ //���������� �� �������� � ���������� ������� � ���������� �������
        main_arr[i] = new char;
        for(int j = 0; j < n; ++j)
            cin >> main_arr[i][j];
    }

    cout << endl;
    cout << "��� ������: | ";
    for(int j = 0; j < n; ++j){
        char tmp = main_arr[n - j - 1][j]; //�������� ��������� ���������� ��� �������� �������� ����������� �� ������� ��������, ����� ����������������
        for(int i = n - j - 1; i < n; ++i){ //��������� �������� � ������� ������� �� �������� ���������
            if(main_arr[i][j] >= tmp && main_arr[i][j] % 3 == 0) tmp = main_arr[i][j]; //�������� �� ��������� ���� � "��������������" ��������
        }
        if(!(tmp % 3)) tmp = char(126); //� ������ ���� �� ���� �������� �� ��������, ���������, ����� ������ ���������� �������� ���� ������ ����
        cout << tmp << " "; //��� ���� �� ��������� ����� �����������, � � �������� ������ ���������� � ���� 126(�� ���.) & �������
    }
    cout << "|" << endl;

    return 0;
}

int second(){
    cout << "������� n(������ ����������� �����): ";
    int n;
    cin >> n;
    if(n < 2 || n % 2 != 0){ //��������� �������� � �������� ������� �������
        cout << "��������� ������!" << endl; //� ������ ������������ ������ ���������� ������������ � ����
        return 0;
    }

    cout << "������� �������� ��������� �������:" << endl;   
    int** matrix = new int*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new int[n];
        for(int j = 0; j < n; ++j) cin >> matrix[i][j];
    }
    swap(n / 2, matrix); //�������� ������� ����������� ���������, �������� �������� ������� ������� ��� ��������
    cout << endl;
    put_matrix(n, matrix); //������� ������� �������������� ��������

    return 0;
}

template <class user_type>
void swap(int n, user_type** matrix){ //������� ����������� ���������
    int tmp; //������� ��������� ����������
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            tmp = matrix[i][j]; //���������� � ��� �������� �������� ��������
            matrix[i][j] = matrix[i + n][j]; //���������� � ���� �������� �������� �������� �� n ���� ����(�� �������)
            matrix[i + n][j] = tmp; //���������� �������� ��������� ���������� � ������� ������� �� n ������ ��������
            tmp = matrix[i][j + n]; //�� ��������, ������ ��������� ������ �� n
            matrix[i][j + n] = matrix[i + n][j + n];
            matrix[i + n][j + n] = tmp;
        }
    }
}

template <class user_type>
void put_matrix(int n, user_type** matrix){
    for(int i = 0; i < n; ++i){
        cout << "| "; //�������� �� ���� ������� � ������� ��������, �������� ����� � ������� ������ � ������ ������(�������� ���������� ����� ����������� �� ������)
        for(int j = 0; j < n; ++j) cout << matrix[i][j] << " ";
        cout << "|" << endl;
    }
}