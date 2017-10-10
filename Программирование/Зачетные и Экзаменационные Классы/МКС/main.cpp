#include <iostream>
using namespace std;
#include "iss.h"

int main(){
    ISS obj(3, 4800, 2);
    Astronaut you("Ty Pidor Lol", 1, "CH");
    obj + you;
    cout << obj << endl;
    return 0;
}