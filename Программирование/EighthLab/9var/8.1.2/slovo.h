#pragma once
#include <iostream>
#include <cstring>

//перевести на char
//добавить pop 

class Slovo {
    private: 
        int len;
        char *slovo;
    public:
        Slovo(){
            (*this).len = 0;
            (*this).slovo = new char[32];
            CM();
        }
        Slovo(std::string str){
            (*this).len = str.size();
            for(int i = 0; i < str.size(); ++i) if(str[i] == ' ' || str[i] == ',' || str[i] == '.') throw 1;
            (*this).slovo = new char[32];
            for(int i = 0; i < str.size(); ++i) (*this).slovo[i] = str[i];
            CM();
        }
        Slovo(int num, char ch){
            (*this).len = num;
            (*this).slovo = new char[32];
            for(int i = 0; i < num; ++i) slovo[i] = ch;
            CM();
        }
        Slovo(std::string str, bool start, int n){
            (*this).len = n;
            (*this).slovo = new char[32];
            if(start){
                for(int i = 0; i < n; ++i) (*this).slovo[i] = str[i];
            } else {
                for(int i = str.size() - n; i < str.size() + 1; ++i) (*this).slovo[i] = str[i];
            }
            CM();
        }
        Slovo(const Slovo &obj){
            (*this).len = obj.len;
            (*this).slovo = new char[32];
            for(int i = 0; i < obj.len; ++i) (*this).slovo[i] = obj.slovo[i];
            CM();
        }
        Slovo(int len, char* str){
            (*this).len = len;
            (*this).slovo = new char[32];
            for(int i = 0; i < len; ++i) (*this).slovo[i] = str[i];
        }
        ~Slovo(){
            std::cout << "_CLASS_SLOVO_OBJ_DEL_SUCCSS_" << std::endl;
        }
        void CM(){ std::cout << "_NEW_SLOVO_OBJ_SUCCSS_CREATED" << std::endl; }
        bool operator== (const Slovo &obj) const {
            return (strcmp((*this).slovo, obj.slovo) == 0 ? true : false);
        }
        const char getch(int i) const {
            return slovo[i];
        }
        const int length() const {
            return len;
        }
        const std::string GetString() const {
            return std::string(slovo);
        }
        void Push(char ch){
            if(len == 31) throw 1;
            (*this).slovo[len] = ch;      
            ++len;
        }
        void Push(std::string str){
            if(len + str.length() >= 31) throw 1;
            for(int i = 0; i < str.length(); ++len, ++i){
                slovo[len] = str[i];
            }
        }
};

std::ostream& operator<< (std::ostream& out, const Slovo &obj){
    for(int i = 0; i < obj.length(); ++i){
        out << obj.getch(i);
    }
    return out;
};