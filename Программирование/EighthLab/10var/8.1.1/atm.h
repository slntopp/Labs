class ATM {
    private:
        char* id; //��������� ���� ��� ������������������ ������
        const int divs[6] = { 10, 20, 50, 100, 200, 500 }; //�������� �����
        int money[6], min, max, all; //������ �������� ���������� �����, ������ � ������� ������� � ���������, � ����� ����� ���������� ����� � ���������
    public:
        ATM(const char* _id, int _min = 10, int _max = 400): min(_min), max(_max) { //����������� ��������� ������ � id, ������� ����� �������� �� ���������, �� ����� � � ����
            id = new char[strlen(_id) + 1]; //��������� ������ � id ��� ������ _id + 1 ��� ��������� ������("\0")
            strcpy(id, _id); //����������� _id � id
            for(int i = 0; i < 6; ++i) money[i] = 0; //������������ ���� ���� �������, �.�. �������� ����
            all = AllMoney(); //������� ���� ����� � ���������
        }
        ATM(const ATM &obj): min(obj.min), max(obj.max), all(obj.all) { //����������� �����������
            id = new char[strlen(obj.id) + 1];
            strcpy(id, obj.id);
            for(int i = 0; i < 6; ++i) money[i] = obj.money[i];
        }
        int AllMoney(){ //������� ���� ����� � ���������
            int result = 0;
            for(int i = 0; i < 6; ++i) result += (money[i] * divs[i]); //������ �������� ���������� �� ���������� "�������" � ����������� � ����
            return result;
        }
        const char* toString(){ //����������� ������� ��� �������� ���������� ����� � ��������� � ���� ������
            char* out = new char[32]; //��������� ������ ��� ����� ������
            itoa(AllMoney(), out, 10); //������� ���� ����� � ��������� � ������ � ������ �� � <out>
            int i = 0;
            for(; out[i] != '\0'; ++i); //�������� �� <out> �� ����� ������
            out[i] = '�', out[i+1] = '.', out[i+2] = '\0'; //���������� � ����� "�." - ������ �����, � ������ ����� ������
            return out; //���������� ��������
        }
        int PutMoney(int *_money){ //�������� ����� � �������� � ������� �������, ������������ ������� money � ������(�.�. ���-�� ������� �� ���������)
            for(int i = 0; i < 6; ++i) money[i] += _money[i]; //�������� ��������������� ���������
            all = AllMoney(); //������� ���-�� ���� ����� � ���������
        }
        int PutMoney(int _money){ //�������� ����� ������
            for(int i = 0; i < 6; ++i){ //��������� ����� �� ������ �� ���������
                money[i] += _money / divs[i]; //������ ���������� ������ � ������ �����(10-��), ������������ ��������� ������� ������ �� 10
                _money = _money % divs[i]; //�� ����� ������� ����� ���������� ������� �� ������� ����
            }
            all = AllMoney(); //�������� ���� ����� � ���������
            cout << "������� �� ���������� ���������: " << _money << "; �������: " << all << "�." << endl; //����� ��������������� ��������� �� ��������
            return _money;
        }
        int GetMoney(int summ){ //������ �����
            cout << "������� ������ " << summ << "�.:" << endl;
            if(summ < min || summ > max){ cout << "����� ��� ������ ������ ����������! �������� �� " << min << "�. �� " << max << "�." << endl; return 0; } //����������� ��������, ���� ����� ������� �� ������������ ������� � ���������
            else if(summ > all) { cout << "����� ��������� ������� � ���������! �� ������ ����� �� " << all << "�." << endl; return 0; } //��������� �������� � ������ ���������� ������� � ���������
            else if(summ % 10 != 0) { cout << "����� �������� 10-��, � ���������� ������ ������ �� 10-�� ������!"; return 0; } //��������� ��������, ���� ��������� ����� �� ����� ���� ������
            cout << "�������� ������! ������: " << summ << "�." << endl;
            for(int i = 5; i >= 0; --i){ //���������� ���������� ����� � ����������� � ��������� ������
                money[i] -= summ / divs[i];
                summ = summ % divs[i];
            }
            all = AllMoney(); //��������
            return summ;
        }
};