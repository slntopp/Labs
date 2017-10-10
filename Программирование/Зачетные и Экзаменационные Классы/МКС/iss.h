#include "astronaut.h"

class ISS {
    private:
        int modules_count; //���������� �������
        double oxygen; //����� ���������
        const int crew_count; //����� �� �������
        int crew_counter; //������� ������ �������
        Astronaut* crew; //������ �������� ���� ��������� - �.�. ������
    public:
        ISS(): modules_count(0), oxygen(0), crew_count(0) {} //��������� ������ �������
        ISS(int mc, double oxy, int cc): modules_count(mc), oxygen(oxy), crew_count(cc), crew_counter(0){
            crew = new Astronaut[cc]; //��������� ������ ��� cc �����������
        }
        void operator+ (const Astronaut &obj){ //���������� ���������� �� �������
            if(crew_counter == crew_count){
                cout << "������ ����������" << endl; //���� ����� ���������
                return;
            }
            crew[crew_counter++] = obj; //���������� ����� ������� � ������
        }
        int GetModules() const { return modules_count; } //������� ���-�� �������
        double GetOxy() const { return oxygen; } //������� ����� ���������
        const Astronaut* GetCrew() const { return crew; } //������� ������� �����������(��������� �� ������)
};

ostream& operator<< (ostream& out, const ISS &obj){
    out << "���������� �������: " << obj.GetModules() << endl; //����� ���-�� �������
    out << "������: " << endl << obj.GetCrew() << endl; //������� ����������� �� astronaut.h 
    out << "������ ���������: " << obj.GetOxy() << "m3" << endl; //������ ���������
    return out;
}