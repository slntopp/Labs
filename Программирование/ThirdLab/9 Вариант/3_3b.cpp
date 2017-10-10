#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

const double eps = 0.000001, e = M_E;
int iter = 0;
const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

double func_res(double x, double s){
	double result = pow((x - s), 2) - pow(e, (-1 * x));
	
	return result;
}
double findx(const double a=-1.5, const double b=2, const double s=0.7, const int iter=5, const int randint=0);
void line();
int randint();

int main(){
	double a = -1.5, b = 2, s = 0.7, sn = 1.6, ds = 0.3;


	cout<<c1<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c2;
	cout<<c<<c<<c<<c<<c<<c<<c3<<endl;
	cout << c4 << "    x    " << c4 << "     f(x)     " << c4 << " iter " << c4 << endl;

	while(s <= sn){
		line();
		double x = findx(a, b, s, iter, randint());
		cout << c4 << setw(9) << setprecision(4);
		cout.setf(ios::dec);
		if(x != 0) cout << x;
		else cout << " ~ ";
		cout << c4 << setw(14);
		cout.setf(ios::scientific);
		if(x == 0) cout << "-";
		else cout << func_res(x, s);
		cout.unsetf(ios::scientific);
		cout.setf(ios::dec);
		cout << c4 << setw(6) << iter << c4 << endl;
		s += ds;
		iter = 0;
	}
	cout<<c8<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c9;
	cout<<c<<c<<c<<c<<c<<c<<c10<<endl;	


	return 0;
}

double findx(const double a, const double b, const double s, const int k_iter, const int randint){
	double inf = a, sup = b;
	int iter = k_iter;
	if((func_res(sup, s) > 0 && func_res(inf, s) < 0) || (func_res(sup, s) < 0 && func_res(inf, s) > 0)){
		return 0;
	}
	while(fabs(sup - inf) > eps){
		inf = sup - (sup - inf) * func_res(sup, s) / (func_res(sup, s) - func_res(inf, s));
		sup = inf - (inf - sup) * func_res(inf, s) / (func_res(inf, s) - func_res(sup, s));
		iter += 1;
	}
	return sup;
}

void line(){
	cout<<c5<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c6;
	cout<<c<<c<<c<<c<<c<<c<<c7<<endl;	
}

int randint(){
	srand(time(0));
	return (-RAND_MAX/2 + rand()%RAND_MAX);
}