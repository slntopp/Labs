#include "smatrix.h"

using namespace sums;

int actions(int n, double** matrix){
    double some_var = sum_above_diag(n, matrix);
    cout << "����� �� ����� �1: " << sum_above_main_d(n, matrix) << endl;
    cout << "����� �� ����� �2: " << some_var << endl;
    cout << "����� �� ����� �3: " << sum_left_right(n, matrix) << endl;
    cout << "����� �� ����� �4: " << sum_all_within_high_triangle(n, matrix) - some_var << endl;

    return 0;
}