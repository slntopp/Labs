#include <iostream>
#include <iomanip>
using namespace std;

#include "truncatedcone.h"

int main(){

    Materials mat_arr[4] = {IRON, TITAN, CUPRUM, STEEL };

    Body *array[4];
    for(int i = 0; i < 4; ++i) array[i] = new TruncatedCone(mat_arr[i], 0.1, 0.05, 0.025);
    cout << "S-���������: " << array[0] -> BaseSquare() * 10000 << " cm^2" << endl;
    cout << "S-�������: " << array[0] -> SideSquare() * 10000 << " cm^2" << endl;
    cout << "S-������: " << array[0] -> FullSquare() * 10000 << " cm^2" << endl;

    cout << "�����: " << array[0] -> Volume() * 100000 << " ml" << endl;

    for(int i = 0; i < 4; ++i){
        cout << "��� ���������� ������ " << Material(mat_arr[i]) << ": " << setprecision(3) << array[i] -> Weight() << " kg" << endl;
    }

    double buff = array[0] -> Weight();
    int res = 0;
    for(int i = 1; i < 4; ++i){
        if(buff > array[i] -> Weight()) buff = array[i] -> Weight(), res = i;
    }

    cout << "��������� ����� " << Material(mat_arr[res]) << " - ����� ������ �� ����!" << endl;

    return 0;
}