#include <cmath>

namespace sums {
    double sum_all(int n, double** matrix){ //Подсчет суммы всех элементов
        double result = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) result += matrix[i][j];
        return result;
    }
    double sum_below_sec_d(int n, double** matrix){ //Подсчет суммы элементов под побочной диагональю
        double result = 0;
        for(int i = 0; i < n; ++i){
            for(int j = n - 1; j >= n - i - 1; --j) result += matrix[i][j]; //Цикл проходит по строкам с конца, до элемента индексы
//которого соответсвуют уравнению i = n - j - 1
        }
        return result;
    }
    double sum_right(int n, double** matrix){ //Подсчет суммы правого треугольника
        double result = 0;
        bool not_center;
        if(n % 2 != 0) not_center = true;
        for(int i = 0; i < n; ++i){
            for(int j = n - 1; j >= n - i - 1; --j){ //Хз что тут в заголовке, я просто копипиздил из своей лабы, там другое условие было
                if(i < n / 2){ //Короче все элементы до половины матрицы лежат над главной диагональю и под побочной, а ниже наоборот
                    result += matrix[i][j];
                } else if (j >= i){ //Это и проверяем
                    result += matrix[i][j];
                }
            }
        }
        return result;
    }
    double sum_left_right(int n, double** matrix){ //Сумма элементов в двух треугольниках
        double result = 0;
        bool not_center;
        if(n % 2 != 0) not_center = true;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){ //Тоже самое, что и в предыдущей функции, только адаптировано еще и для левого треугольника
                if((j + 1 == n - j) && (i + 1 == n - 1) && not_center) continue;
                if(i < n / 2){
                    result += matrix[i][j];
                }
                else if (j <= n - i - 1){
                    result += matrix[i][j];
                }
            }
            for(int j = n - 1; j >= n - i - 1; --j){ //В два цикла, потому что мне было пиздец лень думать и я сделал шо бы было
                if(i < n / 2){
                    result += matrix[i][j];
                } else if (j >= i){
                    result += matrix[i][j];
                }
            }
        }
        return result;
        }
    double sum_all_within_down_triangle(int n, double** matrix){ //Тут считаем элементы нижнего треугольника
        double result = 0;
        for(int i = n / 2; i < n; ++i){ 
            for(int j = 0; j < n; ++j){
                if(j >= n - i - 1 && j <= i) result += matrix[i][j]; //Элементы должны удовлетворять условию:
//элемент находится между побочной и главной диагональю. Так как цикл начинает проходить по элементам сразу с середины исключаем попадание
//в конечный результат лишних элементов
            }
        }
        return result;
    }
}