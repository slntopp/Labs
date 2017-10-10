#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const char c = char(196),   c1 = char(218),   c2 = char(194), c3 = char(191);
const char c4 = char(179),  c5 = char(195),   c6 = char(197), c7 = char(180);
const char c8 = char(192),  c9 = char(217),   c10 = char(193);
//Обхявление и инициализация символьных переменных для создания таблицы

/* Если кодировкой не вышел, то удали предыдущие пять строк и откомментируй следующие три
const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";
*/// Если таки вышел, то удали от палева подальше

int main() {

	double a = 2.8, x = 1, dx = 0.05, xn = 2, w, x0 = x;
//A - коэффициент данный по условию, х - переменная для хранения текущего значения
//Х, dx переменная хранящая значение "дельта-х" данное в условии, xn - конечное Х,
//w - переменная для хранения результата, x0 - содержит начальное значение Х.
//________________________________________________________________________________

	cout <<c1<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c3<<endl;
//Вывод верхней границы таблицы
	cout << setiosflags(ios::fixed) << setw(1) << c4 << setw(3) << "x" << setw(6) << c4;
//По очереди: Инициализация библиотеки для фиксирования символов <<
//Установка ширины поля в которое будут умещены выводимые данные.
	cout << setw(6) << "w" << setw(9) << c4 << endl;
//Последние две строки - вывод шапки таблицы
	
//________________________________________________________________________________

	for(int i = 0; i <= 1 + ((xn - x0) / dx); ++i) {
//В условии цикла автоматически просчитываем нужное количество итераций
//Плюс один так как подсчет итераций ведется с нуля, а нам требуется включить верхнюю границу
//________________________________________________________________________________

		cout <<c5<<c<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c7<<endl;
	//Вывод разделительной линии между строками

//________________________________________________________________________________
		if(x < 1.2) { //По условию, если Х меньше 1.2, то выполняется следующая формула
			w = a * x * x - 0.3 * x + 4;
		} else if(x == 1.2) { //По условию, если Х равно 1.2, то выполняется следующая формула
			w = a / x + sqrt(x * x + 1);
		} else { //По условию, если Х больше 1.2, а так как все остальные варианты
	//учтены, то выполняется следующая формула
			w = (a - 0.3 * x) / sqrt(x * x + 1);
		}

		cout << setprecision(2) << setw(1) << c4 << setw(5) << x << setw(4) << c4;
	//Вывод в таблицу значения текущего Х
	//Установка количества выводимых цифр после запятой - в данном случае две цифры
		cout << setprecision(6) << setw(11) << w << setw(4) << c4 << endl;
	//Вывод в таблицу значения w
		x += dx; //Увеличение текущего Х на значение "дельта-х".
	}

	cout <<c8<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c10<<endl;
//Вывод завершающей линии таблицы

	return 0; //Завершение функции main() -- завершение программы
}