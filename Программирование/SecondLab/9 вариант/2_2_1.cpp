#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const char c = char(196),   c1 = char(218),   c2 = char(194), c3 = char(191);
const char c4 = char(179),  c5 = char(195),   c6 = char(197), c7 = char(180);
const char c8 = char(192),  c9 = char(217),   c10 = char(193);
//Обхявление и инициализация символьных переменных для создания таблицы

/* Если кодировкой не вышел, то удали предыдущие пять строк и откомментируй следующие три
const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";
*/// Если таки вышел, то удали от палева подальше

void line() {
	cout << c5;
	for (int i = 0; i < 6; ++i) {
		cout << c;
	}
	cout << c6;
	for (int j = 0; j < 12; ++j) {
		cout << c;
	}
	cout << c7 << endl;
}

int main() {
	int xn = 5;
	float x = 2, dx = 0.25, y;

	cout << c1;
	for (int i = 0; i < 6; ++i) {
		cout << c;
	}
	cout << c2;
	for (int j = 0; j < 12; ++j) {
		cout << c;
	}
	cout << c3 << endl;

	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << c4 << setw(6) << "x  ";
	cout << setiosflags(ios::fixed) << setprecision(9);
	cout << c4 << setw(12) << " y     " << c4 << endl;

	while(x <= xn) {
		line();
		if (x > 3.5) {
			y = (sin(x)*log10(x));
		} else {
			y = (pow(cos(x), 2));
		}
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << c4 << setw(5) << x << " ";
		cout << setiosflags(ios::fixed) << setprecision(7);
		cout << c4 << setw(11) << y << " " << c4 << endl;
		x += dx;
	}

	cout << c8;
	for (int i = 0; i < 6; ++i) {
		cout << c;
	}
	cout << c9;
	for (int j = 0; j < 12; ++j) {
		cout << c;
	}
	cout << c10 << endl;
	
	return 0;
}