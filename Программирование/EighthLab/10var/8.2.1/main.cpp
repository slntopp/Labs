#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;

void MassCenter(Vector &x, Vector &y); //Поиска координат центра масс

int main(){

    cout << "Введите n: ";
    int n; //Запрос количества точек
    cin >> n;
    Vector x(n), y(n); //Создание двух векторов (оси) длиной n
    for(int i = 0; i < n; ++i){
        cout << "Введите x" << i << " и у" << i << " через пробел: "; //Запрос ввода координат
        cin >> x[i] >> y[i];
    }

    MassCenter(x, y); //Вызов функции поиска координат центра масс

    return 0;
}

void MassCenter(Vector &x, Vector &y){
    double xi = 0, yi = 0, d = 0; //Числитель из формулы в задании для иксов, игреков; знаменатель из формулы
    for(int i = 0; i < x.size(); ++i){
        xi += (i * x[i]); //Выполнение действий из формулы
        yi += (i * y[i]);
        d += i; //См. формулу
    }
    cout << setprecision(3) << "Координаты центра масс: M(" << xi / d << "," << yi / d << ")" << endl; //Вывод координат с количеством точек после запятой = 3
}