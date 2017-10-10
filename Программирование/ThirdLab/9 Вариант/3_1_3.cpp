#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const double e = 0.000001;

const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

namespace myfuncs {
	void body(double x, double& res, double preres, int n){
		preres = (preres * (x / (2 * n)));
		res += preres;
		++n;
		if(fabs(preres) > e) body(x, res, preres, n);
	}

	void line() {
		cout << c5 << c << c << c << c << c << c << c6 << c << c << c << c << c << c << c << c;
		cout << c << c << c << c << c6 << c << c << c << c << c << c << c << c << c << c << c << c7 << endl;
	}
}

int main() {
	double x0, xn, dx, x, finres = 0;
	cout << "Введите нижнюю границу отрезка: ";
	cin >> x0;
	x = x0;
	cout << "Введите верхнюю границу отрезка: ";
	cin >> xn;
	cout << "Введите шаг(дельта-х): ";
	cin >> dx;

	cout << c1 << c << c << c << c << c << c << c2 << c << c << c << c << c << c << c << c;
	cout << c << c << c << c << c2 << c << c << c << c << c << c << c << c << c << c << c << c3 << endl;
	cout << setiosflags(ios::fixed) << c4 << setw(3) << "x";
	cout << setw(6) << c4 << setw(15) << " по Тейлору " << setw(2) << c4;
	cout << setw(4) << "   math.h  " << c4 << endl;

	int n = 1;
	while(x <= xn) {
		myfuncs::line();
		myfuncs::body(x, finres, 1, n);
		cout << setiosflags(ios::fixed) << c4 << setprecision(1) << setw(5) << x;
		cout << setw(4) << c4 << setprecision(6) << setw(10) << (finres + 1);
		cout << setw(5) << c4 << setprecision(6) << setw(10) << sqrt(1 + x);
		cout << setw(4) << c4 << endl;
		finres = 0, x += dx;		
	}
	cout << c8 << c << c << c << c << c << c << c9 << c << c << c << c << c << c << c << c;
	cout << c << c << c << c << c9 << c << c << c << c << c << c << c << c << c << c << c << c10 << endl;

	return 0;
}