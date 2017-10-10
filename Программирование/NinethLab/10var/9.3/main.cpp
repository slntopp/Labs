#include <iostream>
#include <vector>
#include <algorithm> //Для функции sort
#include "addons.cpp"

using namespace std;

int main(){

    int len;
    cout << "Введите длину вектора и его элементы: ";
    cin >> len;
    vector<int> vect(len); //Создаем вектор размера len
    cin >> vect; //Наполняем вектор значениями с клавиатуры
    cout << "Введенный вектор: " << vect << endl;

    sort(vect.begin(), vect.end()); //Сортировка по возрастанию

    cout << "Отсортированный вектор: " << vect << endl;

    return 0;
}