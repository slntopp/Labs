#include <iostream>

using namespace std;

#include "bank.h"

int main(){

    Bank test("банк", "я", 5);

    cout << test;

    Bank test1("банк1", "я", 5);

    test1 += 120;

    cout << test1;

    if(test1 > test) cout << "Test1 > test" << endl;
    if(test1 < test) cout << "Test1 < test" << endl;

    return 0;
}