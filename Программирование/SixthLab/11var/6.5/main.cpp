#include <iostream>
#include <cstdio>

using namespace std;

void put_s(int, char*); //Функция вывода строки
void put_c(int n, char* array); //Функция вывода массива
bool check_common(char, int, char*); //Функция сравнения символа с символами массива

int main(){
    // char first[16], second[16], third[16], common[10]; //Объявление строк через символьный массив 
    char *first = new char, *second = new char, *third = new char, *common = new char; //Объявление строк через указатели на char
    //Для строк содержащих слова делаем размер 16, переменная common будет хранить повторяющиеся буквы

    int f, s, t, c; //Объявление целочисленных переменных для хранения длины слов и длины массива общих букв
    f = s = t = c = 0;

    cout << "Введите ваши три слова: ";
    char ch;
    while((ch = getchar()) != ' ') first[f++] = ch; //В заголовке цикла функцией getchar() записывается один символ в переменную char
    while((ch = getchar()) != ' ') second[s++] = ch; //Затем записывается в элемент массива %переменная_name% и увеличивает ее на один
    while((ch = getchar()) != '\n') third[t++] = ch; //Так же в заголовках проверка на разделяющие символы(пробелы и в конце строки на перенос)
    first[f] = second[s] = third[t] = '\0'; //Запись в конец строки нуль-терминанта, потому что так надо

    for(int i = 0; i < f; ++i){ //Цикл проходит по первому слову
        if(check_common(first[i], c, common)) continue; //Проверка текущий буквы на повторяемость(все одинаковые буквы записываются в массив common)
        for(int j = 0; j < s; ++j){ //Вложенный цикл проверяет совпадение с текущей буквой
            if(first[i] == second[j]){ //В случае совпадения запускается третий цикл сверяющий с третьим словом
                for(int k = 0; k < t; ++k){
                    if(first[i] == third[k]){ //Если буквы совпадают, то текущая буква добавляется в массив совпадений common
                        common[c++] = third[k];
                        break; //Завершение цикла
                    }
                }
                break; //Завершение цикла
            }
        }
    }

    cout << "Повторяющиеся буквы: ";
    put_c(c, common); //Вызов функции вывода массива
    cout << endl;

    return 0;
}

void put_s(int n, char* string){
    for(int i = 0; i < n; ++i) cout << string[i];
    cout << endl;
}

void put_c(int n, char* array){
    cout << "[ ";
    if(n == 1) cout << array[0] << ' ';
    else if(n == 0) cout << "не таких";
    else {
        for(int i = 0; i < n - 1; ++i) cout << array[i] << ", ";
        cout << array[n - 1] << ' ';
    }
    cout << "]";
}

bool check_common(char ch, int n, char* array){
    for(int i = 0; i < n; ++i) if(ch == array[i]) return true;
    return 0;
}