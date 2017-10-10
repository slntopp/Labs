#include <fstream>
#include <iostream>
#include <cstdio>
#include "..\note.h"

using namespace std;

void get_data(note *user);
void put_data(note user);
int comparator(const void* a, const void* b);
void birth_sort(int len, note *data);
void search(int len, note *data);
void put_to_file(int i, note* data);
void myqsort(int l, int h, note* data);
int menu();

int main(){
    note data[8]; //���������� ������� ���� note(���������� ��������� ��������� � note.h)
    bool user_add = true; //���������� ���������� ���������� �� ���������� ������(��������) �������� ��������� �� ���������� ����������� � 8 �������
    int i = 0; //������� ���������� ��������� �������� 
    for(;;){ //����������� ����
        switch(menu()){ //Switch-�������� ����������� � �������� ��������� ���������� ������� menu()
            case 1:
                if(user_add){ //�������� ���������� ������, ���� ��� �� ��������� ������ � �������� �������������� �����
                    get_data(&data[i++]); //�� ���� ����������� ����� ������� �� ����
                    if(i == 8) user_add = false; //���� ���-���� �������� ����. ������� ��������� ������
                } else {
                    cout << "���������� ����������� � 8 ��������!" << endl; //� ��������� ��� ��� ���������� ����� �������� ���������
                }
                break;
            case 2:
                birth_sort(i, data); //�������� ������� ���������� � ������� �������������� ���������
                for(int k = 0; k < i; ++k){
                    cout << "________________________________________" << endl;
                    put_data(data[k]);
                    cout << "----------------------------------------" << endl;
                }
                break;
            case 3:
                search(i, data); //����� ������� ������
                break;
            case 5:
                put_to_file(i, data); //����� ������� ������ � ����
                break;
            case 0:
                cout << "Cleaning RAM..." << endl;
                data;
                cout << "Closing program..." << endl;
                return 0; //����� �� ���������
                cout << "��� ���?" << endl; //� ������ ����� �������(�����) �� ���������� �� � ������ ����
                break;
            default:
                break;
        }
    }

    return 1;
}

void get_data(note *user){ //�������� �������� ���������
    (*user).name = new char[10];
    (*user).surname = new char[16];    
    cout << "������� ��������� ������ ����� ������:\n";
    cout << "1)���, 2)�������, 3)����� ��������(��� ���� ������),\n4)���� ��������(����, �����, ��� ����� ������);" << endl;
    cin >> (*user).name >> (*user).surname >> (*user).number >> (*user).date[0] >> (*user).date[1] >> (*user).date[2];
}

void put_data(note user){ //����� �������
    cout << user.surname << " " << user.name << endl;
    cout << "�������: +375" << user.number << endl;
    cout << "���� ��������: " << user.date[0] << "." << user.date[1] << "." << user.date[2] << endl;
}

int comparator(const void* first, const void* second){
    const note* a = (const note*)first;
    const note* b = (const note*)second;
    int res = ((a -> date[2]) - (b -> date[2]));

    return res;
}

void myqsort(int l, int h, note* data){
    int m = data[h / 2].date[2];
    int i = h - 1;
    int j = l;
    while(j <= i){
        while(data[i].date[2] > m) --i;
        while(data[j].date[2] < m) ++j;
        if(j <= i){
            swap(data[i], data[j]);
            --i, ++j;
        }
    }
    if(j < h - 1) myqsort(j, h, data);
    if(l < i) myqsort(l, i, data);
}

void birth_sort(int len, note *data){ //���������� �� ���� ��������, �� ��� � ��� ����� ������� ������ ����� � ���� ��� �� ����
    // qsort(data, len, sizeof(note), comparator);
    myqsort(0, len, data);
}

int menu(){ //����� � ��������
    cout << "��� ���������� ������� ����� 1, 2 ��� ���������� �������� � ���� �� ���� ��������, 3 ��� ������ �� ������ ��������, 5 ��� ������ � ����, ��� ������ 0: " << endl;
    int choice;
    cin >> choice;
    return choice;
}

void search(int len, note *data){ //����� �� ������ ��������, ���������� � ���������� ��� ����������(genius!)
    int number, k = 1;
    cout << "������� ����� ��� ������ ��� ���� ������: ";
    cin >> number;
    cout << "���������� ������:" << endl;
    cout << "---------------------------------------" << endl;
    for(int i = 0; i < len; ++i){
        if(data[i].number == number){
            cout << k << "-_-_-_-_-" << k << "-_-_-_-_-_-" << k << "-_-_-_-_-_-" << k << "-_-_-_-_-" << k << "-_-_-_-_-" << k++ << endl; //� ������� ������
            put_data(data[i]);
        }
    }
    if(k == 1) cout << "������ ������� �� ����������, �������������� �������� 2 ��� ������ ���� �������������!" << endl;
}

void put_to_file(int i, note* data){ //����� � ����
    ofstream outfile("profiles.txt"); //������� ������ ������ ofstream ���������� � ���� ���� profiles.txt
    for(int k = 0; k < i; ++k){
        note user = data[k];
    //������� ������ � outfile
        outfile << "________________________________________" << endl;
        outfile << user.surname << " " << user.name << endl;
        outfile << "�������: +375" << user.number << endl;
        outfile << "���� ��������: " << user.date[0] << "." << user.date[1] << "." << user.date[2] << endl;
        outfile << "----------------------------------------" << endl;
    //�������� ���� �� ������ ������������� ����� ������ �� � ��������� ������������ ��������� ����� �������
    }
}