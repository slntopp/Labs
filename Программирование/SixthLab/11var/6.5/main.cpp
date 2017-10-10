#include <iostream>
#include <cstdio>

using namespace std;

void put_s(int, char*); //������� ������ ������
void put_c(int n, char* array); //������� ������ �������
bool check_common(char, int, char*); //������� ��������� ������� � ��������� �������

int main(){
    // char first[16], second[16], third[16], common[10]; //���������� ����� ����� ���������� ������ 
    char *first = new char, *second = new char, *third = new char, *common = new char; //���������� ����� ����� ��������� �� char
    //��� ����� ���������� ����� ������ ������ 16, ���������� common ����� ������� ������������� �����

    int f, s, t, c; //���������� ������������� ���������� ��� �������� ����� ���� � ����� ������� ����� ����
    f = s = t = c = 0;

    cout << "������� ���� ��� �����: ";
    char ch;
    while((ch = getchar()) != ' ') first[f++] = ch; //� ��������� ����� �������� getchar() ������������ ���� ������ � ���������� char
    while((ch = getchar()) != ' ') second[s++] = ch; //����� ������������ � ������� ������� %����������_name% � ����������� �� �� ����
    while((ch = getchar()) != '\n') third[t++] = ch; //��� �� � ���������� �������� �� ����������� �������(������� � � ����� ������ �� �������)
    first[f] = second[s] = third[t] = '\0'; //������ � ����� ������ ����-����������, ������ ��� ��� ����

    for(int i = 0; i < f; ++i){ //���� �������� �� ������� �����
        if(check_common(first[i], c, common)) continue; //�������� ������� ����� �� �������������(��� ���������� ����� ������������ � ������ common)
        for(int j = 0; j < s; ++j){ //��������� ���� ��������� ���������� � ������� ������
            if(first[i] == second[j]){ //� ������ ���������� ����������� ������ ���� ��������� � ������� ������
                for(int k = 0; k < t; ++k){
                    if(first[i] == third[k]){ //���� ����� ���������, �� ������� ����� ����������� � ������ ���������� common
                        common[c++] = third[k];
                        break; //���������� �����
                    }
                }
                break; //���������� �����
            }
        }
    }

    cout << "������������� �����: ";
    put_c(c, common); //����� ������� ������ �������
    cout << endl;

    return 0;
}

void put_s(int n, char* string){
    for(int i = 0; i < n; ++i) cout << string[i];
    cout << endl;
}

void put_c(int n, char* array){
    cout << "[ ";
    if(n == 1) cout << array[0] << ' ';
    else if(n == 0) cout << "�� �����";
    else {
        for(int i = 0; i < n - 1; ++i) cout << array[i] << ", ";
        cout << array[n - 1] << ' ';
    }
    cout << "]";
}

bool check_common(char ch, int n, char* array){
    for(int i = 0; i < n; ++i) if(ch == array[i]) return true;
    return 0;
}