template <typename T> //��������� ���������� �������
class Vector {
    private:
        int size; //���� ������� �������
        T* body; //���� �������(������ ���� �)
    public:
        Vector(int _size): size(_size) { //�������� ������� ������� ������ _size
            body = new T[size];
        }
        Vector(int _size, T* array): size(_size) { //�������� ������� �� ������ ������� array ������ _size
            body = new T[size];
            for(int i = 0; i < size; ++i) body[i] = array[i];
        }
        Vector(const Vector<T> &obj): size(obj.size) { //����������� �����������
            body = new T[size];
            for(int i = 0; i < size; ++i) body[i] = obj.body[i];
        }
        Vector operator+ (Vector<T> obj){ //�������� �������� !!! ��� ����������� ���������� ��������� ��������� !!!
            if(size != obj.size) return *this; //�������� �� ����������� ��������, ���� ��� �� �����, �� ������ �������� ����������
            T* buff = new T[size]; //�������� ���������� ������� � ��������� �� ���� ������ ��� ������ �������
            for(int i = 0; i < size; ++i) buff[i] = body[i] + obj.body[i]; //������ � ���� ���� �������������� ���������
            return Vector(size, buff); //������� ���������� ������� �� ������ ���������� �������
        }
        Vector operator- (Vector<T> obj){
            if(size != obj.size) return *this;
            T* buff = new T[size];
            for(int i = 0; i < size; ++i) buff[i] = body[i] - obj.body[i];
            return Vector(size, buff);
        }
        Vector operator* (Vector<T> obj){
            if(size != obj.size) return *this;
            T* buff = new T[size];
            for(int i = 0; i < size; ++i) buff[i] = body[i] * obj.body[i];
            return Vector(size, buff);
        }
        Vector operator/ (Vector<T> obj){
            if(size != obj.size) return *this;
            T* buff = new T[size];
            for(int i = 0; i < size; ++i) buff[i] = body[i] / obj.body[i];
            return Vector(size, buff);
        }
        Vector& operator=(Vector<T> &obj){ //���������� ��������� ������������
            delete[] body; //������� ������� ����
            size = obj.size; //��������� ������� ��� ����� ������
            body = new T[size]; //��������� ������ ��� ���� ������ �������
            for(int i = 0; i < size; ++i) body[i] = obj.body[i]; //������ � ���� ����� ��������
            return *this; //������� ������� ��� ����������� �������� ��� � ����������� ����������� � �������� ���������
        }
        void Fill(T value){ //����� ���������� ������� ���������� ���������
            for(int i = 0; i < size; ++i) body[i] = value;
        }
        T operator[] (int index) const { //���������� ��������� ��������������
            return body[index];
        }
        int length() const { return size; } //������� ����� �������
};

template<typename T> //��������� ���������� ������
std::ostream& operator<< (std::ostream& out, const Vector<T> &obj){
    out << "[ ";
    for(int i = 0; i < obj.length() - 1; ++i) out << obj[i] << ", ";
    out << obj[obj.length() - 1] << " ]";
    return out;
}