#include <iostream>

using namespace std;

template <typename sometype>
void maxxx(sometype a, sometype b, sometype c, sometype d){
	a = (a > b)*a + (a <= b)*b;
	b = (c > d)*c + (c <= d)*d;
	cout << "Результат: " << ((a > b) * a + (a <= b) * b) << endl;
}

int main(){
	double x1, y1, x2, y2;
	cout << "Введите х1, у1, х2, у2(через пробел): ";
	cin >> x1 >> y1 >> x2 >> y2;

	maxxx(x1 + y1, x1 * y1, x2 + y2, x2 * y2);

	return 0;
}