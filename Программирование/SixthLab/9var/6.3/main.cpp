#include <iostream>
#include <iomanip>

using namespace std;

bool check_type(double k){
    if(int(k) * 100000000 == k * 100000000){
        return true;
    } else return false;
}
template <class st>
int mkmatrix(int, st);
template <class st>
void put_matrix(int, st**);

int main(){
    int n;
    double in_k;
    cout << "¬ведите n и k через пробел: ";
    cin >> n >> in_k;

    if(check_type(in_k)){
        int k = in_k;
        mkmatrix(n,k);
    } else {
        double k = in_k;
        mkmatrix(n,k);
    }
    
    return 0;
}

template <class st>
int mkmatrix(int n, st k){
    st** matrix = new st*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new st[n];
        for(int j = 0; j < n; ++j){
            matrix[i][j] = (i + 1)/k;
            if(j >= n - i) matrix[i][j] = 0;
        }
    }
    put_matrix(n, matrix);
    return 0;
}

template <class st>
void put_matrix(int n, st** matrix){
    for(int i = 0; i < n; ++i){
        cout << "|";
        for(int j = 0; j < n; ++j) cout << setw(9) << matrix[i][j];
        cout << setw(9) << "|" << endl;
    }
}