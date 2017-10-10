#include <iostream>
#include <math.h>
#include "sec.cpp"
#include "integr.h"


using namespace std;

int main(){
	double result;
	cout << "Вычислить интеграл:     " << endl;
	cout << "    b _                 " << endl;
	cout << "     / t * arctg(x^0.2) " << endl;
	cout << "    / ──────────────────" << endl;
	cout << " a_/   x^2 + s * sin(x) " << endl;
	cout << "При a=" << a << ", b=" << b << ", s=" << s << ", t=" << t << "." << endl;
	result = Integrate(a, b, s, t);
	cout << "Результат вычилсения определенного интеграла методом трапеций:" << endl;
	if(isnan(result)){
		cout << "Интеграл не имеет решения." << endl;
	} else {
		cout << result << endl;
	}
	return 0;
}