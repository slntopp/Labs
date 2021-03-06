#include <cstdlib>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

double body(int&, double&);
int fact(int);
void sign();
void exec_time();

int main() {
	atexit(sign);
	atexit(exec_time);
	int n;
	double summ = 0;
	cout << "Введите натуральное число n: ";
	cin >> n;

	body(n, summ);

	cout << "Результат: " << summ << endl;

	return 0;
}

double body(int& i, double& summ){
	if(i == 0) return summ;
	summ += (pow(-1, i) * pow(i, 2) * (i + 1) / fact(i));
	--i;
	body(i, summ);
	return summ;
}

int fact(int i){
	int res = 1;
	if(i == 0) return 1;
	for(i; i > 0; --i){
		res *= i;
	}
	return res;
}

void sign(){
	cout << "Written by @slnt_opp" << endl;
}

void exec_time(){
	long int ntime;
	time(&ntime);
	cout << "Executed at: "<< ctime(&ntime) << endl;
}