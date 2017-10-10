template <typename T> //Директива объявления шаблона
class Vector {
    private:
        int size; //Поле размера вектора
        T* body; //Тело вектора(массив типа Т)
    public:
        Vector(int _size): size(_size) { //Создание пустого вектора длиной _size
            body = new T[size];
        }
        Vector(int _size, T* array): size(_size) { //Создание вектора на основе массива array длиной _size
            body = new T[size];
            for(int i = 0; i < size; ++i) body[i] = array[i];
        }
        Vector(const Vector<T> &obj): size(obj.size) { //Конструктор копирования
            body = new T[size];
            for(int i = 0; i < size; ++i) body[i] = obj.body[i];
        }
        Vector operator+ (Vector<T> obj){ //Оператор сложения !!! ВСЕ ПОСЛЕДУЮЩИЕ ПЕРЕГРУЗКИ АБСОЛЮТНО ИДЕНТИЧНЫ !!!
            if(size != obj.size) return *this; //Проверка на соотвествие размеров, если они не равны, то вектор остается неизменным
            T* buff = new T[size]; //Создание буфферного массива и выделение на него памяти под размер вектора
            for(int i = 0; i < size; ++i) buff[i] = body[i] + obj.body[i]; //Запись в него сумм соотвествующих элементов
            return Vector(size, buff); //Возврат анонимного объекта на основе буфферного массива
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
        Vector& operator=(Vector<T> &obj){ //Перегрузка оператора присваивания
            delete[] body; //Очистка старого тела
            size = obj.size; //Изменение размера под новый вектор
            body = new T[size]; //Выделение памяти под тело нового размера
            for(int i = 0; i < size; ++i) body[i] = obj.body[i]; //Запись в него новых значений
            return *this; //Возврат объекта для последующей передачи его в конструктор копирования в основной программе
        }
        void Fill(T value){ //Метод заполнения вектора переданным значением
            for(int i = 0; i < size; ++i) body[i] = value;
        }
        T operator[] (int index) const { //Перегрузка оператора индексирования
            return body[index];
        }
        int length() const { return size; } //Возврат длины вектора
};

template<typename T> //Шаблонная перегрузка вывода
std::ostream& operator<< (std::ostream& out, const Vector<T> &obj){
    out << "[ ";
    for(int i = 0; i < obj.length() - 1; ++i) out << obj[i] << ", ";
    out << obj[obj.length() - 1] << " ]";
    return out;
}