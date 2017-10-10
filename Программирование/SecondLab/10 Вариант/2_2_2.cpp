#include <iostream> //Импортирование библиотеки ввода-вывода
#include <math.h>

using namespace std; //Инициализация пространства имен библиотеки iostream

int main() { //Объявление и инициализация функции main()

	int n; //Объявление переменной n целочисленного типа
	cout << "Введите N(любое натуральное число): ";
//Вывод сообщения с просьбой ввести число N
	cin >> n; //Инициализация переменной n посредством ввода его значения с клавиатуры
// ИНИЦИАЛИЗАЦИЯ == ПРИСВАИВАНИЕ ЗНАЧЕНИЯ
	if (n <= 0) {
		cout << "Введенное число не соответсвует условию: N - натуральное число." << endl;
		main(); //Повторный вызов функции main, т.е. запуск программы с начала
		return 0; //Возвращение нуля для автоматического завершения программы, т.к
	//если этого не сделать, после завершения работы вызванной функции, основная функция
	//продолжит свое выполнение дальше, короче говоря, пиши объясню:)
	}
	for(int i = n; i >= 1; --i) { //По порядку:
/*Объявление переменной для подсчета итераций, так как запись чисел ведется от n и до 1,
она инициализируется со значением n;
Объявление переменной k, её смысл рассматривается далее
Указание условия входа и завершения цикла, а именно пересчет всех чисел от n до 1;
Указание шага цикла, т.е. как изменяется итератор(убывает с шагом 1(единица))*/
		bool forif = false;
		cout << "Curr i: ";
		do{
			int k = 0;
			int next = i / int(pow(10, k+1)) % 10, now = i / int(pow(10, k)) % 10;
			if (i / int(pow(10, k+2)) % 10 == next) break;
			else if(next - now == 1) forif = true;
			else break;
			cout << now;
			k++;
		}while(1);
		if(forif) cout << i << endl;
	}
	cout << endl;
	return 0;
}