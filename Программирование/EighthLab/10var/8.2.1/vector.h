#include <iostream>

class Vector {
    private:
        double *val; //������ ������������ ����� ��� �������� �������, ������� �������� � ������ �������
        int amount; //����� �������
    public:
        Vector(){ amount = 0; val = new double; } //��� �������� ������� ��� ����������, ���������� ����� ��� ���� ��������
        Vector(int len){ //����������� ����������� � �������� ��������� ����� �������� �������
            if(len == 0) {
                std::cout << "_ERR_CR_VECTOR_OBJ" << std::endl; return; 
            } //���� ����� ������������� ������� �������� �������� ������� - ����� ��������� �� ������ � ����� �� ������������
            amount = len; 
            val = new double[len]; //��������� ������ ��� ��� ����� �������
            for(int i = 0; i < len; ++i){ val[i] = 0; } //������������ ���� ��������� ������� ����
        }
        Vector(int len, double *arr){ //����������� ����������� ����� � ������ ��������
            if(len == 0) { std::cout << "_ERR_CR_VECTOR_OBJ" << std::endl; return; }
            amount = len;
            val = new double[len];
            for(int i = 0; i < len; ++i) val[i] = arr[i], mid += arr[i], module += arr[i] * arr[i]; //����������� �������� �� ������� � ������
        }
        Vector(const Vector &obj){ //����������� �����������
            amount = obj.GetAmount();
            val = new double[amount];
            for(int i = 0; i < amount; ++i){
                val[i] = obj[i];
            }
        }
        double GetValue(int i) const { return val[i]; } //��������� �������� ������� i
        int GetAmount() const { return amount; } //��������� �������� ����� �������
        int size() const { return GetAmount(); } //��� � GetAmount
        const Vector& operator+ (float num) const { //���������� ��������� �������� ��� �����
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] + num;
            return Vector(amount, buff);
        }
        const Vector& operator- (float num) const { //���������� ��������� ��������� � ������
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] - num;
            return Vector(amount, buff);
        }
        const Vector& operator* (float num) const { //���������� ��������� ���������
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] * num;
            return Vector(amount, buff);
        }
        const Vector& operator/ (float num) const { //���������� ��������� �������
            double *buff = new double[amount];
            for(int i = 0; i < amount; ++i) buff[i] = val[i] / num;
            return Vector(amount, buff);
        }
        double& operator[] (int index) const { //���������� ��������� ��������������
            if(index >= amount) return val[amount - 1]; //������������ ������ �� �������, ����� ����� ���� �������� � ���� ����� ��������
            return val[index];
        }
};

std::ostream& operator<< (std::ostream& out, const Vector &obj){ //���������� ��������� ������
    out << "[ ";
    for(int i = 0; i < obj.GetAmount(); ++i){
        out << obj[i];
        if(i != obj.GetAmount() - 1) out << ",";
        out << " ";
    }
    out << "]";
    return out;
}