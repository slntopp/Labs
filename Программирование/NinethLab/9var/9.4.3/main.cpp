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
    cout << "Введи f для получения очереди студентов из файла, t - из потока ввода, p - вывести в поток выввода(завершает программу) и s для сохранения очереди в файл(завершает программу)" << endl;
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
            cout << "Введи f для получения очереди студентов из файла, t - из потока ввода, p - вывести в поток вывода и s для сохранения очереди в файл" << endl;
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
    cout << "Количество отличников: " << q.ExcP() << endl;
}

void ThreadGet(Queue& q){
    cout << "Имя Фамилия возраст пол(0-ж/1-м) курс средний балл:" << endl;
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