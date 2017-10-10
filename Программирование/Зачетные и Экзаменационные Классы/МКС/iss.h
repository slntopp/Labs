#include "astronaut.h"

class ISS {
    private:
        int modules_count; //Количество модулей
        double oxygen; //Объем кислорода
        const int crew_count; //Лимит по экипажу
        int crew_counter; //Счетчик членов экипажа
        Astronaut* crew; //Массив объектов типа Астронавт - т.е. экипаж
    public:
        ISS(): modules_count(0), oxygen(0), crew_count(0) {} //Создается пустая станция
        ISS(int mc, double oxy, int cc): modules_count(mc), oxygen(oxy), crew_count(cc), crew_counter(0){
            crew = new Astronaut[cc]; //Выделение памяти под cc астронавтов
        }
        void operator+ (const Astronaut &obj){ //Добавление астронавта на станцию
            if(crew_counter == crew_count){
                cout << "Экипаж переполнен" << endl; //Если лимит достигнут
                return;
            }
            crew[crew_counter++] = obj; //Добавление копии объекта в массив
        }
        int GetModules() const { return modules_count; } //Возврат кол-ва модулей
        double GetOxy() const { return oxygen; } //Возврат объем кислорода
        const Astronaut* GetCrew() const { return crew; } //Возврат массива астронавтов(указатель на экипаж)
};

ostream& operator<< (ostream& out, const ISS &obj){
    out << "Количество модулей: " << obj.GetModules() << endl; //Вывод кол-ва модулей
    out << "Экипаж: " << endl << obj.GetCrew() << endl; //Экипажа перегрузкой из astronaut.h 
    out << "Запасы кислорода: " << obj.GetOxy() << "m3" << endl; //Объема кислорода
    return out;
}