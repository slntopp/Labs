#include <iostream>

using namespace std;

int main() {
	double x = 0.0;
	int a, b, c;
	cout << "Введите x:" << ends;
	cin >> x;
	
	a = (int)x / 10;
	b = (int)x % 10;
	c = ((int)(x * 10)) % 10 + ((int)(x * 100)) % 10 + ((int)(x * 1000)) % 10;
	x = (a ^ b) & ~(a | c);
	
	cout << a << " " << b << " " << c << " " << x << ends;
	return 0;
}
