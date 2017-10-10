#include "string"

class Astronaut {
    public:
        char** name; //��������� ������ ��� ���
        bool sex;
        char country[4]; //��� ������ �� ����-���� ���� (ex. Belarus == BLR)
        Astronaut(){
            country[0] = '\n'; //��� ����������� ������� ������� ��� ������
            name = new char*[3]; //��������� ������ ��� ��� �� ���
            for(int i = 0; i < 3; ++i) name[i] = new char[16]; // ��������� ������ ��� ����� � ���
        }
        Astronaut(const char* _name, bool _sex, const char* _country): sex(_sex) { //����������� ����������
            if(strlen(country) > 4) return; //���� ��� ������ �� 4 � ����� ���� - ������
            name = new char*[3]; //��� � ������ ������������
            for(int i = 0, j = 0, k = 0; i < strlen(_name); ++i){
                if(k == 0) name[j] = new char[16];
                if(_name[i] == ' '){
                    name[j++][k] = '\0';
                    k = 0;
                    continue;
                }
                name[j][k++] = _name[i];
            }
            strcpy(country, _country);
        }
};

ostream& operator<< (ostream& out, const Astronaut* arr){
    int i = 0;
    while(arr[i].country[0] != '\n'){ //�������� �� ������������� �������(�.�. ��� �� ��� ���� ����� ��������)
        out << i << ")" << arr[i].name[0] << " " << arr[i].name[1] << " " << arr[i].name[2] << endl; //����� ��� ����� ������
        out << (arr[i].sex ? "�������" : "�������") << endl; //���� sex == 1 -> �������, ��������� �������
        out << "������: " << arr[i].country << endl; //����� ���� ������
        ++i;
    }
    if(i == 0) out << "NoCrew"; //���� ������� ��� - ����� ���������
    return out;
}