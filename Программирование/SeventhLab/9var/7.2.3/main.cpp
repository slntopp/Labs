//������ 10000 ����� �� ������������� - ������ �� ������ �������

#include <iostream>
#include <fstream>
#include <ostream>
#include <cmath>
#include <malloc.h>
#include <ctime>

using namespace std;

void mkfile();
void deletesame(int*, int*);
void move(int, int, int*);
void sort(int, int*);

int main(){
    int choice;
    cout << "������� 0 ��� ������������� ������������� ����� � 1 ��� ��������� ������������: ";
    cin >> choice;
    if(choice){
        mkfile();
    }

    int *numbers = (int*)malloc(0), len = 0; //������ ������ ������� �����
    ifstream user_file("in.txt"); //��������������� ������ ����� �� ����
    while(!user_file.eof()){
        numbers = (int*)realloc(numbers, (len+1)*sizeof(int)); //��� ��� ������ �� ����� ����� ���� �������-������� ������ �������� �����������
        user_file >> numbers[len++]; //������ ����� � ������ �� ����� ����� (eof - end of file)
    }
    fflush(stdin); //������� ������� �����(����� �� ����)
    user_file.close(); //�������� �����

    deletesame(&len, numbers); //����� ������� ������� �� ������ ������������� �����(������ ��������)
    sort(len, numbers); //���������� �� �����������

    ofstream outfile("out.txt");
    for(int i = len - 1; i >= 0; --i){
        if(numbers[i] <= 0 || numbers[i] > 9999) continue;
        outfile << numbers[i] << " ";
    }
    outfile.close();


    return 0;
}

void mkfile(){
    long int n;
    cout << "������� ���������� �����(�� n = 10^9):";
    cin >> n;
    ofstream infile("in.txt");
    srand(time(0));
    for(long int i = 0; i < n; ++i){ //���������� ���������� �������
        infile << rand()%10000 << " ";
    }
    infile.close();
}

void deletesame(int* len, int* arr){
    cout << "�������� ���������� �����..." << endl;
    bool rep = false;
    for(int i = 0; i < *len - 1; ++i){
        for(int j = i + 1; j < *len; ++j){
            if(arr[i] == arr[j] && rep){
                move(j, *len, arr);
                --*len;
            } else if(arr[i] == arr[j] && !rep) rep = true;
        }
    }
}

void move(int pos, int len, int* arr){ //�������� ������� � ����� �� �������� �������
    for(int i = pos; i < len - 1; ++i){
        arr[i] = arr[i + 1];
    }
}

void sort(int len, int* arr){ //������ ���������� �������
    cout << "������� ����������..." << endl;
    int buf;
    for(int i = 0; i < len - 1; ++i){
        for(int j = i + 1; j < len; ++j){
            if(arr[i] > arr[j]){
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
        }
    }
}