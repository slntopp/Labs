#include <iostream>

using namespace std;

bool Prime(int a){
   int i;
   if (a == 2)
      return 1;
   if (a == 0 || a == 1 || a % 2 == 0)
      return 0;
   for(i = 3; i*i <= a && a % i; i += 2)
      ;
   return i*i > a;
}

int main(){
    int n;
    cout << "Type n(array lenth) here: ";
    cin >> n;
    if(n < 2 || n % 2){
        cout << "n should be even and greater than 1." << endl;
        main();
        return 1;
    }

    int *m_arr = new int[n];
    for(int i = 0; i < n; ++i){
        cout << "Type next array member: ";
        int someint = 0;
        cin >> someint;
        m_arr[i] = someint;
    }
    cout << "Getting prime pairs indexes..." << endl;
    for(int j = 0; j < (n / 2); j++){
        if(Prime(m_arr[j] + m_arr[n - (j + 1)])){
            cout << "\t Next prime pair is: " << m_arr[j] << " and " << m_arr[n - j - 1] << endl;
            cout << "\t\t ------- Indexes are: " << j << " and " << n - j - 1 << endl;
        }
    }
    cout << "________________________________________________" << endl;
    return 0;
}