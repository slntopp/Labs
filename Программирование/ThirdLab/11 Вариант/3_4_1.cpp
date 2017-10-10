#include <iostream>
#include <math.h>

using namespace std;

int fact(int);
double iter_body(int); //Функция для подсчета методом итераций
void rec_body(int, int, double*); //Функция для подсчета методом рекурсии

int main(){
	int n;
	cout << "Введите натуральное n: ";
	cin >> n;
	if(n <= 0){
		main();
		return 0;
	} 
	double result_iter = 0, result_rec = 0;
	for(int i = 1; i <= n; ++i){
		result_iter += iter_body(i);
	}
	rec_body(1, n, &result_rec);
	cout << "Результат:\nМетодом итераций - " << result_iter << "\tМетодом рекурсии - " << result_rec << endl;

	return 0;
}

int fact(int i){
	int res = 1;
	for (int j = 1; j < i; ++j){
		res *= j;
	}
	return res;
}

double iter_body(int i) {
	return (pow(-1, i) / fact(i));
}

void rec_body(int i, int n, double* result){
	*result += (pow(-1, i) / fact(i));
	if (i != n) rec_body(++i, n, result);
}