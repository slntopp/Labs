#include <iostream>

using namespace std;

int main() {
	double x, y = 1, summ = 0, fact = 2, e = 0.000001;
	int k = 1;
	cout << "x(0,1], x: ";
	cin >> x;
	if (x <= 0 || x > 1) {
		cout << "try again" << endl;
		main();
		return 0;
	}
	double pow = x*x;
	while(y*y > e*e){
		pow *= x;
		fact *= (k + 2);
		y = pow / (fact * (k + 1));
		if (k % 2) y *= (-1);
		summ += y;
	}
	cout << summ << endl;

	return 0;
}