#pragma once
#include <iostream>
#include <cstring>

class Slovo {
    private: 
        int len;
        std::string slovo;
    public:
        Slovo(){
            (*this).len = 0;
            CM();
        }
        Slovo(std::string str){
            (*this).len = str.size();
            (*this).slovo = str;
            CM();
        }
        Slovo(int num, char ch){
            (*this).len = num;
            char *cstr = new char[num - 1];
            for(int i = 0; i < num; ++i){
                cstr[i] = ch;
            }
            std::string str(cstr);
            (*this).slovo = str;
            CM();
        }
        Slovo(std::string str, bool start, int n){
            (*this).len = n;
            if(start){
                (*this).slovo = str.substr(0, n);
            } else {
                (*this).slovo = str.substr(str.size() - n, str.size() + 1);
            }
            CM();
        }
        Slovo(const Slovo &obj){
            (*this).len = obj.len;
            (*this).slovo = obj.slovo;
            CM();
        }
        ~Slovo(){
            std::cout << "_CLASS_SLOVO_OBJ_DEL_SUCCSS_" << std::endl;
        }
        void CM(){ std::cout << "_NEW_SLOVO_OBJ_SUCCSS_CREATED" << std::endl; }
        bool operator== (const Slovo &obj) const {
            return (strcmp((*this).slovo.c_str(), obj.slovo.c_str()) == 0 ? true : false);
        }
        const char getch(int i) const {
            return slovo[i];
        }
        const int length() const {
            return len;
        }
        const std::string GetString() const {
            return slovo;
        }
        void Set(std::string str){
            slovo = str;
            len = str.length();
        }
};

std::ostream& operator<< (std::ostream& out, const Slovo &obj){
    for(int i = 0; i < obj.length(); ++i){
        out << obj.getch(i);
    }
    return out;
};