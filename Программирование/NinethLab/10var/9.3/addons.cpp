template<typename UT> //��������� ������� ���������� ��������� ������ ��� �������
std::ostream& operator<<(std::ostream& out, const std::vector<UT> &obj){ //����� �������� ������ � ���������� ������ ����
    for(int i = 0; i < obj.size(); ++i) out << obj[i] << " "; //����� ��������� ����� ������
    return out;
}
template<typename UT> //��������� ������� ���������� ��������� ����� ��� �������
std::istream& operator>>(std::istream& in, std::vector<UT> &obj){
    for(int i = 0; i < obj.size(); ++i){ in >> obj[i]; } //��� ��� �� ����� �������� ��� ������ len ���������, size ���������� ���������
    return in;
}