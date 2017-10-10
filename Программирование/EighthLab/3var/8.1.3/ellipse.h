#include "point.h"

class Ellipse {
    private:
        char* name; //Имя объекта
        double a, b, square; //Базовые параметры фигуры, площадь и периметр
        Point position; //Место нахождения фигуры
        static int counter; //Статическое поле-счетчик объектов, так как поле общее для всех объектов, счетчик будет работать как надо
    public:
        Ellipse(): position(Point(0,0)) {
            char* buff = new char[8]; //Буфферная строка, для сохранения номера объекта в качестве строки
            itoa(counter++, buff, 10); //Запись числа в качестве строки и увеличение значения счетчика на 1
            name = new char[6 + strlen(buff) + 1]; //Выделение памяти на имя объекта: длина названия фигуры + длина строки с номером объекта + 1 на \0
            strcpy(name, "Эллипс");
            strcat(name, buff); //Добавление в переменную с именем объекта строки с номером объекта
            name[strlen(name)] = '\0'; //Нуль-терминант в конец строки, для корректного вывода
        }
        Ellipse(int _a, int _b): a(_a), b(_b), position(Point(0,0)) {
            char* buff = new char[8]; //Буфферная строка, для сохранения номера объекта в качестве строки
            itoa(counter++, buff, 10); //Запись числа в качестве строки и увеличение значения счетчика на 1
            name = new char[6 + strlen(buff) + 1]; //Выделение памяти на имя объекта: длина названия фигуры + длина строки с номером объекта + 1 на \0
            strcpy(name, "Эллипс");
            strcat(name, buff); //Добавление в переменную с именем объекта строки с номером объекта
            name[strlen(name)] = '\0'; //Нуль-терминант в конец строки, для корректного вывода
            square = 3.14 * a * b;
        }
        void init(double _a, double _b){ a = _a; b = _b; square = 3.14 * a * b; } //Метод для инициализации осей
        char* GetName() const { return name; } //Возврат строки - имени объекта
        void Locate(double x, double y){ position = Point(x,y); } //Установка эллипса в точку x,y
        void Resize(double k) { a *= k; b *= k; square = 3.14 * a * b; } //Изменение размера по коэффициенту k
        double GetSquare() const { return square; }
        Point GetLocation() const { return position; }
        double Greater() const { return a > b ? a : b; } //Возврат большей оси
        double Lower() const { return a <= b ? a : b; } //Возврат меньшей оси
};

std::ostream& operator<< (std::ostream& out, const Ellipse &obj){
    out << obj.GetName() << std::endl;
    out << "Расположение: (" << obj.GetLocation().x << "," << obj.GetLocation().y << ")" << std::endl;
    out << "Большая ось - " << obj.Greater() << "; Малая ось - " << obj.Lower() << std::endl;
    out << "Площадь: " << obj.GetSquare() << std::endl;
    return out;
}

int Ellipse::counter = 0; //Инициализация счетчика нулем