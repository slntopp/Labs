#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

	int n;
	cout << "Введите n: ";
	cin >> n;

	bool choice;
	cout << "Выберите способ ввода: 0 - случайные числа, 1 - ввод с клавиатуры\n";
	cin >> choice;

	double *exarray = new double[n];
	int pos_mem = -1;

	srand(time(0));

	if(choice) {
		for(int i = 0; i < n; ++i){
			cout << "Введите элемент N." << i << ":";
			cin >> exarray[i];
			if(exarray[i] > 0) pos_mem = i;
		}
	} else if (!choice) {
		cout << "[ ";
		for(int i = 0; i < n; ++i){
			exarray[i] = -1*rand()%200 + 100;
			if(exarray[i] > 0) pos_mem = i;
			cout << " " << exarray[i];
		}
		cout << " ]" << endl;
	} else {
		cout << "Повторите попытку ввода." << endl;
		main();
		return 0;
	}

	if (pos_mem == -1){
		cout << "Входные данные не соответствуют условиям задачи." << endl;
		return 0;
	}

	double result = 0;
	for(int i = 0; i < pos_mem; ++i){
		result += exarray[i];
	}
	if(exarray[0] > 0 && pos_mem == 0){
		cout << "Входные данные не соответствуют условиям задачи." << endl;
		return 0;
	}
	cout << "Результат: " << result << endl;

	return 0;
}
