#include "string"

class Astronaut {
    public:
        char** name; //Двумерный массив для ФИО
        bool sex;
        char country[4]; //Код страны из двух-трех букв (ex. Belarus == BLR)
        Astronaut(){
            country[0] = '\n'; //Для определения пустого объекта при выводе
            name = new char*[3]; //Выделение памяти под все из ФИО
            for(int i = 0; i < 3; ++i) name[i] = new char[16]; // Выделение памяти под слова в ФИО
        }
        Astronaut(const char* _name, bool _sex, const char* _country): sex(_sex) { //Конструктор Астронавта
            if(strlen(country) > 4) return; //Если код страны из 4 и более букв - ошибка
            name = new char*[3]; //Как в первом конструкторе
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
    while(arr[i].country[0] != '\n'){ //Проверка на заполненность объекта(т.е. все ли его поля имеют значения)
        out << i << ")" << arr[i].name[0] << " " << arr[i].name[1] << " " << arr[i].name[2] << endl; //Вывод ФИО через пробел
        out << (arr[i].sex ? "Мужчина" : "Женщина") << endl; //Если sex == 1 -> мужчина, наобороот женщина
        out << "Страна: " << arr[i].country << endl; //Вывод кода страны
        ++i;
    }
    if(i == 0) out << "NoCrew"; //Если экипажа нет - вывод сообщения
    return out;
}