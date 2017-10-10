#pragma once
#include <iostream>

template<typename ut>
class Vector {
    private:
        ut *memory;
        int length;
    public:
        Vector(){ length = 0; throw 0; };
        Vector(int size){
            if(size <= 0) { std::cout << "_ERR_OBJ_VECTOR_CR" << std::endl, throw 1; }
            length = size;
            memory = new ut[length];
        }
        Vector(int size, ut *arr){
            if(size <= 0) { std::cout << "_ERR_OBJ_VECTOR_CR" << std::endl, throw 1; }
            length = size;
            memory = new ut[length];
            for(int i = 0; i < size; ++i) memory[i] = arr[i];
        }
        Vector(const Vector &obj){
            if(obj.length <= 0) { std::cout << "_ERR_OBJ_VECTOR_CR" << std::endl, throw 1; }
            length = obj.length;
            memory = new ut[memory];
            for(int i = 0; i < size; ++i) memory[i] = obj.memory[i];
        }
        const Vector operator+ (float num) const {
            ut *buff = new ut[length];
            for(int i = 0; i < length; ++i) buff[i] = memory[i] + num;
            return Vector(length, buff);
        }
        const Vector operator- (float num) const {
            ut *buff = new ut[length];
            for(int i = 0; i < length; ++i) buff[i] = memory[i] - num;
            return Vector(length, buff);
        }
        const Vector operator* (float num) const {
            ut *buff = new ut[length];
            for(int i = 0; i < length; ++i) buff[i] = memory[i] * num;
            return Vector(length, buff);
        }
        const Vector operator/ (float num) const {
            ut *buff = new ut[length];
            for(int i = 0; i < length; ++i) buff[i] = memory[i] / num;
            return Vector(length, buff);
        }
        ut &operator[] (int index) const {
            if(index >= length) return memory[length - 1];
            return memory[index];
        }
        void Print(){
            std::cout << "[ ";
            for(int i = 0; i < length; ++i){
                std::cout << memory[i];
                if(i != length - 1) std::cout << ",";
                std::cout << " ";
            }
            std::cout << "]";
        }
};