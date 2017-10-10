#include <fstream>
#include <iostream>
#include <cstdio>
#include "..\note.h"

using namespace std;

void get_data(note *user);
void put_data(note user);
int comparator(const void* a, const void* b);
void birth_sort(int len, note *data);
void search(int len, note *data);
void put_to_file(int i, note* data);
void myqsort(int l, int h, note* data);
int menu();

int main(){
    note data[8]; //Объявление массива типа note(самописной структуры описанной в note.h)
    bool user_add = true; //Логическая переменная отвечающая за блокировку записи(создания) объектов структуры по достижению ограничения в 8 записей
    int i = 0; //Подсчет количества созданных объектов 
    for(;;){ //Бесконечный цикл
        switch(menu()){ //Switch-оператор принимающий в значение результат выполнения функции menu()
            case 1:
                if(user_add){ //Проверка блокировки записи, если все ок разрешаем запись и вызываем соответсвующий метод
                    get_data(&data[i++]); //За одно увеличиваем длину массива на один
                    if(i == 8) user_add = false; //Если все-таки достигли макс. размера блокируем запись
                } else {
                    cout << "Достигнуто ограничение в 8 профилей!" << endl; //В следующий раз при блокировке будет выведено сообщение
                }
                break;
            case 2:
                birth_sort(i, data); //Вызываем функцию сортировки и выводим отсортированне структуры
                for(int k = 0; k < i; ++k){
                    cout << "________________________________________" << endl;
                    put_data(data[k]);
                    cout << "----------------------------------------" << endl;
                }
                break;
            case 3:
                search(i, data); //Вызов функции поиска
                break;
            case 5:
                put_to_file(i, data); //Вызов функции вывода в файл
                break;
            case 0:
                cout << "Cleaning RAM..." << endl;
                data;
                cout << "Closing program..." << endl;
                return 0; //Выход из программы
                cout << "Что что?" << endl; //В случае ввода символа(цифры) не подходящих ни к какому меню
                break;
            default:
                break;
        }
    }

    return 1;
}

void get_data(note *user){ //Создание объектов структуры
    (*user).name = new char[10];
    (*user).surname = new char[16];    
    cout << "Введите следующие данные через пробел:\n";
    cout << "1)Имя, 2)Фамилия, 3)Номер телефона(без кода страны),\n4)Дату рождения(день, месяц, год через пробел);" << endl;
    cin >> (*user).name >> (*user).surname >> (*user).number >> (*user).date[0] >> (*user).date[1] >> (*user).date[2];
}

void put_data(note user){ //Вывод профиля
    cout << user.surname << " " << user.name << endl;
    cout << "Телефон: +375" << user.number << endl;
    cout << "Дата рождения: " << user.date[0] << "." << user.date[1] << "." << user.date[2] << endl;
}

int comparator(const void* first, const void* second){
    const note* a = (const note*)first;
    const note* b = (const note*)second;
    int res = ((a -> date[2]) - (b -> date[2]));

    return res;
}

void myqsort(int l, int h, note* data){
    int m = data[h / 2].date[2];
    int i = h - 1;
    int j = l;
    while(j <= i){
        while(data[i].date[2] > m) --i;
        while(data[j].date[2] < m) ++j;
        if(j <= i){
            swap(data[i], data[j]);
            --i, ++j;
        }
    }
    if(j < h - 1) myqsort(j, h, data);
    if(l < i) myqsort(l, i, data);
}

void birth_sort(int len, note *data){ //Сортировка по дате рождения, хз как я это говно написал такого угара у меня еще не было
    // qsort(data, len, sizeof(note), comparator);
    myqsort(0, len, data);
}

int menu(){ //Ответ в названии
    cout << "Для добавления профиля введи 1, 2 для сортировки профилей в базе по дате рождения, 3 для поиска по номеру телефона, 5 для вывода в файл, для выхода 0: " << endl;
    int choice;
    cin >> choice;
    return choice;
}

void search(int len, note *data){ //Поиск по номеру телефона, возвращает в результаты все совпадения(genius!)
    int number, k = 1;
    cout << "Введите номер для поиска без кода страны: ";
    cin >> number;
    cout << "Результаты поиска:" << endl;
    cout << "---------------------------------------" << endl;
    for(int i = 0; i < len; ++i){
        if(data[i].number == number){
            cout << k << "-_-_-_-_-" << k << "-_-_-_-_-_-" << k << "-_-_-_-_-_-" << k << "-_-_-_-_-" << k << "-_-_-_-_-" << k++ << endl; //Я упролся просто
            put_data(data[i]);
        }
    }
    if(k == 1) cout << "Такого профиля не существует, воспользуйтесь командой 2 для вывода всех пользователей!" << endl;
}

void put_to_file(int i, note* data){ //Вывод в файл
    ofstream outfile("profiles.txt"); //Создаем объект класса ofstream привязывая к нему файл profiles.txt
    for(int k = 0; k < i; ++k){
        note user = data[k];
    //Выводим данные в outfile
        outfile << "________________________________________" << endl;
        outfile << user.surname << " " << user.name << endl;
        outfile << "Телефон: +375" << user.number << endl;
        outfile << "Дата рождения: " << user.date[0] << "." << user.date[1] << "." << user.date[2] << endl;
        outfile << "----------------------------------------" << endl;
    //Логичнее было бы просто перенаправить поток вывода но в методичке православным считается такой вариант
    }
}