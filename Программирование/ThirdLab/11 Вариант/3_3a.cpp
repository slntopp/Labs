#include <iostream>
#include "secfile.cpp"
#include "integr.h"

using namespace std;

int main(){
	double result;

	cout << "a=" << a << ", b=" << b << ", s=" << s << ", t=" << t << "." << endl;
	result = Integr(a, b, s, t);
	cout << "Результат вычисления определенного интеграла методом трапеций:" << endl;
	cout << result << endl;
}