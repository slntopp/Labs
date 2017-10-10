#include <iostream>

class Vector {
    private:
        double *val; //Массив вещественных чисел для значений вектора, среднее значение и модуль вектора
        int amount; //Длина вектора
    public:
        Vector(){ amount = 0; val = new double; } //При создании объекта без параметров, выделяется место под одно значение
        Vector(int len){ //Конструктор принимающий в качестве параметра длину будущего вектора
            if(len == 0) {
                std::cout << "_ERR_CR_VECTOR_OBJ" << std::endl; return; 
            } //Если будет осущевствлена попытка создания нулевого вектора - вывод сообщения об ошибке и выход из конструктора
            amount = len; 
            val = new double[len]; //Выделение памяти под всю длину вектора
            for(int i = 0; i < len; ++i){ val[i] = 0; } //Присваивание всем элементам вектора нуля
        }
        Vector(int len, double *arr){ //Конструктор принимающий длину и массив значений
            if(len == 0) { std::cout << "_ERR_CR_VECTOR_OBJ" << std::endl; return; }
            amount = len;
            val = new double[len];
            for(int i = 0; i < len; ++i) val[i] = arr[i], mid += arr[i], module += arr[i] * arr[i]; //Копирование значений из массива в вектор
        }
        Vector(const Vector &obj){ //Конструктор копирования
            amount = obj.GetAmount();
            val = new double[amount];
            for(int i = 0; i < amount; ++i){
                val[i] = obj[i];
            }
        }
        double GetValue(int i) const { return val[i]; } //Получение элемента вектора i
        int GetAmount() const { return amount; } //Получение значения длины вектора
        int size() const { return GetAmount(); } //Как и GetAmount
        const Vector& operator+ (float num) const { //Перегрузка оператора сложения для числа
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] + num;
            return Vector(amount, buff);
        }
        const Vector& operator- (float num) const { //Перегрузка оператора вычитания с числом
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] - num;
            return Vector(amount, buff);
        }
        const Vector& operator* (float num) const { //Перегрузка оператора умножения
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] * num;
            return Vector(amount, buff);
        }
        const Vector& operator/ (float num) const { //Перегрузка оператора деления
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] / num;
            return Vector(amount, buff);
        }
        double& operator[] (int index) const { //Перегрузка оператора индексирования
            if(index >= amount) return val[amount - 1]; //Возвращается ссылка на элемент, чтобы можно было записать в него новое значение
            return val[index];
        }
};

std::ostream& operator<< (std::ostream& out, const Vector &obj){ //Перегрузка оператора вывода
    out << "[ ";
    for(int i = 0; i < obj.GetAmount(); ++i){
        out << obj[i];
        if(i != obj.GetAmount() - 1) out << ",";
        out << " ";
    }
    out << "]";
    return out;
}