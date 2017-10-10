#pragma once
#include <iostream>

class Money {
    protected:
        int rub[4];
        int coin[4];
        char* comm;
    public:
        const int div[4] = {50, 10, 5, 1};
        Money(){
            for(int i = 0; i < 4; ++i){
                (*this).rub[i] = 0;
                (*this).coin[i] = 0;
            }
            comm = new char[64];
            comm[0] = '\0';
        }
        Money(int *rubs, int *coins){
            int summ = 0;
            for(int i = 0; i < 4; ++i) summ += rubs[i]*div[i] + coins[i]*div[i]*0.01;
            if(summ < 0){
                std::cout << "_ERR_WRONG_ARGS_IN_MONEY" << std::endl;
                return;
            }
            for(int i = 0; i < 4; ++i){
                (*this).rub[i] = rubs[i];
                (*this).coin[i] = coins[i];
            }
            comm = new char[64];
            comm[0] = '\0';
        }
        Money(const Money &obj){
            int summ = 0;
            for(int i = 0; i < 4; ++i) summ += obj.rub[i] * div[i] + obj.coin[i] * div[i] * 0.01;
            if(summ < 0){
                std::cout << "_ERR_WRONG_ARGS_IN_MONEY" << std::endl;
                return;
            }
            for(int i = 0; i < 4; ++i){
                (*this).rub[i] = obj.rub[i];
                (*this).coin[i] = obj.coin[i];
            }
            comm = new char[64];
            comm[0] = '\0';
        }
        Money(float summ){
            if(summ < 0){
                std::cout << "_ERR_WRONG_ARGS_IN_MONEY" << std::endl;
                return;
            }
            int rubs = int(summ), coins = int(summ*100)%100;
            for(int i = 0; i < 4; ++i){
                rub[i] = rubs / div[i];
                rubs -= div[i] * rub[i];
                coin[i] = coins / div[i];
                coins -= div[i] * coin[i];
            }
            comm = new char[64];
            comm[0] = '\0';
        }
        ~Money(){
            delete[] comm;
            std::cout << "_MONEY_OBJ_SUCCSS_DEL" << std::endl;
        }
        
        void mkComm(int len, char* str){
            for(int i = 0; i < len; ++i){
                (*this).comm[i] = str[i];
            }
            comm[len] = '\0';
        }

        const Money operator+ (const Money &obj) const {
            int *rubs = new int[4], *coins = new int[4];
            for(int i = 0; i < 4; ++i){
                rubs[i] = rub[i] + obj.rub[i];
                coins[i] = coin[i] + obj.coin[i];            
            }
            return Money(rubs, coins);
        }
        const Money operator- (const Money &obj) const {
            int *rubs = new int[4], *coins = new int[4];
            for(int i = 0; i < 4; ++i){
                rubs[i] = rub[i] - obj.rub[i];
                coins[i] = coin[i] - obj.coin[i];            
            }
            return Money(rubs, coins);
        }
        const Money operator* (const float a) const {
            float summ = 0;
            for(int i = 0; i < 4; ++i){
                summ += (rub[i] * div[i]) + (coin[i] * div[i])*0.01;
            }
            return Money(a * summ);
        }
        const Money operator/ (const float a) const {
            float summ = 0;
            for(int i = 0; i < 4; ++i){
                summ += (rub[i] * div[i]) + (coin[i] * div[i])*0.01;
            }
            return Money(summ / a);
        }
        const int GetRub(int i) const {
            return rub[i];
        }
        const int GetCoin(int i) const {
            return coin[i];
        }
};

std::ostream& operator<< (std::ostream& out, const Money& obj){
    int rubs, coins;
    rubs = coins = 0;
    for(int i = 0; i < 4; ++i){
    rubs += (obj.GetRub(i) * obj.div[i]);
    coins += (obj.GetCoin(i) * obj.div[i]);
    }
    out << rubs << "," << coins;
    return out;
}