#include "matrix.h"
#include "6.2b.cpp"

using namespace matrix;

int main(){
    cout << "¬ведите пор€док матрицы: ";
    int n;
    cin >> n;
    if (n <= 1){
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    cout << "¬ведите значени€ матрицы:\n";
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
    }
    get_matrix(n, matrix);
    cout << "»дет обработка..." << endl;
    actions(n, matrix);
    delete[] matrix;
   
    return 0;
}