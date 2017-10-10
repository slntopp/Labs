#include <iostream>
#define _USE_MATH_DEFINES_
#include <math.h>
#include <iomanip>

const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

using namespace std;

const double E = M_E;

double func(double, double); //Исходная функция(дана в условии)
void line();
void res(double, double, int);

int main() {
	double a0 = -1.5, b0 = 1, s0 = 0.9, sn = 1.1, ds = 0.05, e = 0.000001, dx, m; //m - середина отрезка, dx - шаг
	double a = a0, b = b0;
	cout<<c1<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c3<<endl;
	cout<<c4<<"   s   "<<c4<<"     x     "<<c4<<"   f(x)   "<<c4<<" iter "<<c4<<endl;

	for(int i = 0; i < (sn - s0)/ds; ++i){
		line();
		double s = s0 + ds * i;
		dx = (b0 - a0);
		int iter = 0;
		while(b - a > e){ //Алгоритм решения методом половинных делений
			dx /= 2;
			m = a + dx;
			if (func(a, s) * func(m, s) <= 0){
				b = m;
			} else {
				a = m;
			}
			++iter;
		}
		res(s, m, iter);
		b = b0, a = a0;
		iter = 0;
	}
	cout<<c8<<c<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c9;
	cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c10<<endl;

	return 0;
}

double func(double x, double s){
	return (pow(x, 2) - pow(E, x) - 1.5*s);
}

void line(){
	cout<<c5<<c<<c<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c6;
	cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c7<<endl;
}

void res(double s, double x, int iter) {
	cout << setiosflags(ios::fixed);
	cout << setw(1) << c4 << setw(7) << setprecision(2) << s << setw(1) << c4;
	cout << setw(11) << setprecision(6) << x << setw(1) << c4;
	cout << setw(10) << fabs(func(x, s)) << setw(1) << c4;
	cout << setprecision(0) << setw(6) << iter << setw(1) << c4 << endl;
}