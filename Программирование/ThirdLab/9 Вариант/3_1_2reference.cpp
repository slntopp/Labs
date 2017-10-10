#include <iostream>
#include <iomanip>

using namespace std;

const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

void body(double x, double& result, int n);
double fact(int n);
double pow(double x, int n);
void line();
void formatted_out(double x, double result, int n);

int main() {
	double x0 = 2, xn = 6, dx = 0.5, finres = 0, x = x0;
	int n;
	cout << "Введите n: ";
	cin >> n;

	cout<<c1<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c;
	cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c3<<endl;
	cout << c4 << " Прямое вычисление                        " << c4 << endl;
	cout<<c5<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c;
	cout<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c7<<endl;
	cout<<c4<<"  x  "<<c4<<"    +    "<<c4<<"       *       "<<c4<<"  Result  "<<c4<<endl;

	while(x <= xn){
		line();
		for(int i = n; i >= 0; --i) {
			body(x, finres, i);
		}
		formatted_out(x, finres, n);
		x += dx, finres = 0;
	}
	cout<<c8<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c;
	cout<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c10<<endl;
	return 0;
}

double fact(int n){
	double res = 1;
	for(int i = 1; i <= n; ++i){
		res *= i;
	}
	if(n == 0) {
		res = 1;
	}
	return res;
}

double pow(double x, int n){
	if(n == 0) return 1;
	double powx = 1;
	for(int i = 1; i <= n; ++i){
		powx *= x;
	}
	return powx;
}

void body(double x, double& result, int n){
	result += (pow(x, n) / fact(n));
}

void line(){
	cout << c5 << c << c << c << c << c << c6;
	cout << c << c << c << c << c << c << c << c << c << c6;
	cout << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c << c6;
	cout <<  c << c << c << c << c << c << c << c << c << c << c7 << endl;
}

void formatted_out(double x, double result, int n){
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << setw(1) << c4 << setw(5) << x << setw(1) << c4;
	cout << setprecision(3) << setw(9) << (n - 1) << setw(1) << c4;
	int mult = 0;
	for(int j = 0; j <= n; ++j){
		mult += j;
	}
	cout << setw(15) << mult << setw(1) << c4;
	cout << setprecision(3) << setw(10) << result << setw(1) << c4 << endl;
}