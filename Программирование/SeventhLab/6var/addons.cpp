void menu() { cout << "1 - ������� �� �����, 2 - ������� ��� ������, 3 - �������� � ����, 4 - �����������, 5 - ������ � ����������, 6 - �������� �����, q - ��� ������ :" << endl; }

int file_read(char** cities, char** times, int* numbers, int* numbers_cpy, int border){
    int len = 0;
    ifstream file("in.txt", ios_base::app);
    while(!file.eof()){
        if(border + len >= 1000) break;
        cities[len] = new char[32];
        times[len] = new char[5];
        int buff;
        file >> cities[len];
        file >> buff;
        numbers[len] = numbers_cpy[len] = buff;
        file >> times[len];
        ++len;
    }
    cout << "Done!" << endl;
    file.close();
    return len;
}

void read(char** cities, char** times, int* numbers, int *numbers_cpy, int len){
    cities[len] = new char[32];
    times[len] = new char[5];
    int buff;
    cout << "����� ����������: ";
    cin >> cities[len];
    cout << "����� �����: ";
    cin >> buff;
    cout << "����� �����������: ";
    cin >> times[len];
    numbers[len] = numbers_cpy[len] = buff;
    cout << "Done!" << endl;
}

void print(char** const cities, char** const times, int* const numbers, int* const numbers_cpy, const int len){
    for(int i = 0; i < len; ++i){
        int j = -1;
        while(numbers_cpy[i] != numbers[++j]);
        cout << "--------------------" << endl << "����� ����������: " << cities[j] << endl;
        cout << "����� �����: " << numbers[j] << endl;
        cout << "����� �����������: " << times[j] << endl << "--------------------" << endl;
    }
    cout << "Done!" << endl;
    menu();
}

void file_write(char** const cities, char** const times, int* const numbers, int* const numbers_cpy, const int len){
    ofstream file("out.txt");
    for(int i = 0; i < len; ++i){
        int j = -1;
        while(numbers[i] != numbers_cpy[++j]);
        file << "--------------------" << endl << cities[j] << endl << numbers[j] << endl << times[j] << endl << "--------------------" << endl;
    }
    cout << "Done!" << endl;
}

int comp(const void* attr1, const void* attr2){
    if(*(reinterpret_cast<const int*>(attr1)) < *(reinterpret_cast<const int*>(attr2))) return -1;
    else if(*(reinterpret_cast<const int*>(attr1)) == *(reinterpret_cast<const int*>(attr2))) return 0;
    else return 1;
}

void sort(int* numbers, int const len){
    qsort(numbers, len, sizeof(int), comp);
    cout << "Done!" << endl;
}