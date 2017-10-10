#include <iostream>

using namespace std;

int main(){
    int order = 1;
    int x = 1;
    while(x / int(pow(10, order)) != 0) ++order;

    cout << order << endl;

    return 0;
}