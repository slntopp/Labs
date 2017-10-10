#include <iostream>
#include "vector.h"
#include <cmath>

using namespace std;

double MaxDevi(const Vector &obj);

int main(){

   double *num = new double[16];
   for(int i = 0; i < 16; ++i) num[i] = i;
   Vector obj(16, num);
   Vector obj1(obj);

   cout << "Среднее значение первого вектора: " << obj.GetMiddle() << endl;
   cout << "Максимальное отклонение от среднего значения в векторе 2: " << MaxDevi(obj1) << endl;
   cout << "Вектор 3: " << obj << endl;

   Vector *arr = new Vector[8];
   arr[0] = obj;

   cout << arr[0][3] << endl;

   return 0;
}

double MaxDevi(const Vector &obj){
    double deviation = 0;
    for(int i = 0; i < obj.GetAmount(); ++i){
        if(abs(obj[i] - obj.GetMiddle()) > deviation) deviation = abs(obj[i] - obj.GetMiddle());
    }
    return deviation;
}