#include "point.h"

class Ellipse {
    private:
        char* name; //��� �������
        double a, b, square; //������� ��������� ������, ������� � ��������
        Point position; //����� ���������� ������
        static int counter; //����������� ����-������� ��������, ��� ��� ���� ����� ��� ���� ��������, ������� ����� �������� ��� ����
    public:
        Ellipse(): position(Point(0,0)) {
            char* buff = new char[8]; //��������� ������, ��� ���������� ������ ������� � �������� ������
            itoa(counter++, buff, 10); //������ ����� � �������� ������ � ���������� �������� �������� �� 1
            name = new char[6 + strlen(buff) + 1]; //��������� ������ �� ��� �������: ����� �������� ������ + ����� ������ � ������� ������� + 1 �� \0
            strcpy(name, "������");
            strcat(name, buff); //���������� � ���������� � ������ ������� ������ � ������� �������
            name[strlen(name)] = '\0'; //����-��������� � ����� ������, ��� ����������� ������
        }
        Ellipse(int _a, int _b): a(_a), b(_b), position(Point(0,0)) {
            char* buff = new char[8]; //��������� ������, ��� ���������� ������ ������� � �������� ������
            itoa(counter++, buff, 10); //������ ����� � �������� ������ � ���������� �������� �������� �� 1
            name = new char[6 + strlen(buff) + 1]; //��������� ������ �� ��� �������: ����� �������� ������ + ����� ������ � ������� ������� + 1 �� \0
            strcpy(name, "������");
            strcat(name, buff); //���������� � ���������� � ������ ������� ������ � ������� �������
            name[strlen(name)] = '\0'; //����-��������� � ����� ������, ��� ����������� ������
            square = 3.14 * a * b;
        }
        void init(double _a, double _b){ a = _a; b = _b; square = 3.14 * a * b; } //����� ��� ������������� ����
        char* GetName() const { return name; } //������� ������ - ����� �������
        void Locate(double x, double y){ position = Point(x,y); } //��������� ������� � ����� x,y
        void Resize(double k) { a *= k; b *= k; square = 3.14 * a * b; } //��������� ������� �� ������������ k
        double GetSquare() const { return square; }
        Point GetLocation() const { return position; }
        double Greater() const { return a > b ? a : b; } //������� ������� ���
        double Lower() const { return a <= b ? a : b; } //������� ������� ���
};

std::ostream& operator<< (std::ostream& out, const Ellipse &obj){
    out << obj.GetName() << std::endl;
    out << "������������: (" << obj.GetLocation().x << "," << obj.GetLocation().y << ")" << std::endl;
    out << "������� ��� - " << obj.Greater() << "; ����� ��� - " << obj.Lower() << std::endl;
    out << "�������: " << obj.GetSquare() << std::endl;
    return out;
}

int Ellipse::counter = 0; //������������� �������� �����