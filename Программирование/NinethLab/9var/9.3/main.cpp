#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

float max_deviation(int len, vector <int>arr){
    float mid_val = 0;
    for(int i = 0; i < len; ++i) mid_val += arr[i];
    mid_val /= len;

    int max_deviation = 0;
    for(int i = 0; i < len; ++i) if(abs(arr[i] - mid_val) > max_deviation) max_deviation = abs(arr[i] - mid_val);

    cout << "Среднее значение: " << mid_val << endl;
    cout << "Максимальное отклонение: " << max_deviation << endl;
    return max_deviation;
}

ostream& operator<< (ostream& out, const vector<int> arr);

int main(){

    int n;
    cout << "Введите длину вектора: ";
    cin >> n;
    vector <int>main_arr(n);

    srand(time(0));
    for(int i = 0; i < n; ++i) main_arr[i] = -999 + rand()%2000;

    cout << "Массив: " << endl;
    cout << main_arr << endl;

    max_deviation(n, main_arr);

    return 0;
}

ostream& operator<< (ostream& out, const vector<int> arr){
    out << "[ ";
    for(int i = 0; i < arr.size(); ++i){ out << arr[i]; if(i + 1 != arr.size()) out << ","; out << " "; }
    out << "]";
    return out;
}