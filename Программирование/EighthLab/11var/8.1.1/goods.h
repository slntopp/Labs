#pragma once
#include <cstdio>

class Goods {
    private:
        char* name; //Наименование товара
        int date; //Дата поступления
        float price; //Цена
        int amount; //Количество единиц товара
        long int invoice; //Номер накладной
    public:
        Goods(): date(000000), price(0), amount(0), invoice(0){
            name = new char;
            name[0] = '\0';
        }
        Goods(const char* _name, int _date, float _price, int _amount, long int _invoice){
            date = _date, price = _price, amount = _amount, invoice = _invoice;
            name = new char[strlen(_name)];
            int i = 0;
            do name[i] = _name[i]; while(_name[i++] != '\0'); //Копирование входящей строки
        }
        Goods(const Goods &obj): date(obj.date), price(obj.price), amount(obj.amount), invoice(obj.invoice){
            name = new char[strlen(obj.name)];
            int i = 0;
            do name[i] = obj.name[i]; while(obj.name[i++] != '\0');
        }
        ~Goods(){ delete[] name; }
        void Add(int _amount){ amount += _amount; }
        void Remove(int _amount){ amount -= _amount; }
        void SetPrice(float _price) { price = _price; }
        float Price(){ return price * amount; }
        char* toString(){
            char* price_str = new char[32];
            sprintf(price_str, "%f", Price());
            return price_str;
        }
};