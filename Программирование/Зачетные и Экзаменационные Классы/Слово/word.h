class Word {
    private:
        int size; //Длина строки
        char* body; //СТрока
    public:
        Word(int _size = 0): size(_size) { //Создание пустого слова размера _size (по умолчанию = 0)
            body = new char[size + 1]; //Выделение памяти под нуль терминант
            body[0] = '\0'; //Запись нуль-терминанта в начало строки 
        }
        Word(char* word): size(strlen(word)) { //Создание объекта на основе си-строки
            body = new char[size + 1]; //Выделение памяти под строку + нуль-терминант
            for(int i = 0; i < size; ++i) body[i] = word[i]; //Копирование строки в объект (циклом, тому що понаставят вижуалок - strcpy не работает)
            body[size] = '\0'; //Запись нуль-терминанта в конец строки
        }
        Word(const Word &obj): size(obj.size){ //Конструктор копирования
            body = new char[size]; //Выделение памяти под копию строки входящего объекта
            for(int i = 0; i < size; ++i) body[i] = obj.body[i]; //Копирование строки
            body[size] = '\0'; //Запись нуль-терминанта в конец
        }
        int length() const { return size; } //Получение длины строки-объекта
        const char* to_c() const { return body; } //Возврат константной строки в формате указателя на char (char*)
        char* pointer() { return body; } //Возврат указателя на внутреннее представление строки(например, для ее инициализации при вводе строки необычными методами)
        void re_init() { while(body[++size] != '\0'); } //Пересчет длины строки
        Word operator+ (const Word &obj){ //Конкатенация строк (склеивание крч)
            char* buff = new char[size]; //Создание буфферной строки
            for(int i = 0; i < size; ++i) buff[i] = body[i]; //Копирование в нее строки из основного объекта
            return Word(strcat(buff, obj.body)); //Склеивание этой строки со строкой из входящего объекта и создание анонимного объекта на основе это строки.\
            возврат объекта в вызывающую функцию
        }
        void Push(char ch){ //Добавление символа в конец
            body = (char*) realloc(body, ++size * sizeof(char)); //Перевыделение памяти - на один символ больше
            body[size] = '\0'; //Запись в конец нуль-терминанта
            body[size - 1] = ch; //Запись в конец строки символа
        }
        void Push(char* str){ //Добавление строки в конец
            body = (char*) realloc(body, (size + strlen(str)) * sizeof(char)); //Перевыделение памяти
            for(int i = size; i < size + strlen(str); ++i) body[i] = str[i - size]; //Запись доп строки в объект
            size += strlen(str); //Увеличение размера строки объекта на длину входящей строки
            body[size] = '\0'; //Запись нуль-терминанта в конец
        }
        char operator[] (int index) { if(index >= size) return '\0'; return body[index]; } //Перегрузка оператора индексирования - если индекс превышает размер - возврат пустоты
        ~Word(){ delete[] body; } //Деструктор - очистка памяти от массива char
};

ostream& operator<< (ostream& out, const Word &obj){ //Перегрузка вывода
    return out << obj.to_c(); //С-строки выводятся в потоки, если подключена библиотека <string> и если в них есть '\0'
}

istream& operator>> (istream& in, Word &obj){ //Перегрузка ввода
    in >> obj.pointer(); //Ввод из потока ввода в С-строку поддерживается библиотекой <string>, см. метод Word::pointer()
    obj.re_init(); //Переучет!
    return in;
}