#include <iostream>
#include <сstdlib>
#include <сstring>
#include <сlocale>
#include <сmath>

using namespace std;

int main(){

    //setlocale(LC_ALL, "rus");
    int n = 0;
    while(n <= 0) cout << "����� ���������� ��������� � �������: ", cin >> n;
    int *main_arr = new int[1], result = 0;
    for(int i = 0; i < n; ++i){
        cout << "����� �������� �������� ������� �" << i << ": ";
        cin >> *(main_arr + i);
    }
    for(int i = 0; i < n; ++i){
        if(main_arr[i] > 0 && !(main_arr[i] % 3) && pow(int(sqrt(i)), 2) == i) result += main_arr[i];
    }

    cout << "���������: " << result << endl;
    delete []main_arr;

    return 0;

}