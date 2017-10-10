#include "matrix.h"
#include "6.2b.cpp"

using namespace matrix;

int main(){
    cout << "������� ������� �������: ";
    int n;
    cin >> n;
    if (n <= 1){
        cout << "ERR_Unknown_n" << endl;
        return main();
    }
    cout << "������� �������� �������:\n";
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
    }
    get_matrix(n, matrix);
    cout << "���� ���������..." << endl;
    actions(n, matrix);
    delete[] matrix;
   
    return 0;
}