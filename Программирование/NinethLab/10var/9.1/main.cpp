#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

#include "addons.cpp" //Почитать тут комменты про массивы

bool isBreaker(char ch); //Проверка на закнченность слова

int main(){

    for(int i = 0; i < 58; ++i) d_alphabet_counter[i] = true; //Проинициализируем каждый жлемент счетчика попадания в букву нулями
//В дальнейшем мы будем увеличивать соответсвующее букве значение, и в конце можно будет вывести буквы, которыене встречались в тексте
    cout << "Введите вашу строку: ";
    string str; //Объявляем строку
    getline(cin, str); //Заполняем ее с клавиатуры

    int result = 0; //Переменная, хранящая кол-во слов на "rd"

    for(int i = 0; i < str.length(); ++i){
        letter_inc(str[i]); //Говорим программе, что была встречена такая-то буква, дабы в конце вывести не вошедшие в строку
        if(str[i] == 'r' && str[i + 1] == 'd' && isBreaker(str[i + 2])) ++result; //Если текущий символ есть 'r', следующий 'd', а символ через один от 'r'\
        может быть концом слова, инкрементируем результат
    }
    
    cout << "Количество слов оканчивающихся на \"rd\": " << result << endl; //Выводим результат

    cout << "Буквы не вошедшие в строку: " << endl; //Выводим буквы не вошедшие в строку
    for(int i = 0; i < 58; ++i){
        if(d_alphabet_counter[i]) cout << d_alphabet[i] << " ";
    }

    return 0;
}
bool isBreaker(char ch){
    const char* breakers = "\"\' ,./!?\n"; //Знаки препинани и прочие символы, которые могут означать для программы конец слова
    for(int i = 0; i < strlen(breakers); ++i) if(breakers[i] == ch) return true;
    if(ch == NULL) return true; //После слова также может ничего не быть, если оно последние при вводе в строку
    return false;
}
