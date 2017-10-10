#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "queue.h"

using namespace std;

void FileGet(Queue&, const char*);
void ThreadGet(Queue&);
void StdPut(Queue&);
void FilePut(Queue&, const char*);

int main(){
    char choice;
    Queue main;
    int count = 0;
    cout << "����� f ��� ��������� ������� ��������� �� �����, t - �� ������ �����, p - ������� � ����� �������(��������� ���������) � s ��� ���������� ������� � ����(��������� ���������)" << endl;
    while((choice = getchar()) != 'q'){
        ++count;
        if(choice == 'f'){ FileGet(main, "data.dat"); continue; }
        else if(choice == 't') ThreadGet(main);
        else if(choice == 'p'){
            StdPut(main);
            break;
        }
        else if(choice == 's'){
            FilePut(main, "out.dat");
            break;
        }
        else if(choice == 'o'){
            cout << main.Size() << endl;
        }
        if(count == 5){
            count = 0;
            cout << "����� f ��� ��������� ������� ��������� �� �����, t - �� ������ �����, p - ������� � ����� ������ � s ��� ���������� ������� � ����" << endl;
        }
    }

    return 0;
}

void FileGet(Queue& q, const char* filename){
    Node *students = new Node[32];
    ifstream data;
    data.open(filename);

    int i = 0;
    while(!data.eof()){
        data >> students[i];
        q.Push(students[i++]);
    }
    data.close();
    cout << "���������� ����������: " << q.ExcP() << endl;
}

void ThreadGet(Queue& q){
    cout << "��� ������� ������� ���(0-�/1-�) ���� ������� ����:" << endl;
    Node student;
    cin >> student;
    q.Push(student);
}

void StdPut(Queue& q){
    int s = q.Size();
    for(int i = 0; i < s; ++i){
        cout << q.Read();
        q.Pop();
    }
}

void FilePut(Queue& q, const char* filename){
    ofstream outfile;
    outfile.open(filename);
    int s = q.Size();
    for(int i = 0; i < s; ++i){
        outfile << q.Read();
        q.Pop();
    }
    outfile.close();
}