#include <iostream>
#include <math.h>
#include <algorithm> //Стандартная библиотека

//Писать также, если лень сделать через if/else и тернарные операции
//препод будет крайне доволен, если сделать именно через них

using namespace std;

int main() {

	cout << "_____________________________\n-----------------------------\n";

	double x1, x2, y1, y2;
	cout << "Введите х1: ";
	cin >> x1;
	cout << "Введите y1: ";
	cin >> y1;
	cout << "Введите х2: ";
	cin >> x2;
	cout << "Введите y2: ";
	cin >> y2;

	double preresult1 = max(x1 + y1, x1 * y1), preresult2 = max(x2 + y2, x2 * y2);
	double result = max(preresult1, preresult2);
	cout << "Самое большое число:\n";
	cout << result;
	cout << "\n";
	cout << "#############################\n";

	return 0;
};