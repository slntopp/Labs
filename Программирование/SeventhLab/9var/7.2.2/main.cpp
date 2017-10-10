#include <iostream>
#include <fstream> //��� ������ � �������
#include <ostream> //��� fflush()
#include <cstdio>
#include <cmath>

using namespace std;

void sign_sort(int, int*); //������� ����������

int main(){
    bool choice;
    cout << "������� 1 ��� �������������� ��������� ����� � 0 ��� ����� �� �����: ";
    cin >> choice;
    int len = 0, *numbers = new int[16];
    if(choice){
        cout << "������� ���������� �����: ";
        cin >> len;
        for(int i = 0; i < len; ++i) numbers[i] = pow(-1, i) * rand();
    } else {
        ifstream user_file("num.txt"); //��������������� ������ ����� �� ����
        while(!user_file.eof()) user_file >> numbers[len++]; //������ ����� � ������ �� ����� ����� (eof - end of file)
        fflush(stdin); //������� ������� �����(����� �� ����)
        user_file.close(); //�������� �����
    }

    sign_sort(len, numbers); //����� ������������

    ofstream out_file("out.txt"); //��������������� ������ ������ � ����
    for(int i = 0; i < len; ++i){ //���������� �����
        out_file << numbers[i] << " ";
    }
    fflush(stdout); //������� ������� ������(����� �� ����)
    out_file.close(); //�������� �����
    
    delete[] numbers; //������� ������

    return 0;
}

void sign_sort(int n, int* arr){
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[j] > 0){
                int buf = arr[j];
                arr[j] = arr[i];
                arr[i] = buf;
            }
        }
    }
}