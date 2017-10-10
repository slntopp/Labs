#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const char c = char(196),   c1 = char(218),   c2 = char(194), c3 = char(191);
const char c4 = char(179),  c5 = char(195),   c6 = char(197), c7 = char(180);
const char c8 = char(192),  c9 = char(217),   c10 = char(193);
//Объявление и инициализация символьных переменных для создания таблицы

/* Если кодировкой не вышел, то удали предыдущие пять строк и откомментируй следующие три
const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";
*/// Если таки вышел, то удали от палева подальше

void line() { //промежуточная линия
	cout << c5;
	for (int l = 0; l < 6; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 12; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 11; ++l) {
		cout << c;
	}
	cout << c7 << endl;
}

int main() {
	
	float e = 0.000001, x0 = -0.5, res = 0.0, x, preres = 1.0;

	cout << c1 << c << c << c << c << c << c << c2 << c << c << c << c << c << c << c << c;
	cout << c << c << c << c << c2 << c << c << c << c << c << c << c << c << c << c << c << c3 << endl;
	cout << setiosflags(ios::fixed) << c4 << setw(3) << "x";
	cout << setw(6) << c4 << setw(15) << " по Тейлору " << setw(2) << c4;
	cout << setw(4) << "   math.h  " << c4 << endl;

	for(int j = 0; j < 11; ++j) {
		line();
		x = x0 + j * 0.1;
		for(int i = 1; fabs(preres) > (e); ++i) {
			preres = (preres * (x / (2 * i)));
			res += preres;
		}
		cout << setiosflags(ios::fixed) << c4 << setprecision(1) << setw(5) << x;
		cout << setw(4) << c4 << setprecision(6) << setw(10) << (res + 1);
		cout << setw(5) << c4 << setprecision(6) << setw(10) << sqrt(1 + x);
		cout << setw(4) << c4 << endl;
		res = 0.0;
		preres = 1.0;
	}
	cout << c8 << c << c << c << c << c << c << c9 << c << c << c << c << c << c << c << c;
	cout << c << c << c << c << c9 << c << c << c << c << c << c << c << c << c << c << c << c10 << endl;

	return 0;

}