#include <iostream>
#include <iomanip>

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

void line() { //промежуточная линия
	cout << c5;
	for (int l = 0; l < 15; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 17; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 19; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 13; ++l) {
		cout << c;
	}
	cout << c6;
	for (int l = 0; l < 9; ++l) {
		cout << c;
	}
	cout << c7 << endl;
}

void Res(float res) { //форматированный вывод результата
	float n = 1;
	int i = 0;
	while (res > n) {
		n *= 10;
		++i;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << c4 << setw(1) << " " << res;
	cout << setw(14 - i) << c4;
}

int main() {

	float dx = 0.5, xn = 6.0, x = 2.0; //дельта-х, конечное х, начальное х
	double res = 1, up = 1, down = 1;
	int sum = 0, mult = 0;


	cout << c1; //вывод шапки таблицы
	for (int l = 0; l < 15; ++l) {
		cout << c;
	}
	cout << c2;
	for (int l = 0; l < 17; ++l) {
		cout << c;
	}
	cout << c2;
	for (int l = 0; l < 19; ++l) {
		cout << c;
	}
	cout << c2;
	for (int l = 0; l < 13; ++l) {
		cout << c;
	}
	cout << c2;
	for (int l = 0; l < 9; ++l) {
		cout << c;
	}
	cout << c3 << endl;
	cout << setiosflags(ios::fixed);
	cout << c4 << "   Результат   " << c4 << " Кол-во сложений ";
	cout << c4 << " Кол-во умножений  " << c4 << " Вычисления  ";
	cout << c4 << "    x    " << c4 << endl;
	line(); //конец вывода шапки
	cout << setiosflags(ios::fixed) << setprecision(2) << c4 << setw(1) << " " << res; //вывод первого
	cout << setw(13) << c4; //результата в силу очевидности
	cout << setiosflags(ios::fixed) << setw(9) << sum << setw(11) << c4;
	cout << setiosflags(ios::fixed) << setw(11) << mult << setw(11) << c4;
	cout << setiosflags(ios::fixed) << setw(1) << " сх. Горнера " << setw(2) << c4;
	cout << setiosflags(ios::fixed) << setw(3) << " " << x << setw(2) << " " << c4 << endl;

	for (int i = 1; i <= (8); ++i) { //решение по схеме Горнера
		line();
		x = x + dx;
		for(int n = i; n > 0; --n) {
			res = (res * x / n + 1);
			sum += 1;
			mult += 1;
		}
		Res(res);
		cout << setiosflags(ios::fixed) << setw(9) << sum << setw(11) << c4;
		cout << setiosflags(ios::fixed) << setw(11) << mult << setw(11) << c4;
		cout << setiosflags(ios::fixed) << setw(1) << " сх. Горнера " << setw(2) << c4;
		cout << setiosflags(ios::fixed) << setw(3) << " " << x << setw(2) << " " << c4 << endl;
		res = 1;
	}
	line();
	cout << setiosflags(ios::fixed) << setprecision(2) << c4 << setw(1) << " " << res;
	cout << setw(13) << c4;
	cout << setiosflags(ios::fixed) << setw(9) << sum << setw(11) << c4;
	cout << setiosflags(ios::fixed) << setw(11) << mult << setw(11) << c4;
	cout << setiosflags(ios::fixed) << setw(3) << "   Простое   " << setw(2) << c4;
	cout << setiosflags(ios::fixed) << setw(3) << " " << x << setw(2) << " " << c4 << endl;


	x = 2.0;  //сброс х
	for(int j = 1; j <= 8; ++j) { //решение "в лоб"
		line();
		x += dx;
		for(int i = 1; i <= j; ++i) {
			up *= x;
			down *= i;
			res += (up/down);
			sum += 1;
			mult += 2;
		}
		Res(res);
		cout << setiosflags(ios::fixed) << setw(9) << sum << setw(11) << c4;
		cout << setiosflags(ios::fixed) << setw(11) << mult << setw(11) << c4;
		cout << setiosflags(ios::fixed) << setw(3) << "   Простое   " << setw(2) << c4;
		cout << setiosflags(ios::fixed) << setw(3) << " " << x << setw(2) << " " << c4 << endl;
		down = up = 1;
		res = 1;
	}

	cout << c8;
	for (int l = 0; l < 15; ++l) {
		cout << c;
	}
	cout << c9;
	for (int l = 0; l < 17; ++l) {
		cout << c;
	}
	cout << c9;
	for (int l = 0; l < 19; ++l) {
		cout << c;
	}
	cout << c9;
	for (int l = 0; l < 13; ++l) {
		cout << c;
	}
	cout << c9;
	for (int l = 0; l < 9; ++l) {
		cout << c;
	}
	cout << c10 << endl;
	return 0;
}