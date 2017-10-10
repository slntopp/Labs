#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int eqXY(float x1, float x2, float y1, float y2) { //Функция сравнения объектов точек по координатно
	if (x1 == x2 and y1 == y2) { //Возвращает true если и х и у равны
		return 1;
	};
	return 0;
};

int main() {

	float p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
	int select;
	cout << "Выберите вариант задания(1 либо 2): ";
	cin >> select;
	if (select == 1) {
		p1x = 0, p1y = 1;
		p2x = 4, p2y = 1;
		p3x = -1, p3y = -2;
		p4x = 0, p4y = 1;
	} else if (select == 2) {
		p1x = -1, p1y = -2;
		p2x = 1, p2y = 4;
		p3x = 2, p3y = -5;
		p4x = 0, p4y = 1;
	} else {
		cout << "Введен некорректный номер варианта. Попробуйте еще раз." << endl;
		main();
	};

	float x1 = (p1x * p2y - p2x * p1y) * (p4x - p3x);
	float x2 = (p3x * p4y - p4x * p3y) * (p2x - p1x);
	float x3 = (p1y - p2y) * (p4x - p3x);
	float x4 = (p3y - p4y) * (p2x - p1x);
	static float x = (x1 - x2) / (x3 - x4); //Вычисление возможных точек пересечения
	float y1 = (p3y - p4y) * x;
	float y2 = p3x * p4y - p4x * p3y;
	float y3 = p4x - p3x;
	static float y = (y1 - y2) / y3; 

	float k1 = (p2x - p1x) / (p2y - p1y); //Вычисление тангенсов углов наклона
	float k2 = (p4x - p3x) / (p4y - p3y); //отрезков относительно оси Ох

	float a1 = (p1y -p2y), b1 = (p2y - p1x), c1 = (p1x * p2y - p2x * p1y); //Определение составных коэффициентов
	float a2 = (p3y -p4y), b2 = (p4y - p3x), c2 = (p3x * p4y - p4x * p3y); //для уравнения прямой данных отрезков

	if (((p1x <= x) and (p2x >= x) and (p3x <= x) and (p4x >= x))or((p1y <= y) and (p2y >= y) and (p3y <= y) and (p4y >= y)))  {
		cout << "Отрезки пересекаются. Точка пересечения: C(" << x << ", " << y << ")" << endl;
	} else if ((a1 * p3x + b1 * p3y + c1 > 0) && (a1 * p4x + b1 * p4y + c1 > 0)) {
		cout << "Отрезок [P3,P4] находится над отрезком [P1,P2]." << endl;
	} else if ((a1 * p3x + b1 * p3y + c1 < 0) && (a1 * p4x + b1 * p4y + c1 < 0)) {
		cout << "Отрезок [P1,P2] находится над отрезком [P3,P4]." << endl;
	} else if (k1 == k2) {
		if (a1 == a2) {
			cout << "Отрезки лежат на одной прямой." << endl;
			if (eqXY(p1x, p3x, p1y, p3y) or eqXY(p1x, p4x, p1y, p4y) or eqXY(p2x, p3x, p2y, p3y) or eqXY(p2x, p4x, p2y, p4y)) {
				cout << "Один отрезок является продолжением другого." << endl;
			}
		} else { 
			cout << "Отрезки параллельны друг другу." << endl;
		}
	} else {
		cout << "Что-то пошло очень не так." << endl;
	};

	cout << "\n#############################" << endl;
	return 0;
};