#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "stack.h"

using namespace std;

void RevPolWr(Stack<char> &data, Stack<char> &oper); //Обратная польская запись
bool isOper(char a);
int Priority(char a);
void Resize(int from, int length, char* arr);
double MakeOper(double a, double b, char oper);

int main(){

    Stack <char>nums;
    Stack <char>operations;
    Stack <char>result;

    RevPolWr(nums, operations);

    cout << "Stack:" << endl;
    while(nums.Iterator()) cout << result.Push(nums.Pop()) << " ";
    cout << "\nResult:" << endl;

    char *eq = new char[result.Length()];
    Dict vars;
    int length = 0;
    ifstream in;
    in.open("vars.dat");

    while(result.Iterator()){
        cout << (eq[length++] = result.Pop()) << " ";
    }
    cout << endl;
    
    char key, buff;
    double value;
    while(in){
        in >> key >> buff >> value;
        vars.Push(key, value);
    }

    cout << "Результат выражения: ";
    
    for(int i = 0; i < length; ++i){
        if(isOper(eq[i])){
            vars[eq[i - 2]] = MakeOper(vars[eq[i - 2]], vars[eq[i - 1]], eq[i]);
            Resize(i - 1, length, eq);
            length -= 2;
            i = 0;
        }
    }

    cout << vars[eq[0]] << endl;

    return 0;
}

void RevPolWr(Stack<char>& data, Stack<char>& oper){
    char ch;
    ifstream in;
    in.open("data.dat");
    for(;;){
        in >> ch;
        if(isOper(ch)){
            if(ch == ')'){
                // cout << "<if0> ";
                while((ch = oper.Pop()) != '(' && oper.Iterator()) data.Push(ch);
                // cout << "</if0>" << endl;
            } else if(ch == '('){
                oper.Push(ch);
            } else if(Priority(ch) < Priority(oper.Read())){
                // cout << "<if1> ";
                while(oper.Iterator() && Priority(ch < Priority(data.Push(oper.Pop()))));
                oper.Push(ch);
                // cout << "</if1>" << endl;
            } else {
                // cout << "<if2> ";
                oper.Push(ch);
                // cout << "</if2>" << endl;
            }
            if(ch == '=') break;
            continue;
        }
        data.Push(ch);
    }
    in.close();
}

bool isOper(char a){
    char opers[7] = {'*', '/', '+', '-', '(', '=', ')'};
    for(int i = 0; i < 7; ++i) if(a == opers[i]) return true;
    return false;
}

int Priority(char a){
    if(a == '*' || a == '/') return 3;
    if(a == '+' || a == '-') return 2;
    if(a == '(') return 1;
    if(a == '=') return 0;
    return -1;
}

void Resize(int from, int length, char* arr){
    for(int i = from; i < length - 2; ++i){
        arr[i] = arr[i + 2];
    }
}

double MakeOper(double a, double b, char oper){
    switch(oper){
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
    }
    return NULL;
}