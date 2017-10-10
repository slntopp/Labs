#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

#include "addons.cpp" //�������� ��� �������� ��� �������

bool isBreaker(char ch); //�������� �� ������������ �����

int main(){

    for(int i = 0; i < 58; ++i) d_alphabet_counter[i] = true; //����������������� ������ ������� �������� ��������� � ����� ������
//� ���������� �� ����� ����������� �������������� ����� ��������, � � ����� ����� ����� ������� �����, ��������� ����������� � ������
    cout << "������� ���� ������: ";
    string str; //��������� ������
    getline(cin, str); //��������� �� � ����������

    int result = 0; //����������, �������� ���-�� ���� �� "rd"

    for(int i = 0; i < str.length(); ++i){
        letter_inc(str[i]); //������� ���������, ��� ���� ��������� �����-�� �����, ���� � ����� ������� �� �������� � ������
        if(str[i] == 'r' && str[i + 1] == 'd' && isBreaker(str[i + 2])) ++result; //���� ������� ������ ���� 'r', ��������� 'd', � ������ ����� ���� �� 'r'\
        ����� ���� ������ �����, �������������� ���������
    }
    
    cout << "���������� ���� �������������� �� \"rd\": " << result << endl; //������� ���������

    cout << "����� �� �������� � ������: " << endl; //������� ����� �� �������� � ������
    for(int i = 0; i < 58; ++i){
        if(d_alphabet_counter[i]) cout << d_alphabet[i] << " ";
    }

    return 0;
}
bool isBreaker(char ch){
    const char* breakers = "\"\' ,./!?\n"; //����� ��������� � ������ �������, ������� ����� �������� ��� ��������� ����� �����
    for(int i = 0; i < strlen(breakers); ++i) if(breakers[i] == ch) return true;
    if(ch == NULL) return true; //����� ����� ����� ����� ������ �� ����, ���� ��� ��������� ��� ����� � ������
    return false;
}
