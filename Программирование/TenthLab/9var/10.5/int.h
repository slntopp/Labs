#pragma once
#include <cstring>
#include <string>

class Ull {
    private:
        string dec, bin;
    public:
        Ull(long long value = 0){
            dec.clear();
            bin.clear();
            char *_dec = new char[12];
            sprintf(_dec, "%lld", value);
            dec = string(_dec);
            bin = toBin(value);
            delete[] _dec;
        }
        ~Ull(){
            dec.clear();
            bin.clear();
        }
        void Clear(){
            dec.clear();
            bin.clear();
        }
        const char* GetBin() const { return bin.c_str(); }
        const char* GetDec() const { return dec.c_str(); }
        string GetBinS(){ return bin; }
        string GetDecS(){ return dec; }
        string toBin(long long n){
            string result;
            do
            {
                result += ('0' + (n % 2));
                n = n / 2;
            } while (n > 0);
            return BinReverse(result);
        }
        string BinReverse(string in){
            string result;
            for(int i = in.length() - 1; i >= 0; --i){
                result.push_back(in[i]);
            }
            return result;
        }
};

string Reverse(string in){
    string result;
    for(int i = in.length() - 1; i >= 0; --i){
        result.push_back(in[i]);
    }
    return result;
}

bool isPalindrome(string subject){
    if(subject[0] != subject[subject.length() - 1]) return false;
    if(subject == Reverse(subject)) return true;
    return false;
}

ostream& operator<< (ostream& out, const Ull &obj){
    out << obj.GetDec() << " - " << obj.GetBin();
    return out;
}