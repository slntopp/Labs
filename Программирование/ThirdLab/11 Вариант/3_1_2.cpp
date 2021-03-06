#include <iostream> //Библиотека для ввода-вывода
#include <iomanip> //Библиотека для управления(манипулирования) вводом-выводом
#include <math.h> //Библиотека, содержащая необходимые для сверки результатов
//работы алгоритма с реальными функции

using namespace std; //Инициализация пространства имен библиотеки iostream

const char c[] =  "─",   c1[] =  "┌",   c2[] = "┬",   c3[] = "┐";
const char c4[] = "│",  c5[] = "├",   c6[] = "┼",   c7[] = "┤";
const char c8[] = "└",  c9[] = "┴",   c10[] = "┘";

double body(double, int); //Объявление функции body, возвращающей переменную типа double
//и принимающую две переменные типов double и int. Функция будет содержать в себе
//"тело" алгоритма
double powx(double, int); //Объявление функции powx, возвращающей переменную типа double
//и принимающую две переменные типов double и int. Функция будет возводить в целую степень
//число вещественного типа. Х в конце названия функции для избежания конфликтов с аналогичной
//функцией(pow) из библиотеки math.h
void line(); //Объявление функции line, не возвращающей ничего

int main() {
	double x = 0, xn = 4, dx = 0.4; //Объявление и инициализация переменных вещественного
//типа, соответсвенно: переменная для хранения значения текущего Х, по умолчанию имеет
//значение х0, переменная содержащая значение конечного Х, переменная для хранения
//значения дельта-Х
	int n; //Объявление целочисленной переменной n, требуемое из условия
	cout << "Введите N: "; //Вывод сообщения с просбой ввести значение n с клавиатуры
	cin >> n; //Инициализация переменной посредством ввода ее значения с клавиатуры

	if(n <= 0){ //Обработчик значения n
		cout << "N - натуральное по условиям задачи" << endl;
		main(); //Повторный вызов функции main()
		return 0; //Возврат нуля для завершения уже запущенной функции main
	}

	cout<<c1<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c3<<endl;
	cout<<c4<<" Прямое вычисление             "<<c4<<endl;
	cout<<c5<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c2<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c7<<endl;
	cout << c4 << "  x  " << c4 << "  +  " << c4 << "   *   " << c4 << " Результат " << c4 << endl;

	while(x <= xn){ //Объявление цикла с предусловием, цикл будет работать, пока
//текущее Х меньше либо равно Х-конечному
		line(); //Обращение(вызов) функции line для вывода линии
		cout << setw(1) << c4 << setw(5) << setprecision(2) << x;
	//Вывод в поле шириной 5 символов значения Х с округлением до второй цифры
		cout << setw(1) << c4 << setw(5) << setprecision(0) << (n - 1);
	//Вывод в поле шириной 5 символов количества сложений, в случае
	//с прямым вычислением оно меньше на один количества слагаемых
		cout << setw(1) << c4 << setw(7) << (n *  2);
	//Вывод в поле шириной 7 символов количества умножений, в случае
	//с прямым вычислением оно в два раза больше кол-ва слагаемых
		cout << setw(1) << c4 << setw(11) << setprecision(5) << body(x, n) << setw(1) << c4 << endl;
	//Вывод в поле шириной 11 символов значения результата с округлением до 5-ой цифры
		x += dx; //Увеличение Х на дельта-Х
	}
	cout<<c8<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c9<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c10<<endl;	
//Вывод нижней границы таблицы
	return 0; //Возврат функцией main() нуля для завершения программы
}

double powx(double x, int n){ //Инициализация функции powx
	double res = 1; //Объявление и иницализация вещественной переменной res
//для хранения результата возведения в степень.
	if(n == 0) return res; //В случае попытки возведения в нулевую степень, возврат
//единицы в качестве результата(значение переменной res по умолчанию задано 1)
	for(int i = 1; i <= n; ++i){ //Объявление цикла for
		res *= x; //Увеличение степени на 1
	}
	return res; //Возврат результата
}

double body(double x, int n){ //Инициализация функции body
	double result = 0; //Объявление и инициализация переменной result для хранения результата
	for(int i = 1; i <= n; ++i){ //Объявление цикла for 
		result += (powx(-1, i) * powx(x, i) * i); //Подсчет многочлена данного в условии
	}
	return result; //Возврат результата
}

void line(){ //Инициализация функции line
	cout<<c5<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c<<c6<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c7<<endl;
//Вывод разделительной линиии в таблицу
}