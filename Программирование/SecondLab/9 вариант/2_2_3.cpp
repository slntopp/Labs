#include <iostream>

using namespace std;

int main() {

	int n, din, preres = 0; /*n - длина последовательности, din - ввод C/S, preres
промежуточный результат*/
	float result = 1; //Конечный результат
	cout << "Введите N: ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "Введите число C" << i << ": ";
		cin >> din;
		preres += din;
		result *= preres;
	}

	preres = 0;

	for (int j = 0; j < n; ++j) {
		cout << "Введите число S" << j << ": ";
		cin >> din;
		preres += din;
		if (preres == 0) {
			cout << "Выражение не имеет смысла." << endl;
			return 0;
		}
		result = result / preres;
	}

	cout << "Конечный результат: " << result << endl;
	return 0;
}