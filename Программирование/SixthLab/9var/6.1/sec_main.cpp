#include <iostream>

using namespace std;

int main(){
    int n, m;
    cout << "������� n � m: ";
    cin >> n >> m;

    bool ediv = true;
    cout << "����� �������: 1";
    for(int i = 2, k = 0; i < m; ++i){
        if(n % i == 0 && m % i == 0){
            cout << ", " << i;
        }
    }

    return 0;
}