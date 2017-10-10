#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

namespace y{ //Определение пространства имен у для всех использующихся в программе функций
	void Header(){
		cout << c1 << c << c << c << c << c << c << c2 << c << c << c << c << c << c << c << c;
		cout << c << c << c << c << c2 << c << c << c << c << c << c << c << c << c << c << c << c3 << endl;
		cout << setiosflags(ios::fixed) /*Инициализация библиотеки для управления выводом*/;
		cout << c4 << setw(3)/*Задает ширину поля в которое будут выведены данные*/ << "x";
		cout << setw(6) << c4 << setw(15) << "y по Тейлору" << setw(2) << c4;
		cout << setw(5) << "y по math.h" << c4 << endl;
	}
	void Line(){
		cout << c5 << c << c << c << c << c << c << c6 << c << c << c << c << c << c << c << c;
		cout << c << c << c << c << c6 << c << c << c << c << c << c << c << c << c << c << c << c7 << endl;
	}
	void Footer(){
		cout << c8 << c << c << c << c << c << c << c9 << c << c << c << c << c << c << c << c;
		cout << c << c << c << c << c9 << c << c << c << c << c << c << c << c << c << c << c << c10 << endl;
	}
	void Result(double x, double res){
		cout << setw(1) << c4 << setprecision(2) << setw(6) << x << setw(1) << c4;
		cout << setprecision(6);
		cout << setw(12) << res << setw(2) << c4;
		cout << setw(11) << (log(x) - x + 1) << c4 << endl;
	}
	int TForPoint(double e){
		double x, result = 0, up, up0;
		int iter = 1;
		cout << "Введите Х(x > 0 & x <= 1): ";
		cin >> x;
		if(x <= 0 || x > 1){
			TForPoint(e);
			return 0;
		}
		cout << "y = ln(" << x << ") - " << x << "+ 1" << endl;
		Header();
		Line();
		up = up0 = x - 1;
		do {
			result += (up/iter)*(iter % 2 ? 1 : -1); //Вычисление логарифма по формуле из условия
		//Систему вычисления второго множителя уточнить у меня!
			iter++;
			up *= up0;
		}
		while(fabs(up/iter) > e);
		Result(x, (result - up0));
		Footer();
	}
	int TForInterval(double dx, double e){
		double x0, xn,result = 0, up, up0;
		int iter = 1;
		cout << "Введите Хo и Xn(x > 0 & x <= 1): ";
		cin >> x0 >> xn;
		if(x0 <= 0 || x0 > 1 || xn <= 0 || xn > 1){
			TForPoint(e);
			return 0;
		}
		Header();
		for(int i = 0; i <= (xn - x0)/dx; ++i){
			Line();
			double x = x0 + dx * i;
			up = up0 = x - 1;
			iter = 1;
			result = 0;
			do {
				result += (up/iter)*(iter % 2 ? 1 : -1); //Вычисление логарифма по формуле из условия
			//Систему вычисления второго множителя уточнить у меня!
				iter++;
				up *= up0;
			}
			while(fabs(up/iter) > e);
			Result(x, result - up0);
		}
		Footer();
	}
}

int main() {
	double dx = 0.1, e = 0.000001;
	double choice;
	cout << "Введите 0 для вычисления ряда для точки, либо 1 для отрезка: ";
	cin >> choice;
	if(choice == 0){ //Выбор варианта задания
		y::TForPoint(e); //Обращение к функции через спецификатор указывающий на пространство имен у
	} else if(choice == 1){
		y::TForInterval(dx, e); //Обращение к функции через спецификатор указывающий на пространство имен у
	} else { //Перезапуск программы, в случае неправильного ввода
		main();
		return 0;
	}
	return 0;
}